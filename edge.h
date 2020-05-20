#ifndef EDGE_H
#define EDGE_H
#include <iostream>

using namespace std;

class Edge{
 public:
  Edge(int, Node*, Node*);
  ~Edge();
  int getWeight();
  void setWeight(int);
  void setStart(Node*);
  void setEnd(Node*);
  Node* getStart();
  Node* getEnd();
 private:
  Node* start;
  Node* end;
  int weight;
};

#endif
