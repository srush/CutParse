




void EisnerToHypergraph::convert(Forest & _forest) {
  for (int i =0; i < length(); i++) {
    for (int d =0; d < num_dir; d++) {
      Node n(Span(i,i), d, TRI);
      _node_to_id[n] = get_id();
    }
  }

  for (int spansize = 2 ; spansize < length(); spansize++) {
    for (int i =0; i < length(); i++) {
      k = i + spansize;
      if (k > length()) continue;

      for (int j =i; j < k ; j ++) {
        // 4 cases 
     
        // triangle rule
        // right triangle + left triangle 
        {
          // RIGHT TRAP

          Node n(Span(i,k),  RIGHT, TRAP);
          
          Node lchild(Span(i,j), RIGHT, TRI);
          Node rchild(Span(j,k), LEFT, TRI);

          Hyperedge edge;
          
          edge.head = _node_to_id(n);
          edge.tail_node_ids.push_back( _node_to_id(lchild));
          edge.tail_node_ids.push_back( _node_to_id(rchild));
          edge.weight = get_weight(i, k);
          

          hyperedges.push_back(edge);
        
          
        }
   

        {
          // LEFT TRAP

          Node n(Span(i,k),  LEFT, TRAP);
          
          Node lchild(Span(i,j), RIGHT, TRI);
          Node rchild(Span(j,k), LEFT, TRI);

          Hyperedge edge();
          
          edge.head = _node_to_id(n);
          edge.tail_node_ids.push_back( _node_to_id(lchild));
          edge.tail_node_ids.push_back( _node_to_id(rchild));
          edge.weight = get_weight(k, i);
        }


        {
          // RIGHT TRI

          Node n(Span(i,k), RIGHT, TRI);
          
          Node lchild(Span(i,j), RIGHT, TRAP);
          Node rchild(Span(j,k), RIGHT, TRI);

          Hyperedge edge();
          
          edge.head = _node_to_id(n);
          edge.tail_node_ids.push_back( _node_to_id(lchild));
          edge.tail_node_ids.push_back( _node_to_id(rchild));
        }

        {
          // LEFT TRI

          Node n(Span(i,k), LEFT, TRI);
          
          Node lchild(Span(i,j), LEFT, TRI);
          Node rchild(Span(j,k), LEFT, TRAP);

          Hyperedge edge();
          
          edge.head = _node_to_id(n);
          edge.tail_node_ids.push_back( _node_to_id(lchild));
          edge.tail_node_ids.push_back( _node_to_id(rchild));
        }      
      }    
    }
  }
}
