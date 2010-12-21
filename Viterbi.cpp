#include <cy_svector.hpp>
#include <svector.hpp>
#include "Forest.h"
#include <fstream>
#include <iostream>
#include "ForestAlgorithms.cpp" 
#include "EdgeCache.h"


int main(int argc, char ** argv) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  
  svector<int, double> * weight;

  {
    fstream input(argv[2], ios::in );
    char buf[1000];
    input.getline(buf, 100000);
    string s (buf);
    weight = svector_from_str<int, double>(s);
  }

  
  Hypergraph hgraph;
  
  {
    stringstream fname;
    fname <<argv[1] ;
    //cout << fname.str() << endl;
    fstream input(fname.str().c_str(), ios::in | ios::binary);
    if (!hgraph.ParseFromIstream(&input)) {
      assert (false);
    } 
  }
    
  Forest f (hgraph);
  NodeCache  score_memo_table(f.num_nodes()); 
  NodeBackCache  back_memo_table(f.num_nodes());
  EdgeCache * edge_weights = cache_edge_weights(f, *weight);

  double score = best_path(f, *edge_weights, score_memo_table, back_memo_table);
  
  vector<int> best_nodes = construct_best_node_order(f, back_memo_table);
  
  for (int i =0; i < best_nodes.size(); i++) {
    const ForestNode & node = f.get_node(best_nodes[i]);
    cout << node._label << endl;
  }


  cout << "SCore is : " << -score << endl;
   
  return 0;
}
