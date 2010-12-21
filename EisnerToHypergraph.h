
typedef vector< vector <double> > WeightVec;
struct Node {
  Span node_span; 
  Direction d;
  Shape s;
  
Node(Span ns, Direction d_in, Shape s_in) : 
  node_span(ns), d(d_in), s(s_in){}

  bool operator<(const Node & other ) const {
    if (d != other.d ) {
      return d < other.d;
    } else if (s != other.s) {
      return s != other.s;
    } else if (!(node_span == other.node_span)) {
      return node_span < other.node_span;
    }
    return false;
  } 

};


struct Hyperedge{
  vector <int> tail_node_ids;
  int head;
  double weight;
  Hyperedge() {
    weight =0.0;
  }
  
};


enum Direction {LEFT, RIGHT};
enum Shape {TRI, TRAP};

struct Span {
  int start;
  int end;
  int size;
  Span(int s, int e) :start(s), end(e){
    size = e -s; 
  } 

  void operator==(const Span & other ) const {
    return other.start == start && other.end == end;
  }

  void operator<(const Span & other ) const {
    if (other.start != start) {
      return start < other.start;
    } else if ( other.end != end) {
      return end < other.end;
    } 
    return false;
  }


};


class EisnerToHypergraph {


 public:
 EisnerToHypergraph(const vector <int> & sent, const WeightVec & weights ) : _sent(sent), _weights(weights)   {
    _id =0; 
  }

  void convert( Forest & _forest );

 private:
  inline int length() {
    return _sent.length();
  }

  inline int get_id(){
    _id++;
    return _id;
  }
  
  inline double get_weight(int h, int m) {
    return _weights[h][m];
  }

  const vector <int> & _sent;
  const WeightVec &  _weights;  
  
  int _id;
  map < Node, int > _node_to_id;
  vector < Hyperedge > hyperedges;
}
