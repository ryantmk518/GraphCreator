#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>

using namespace std;

//Node Header: Intializes functions and variables

class Node{
 public:
  Node(char* );
  ~Node();
  char* getName();
  void setName(char*);
  void setAdj(Node*);
  vector<Node*> getAdj();
 private:
  char* name;
  vector<Node*> adj;
};

#endif
