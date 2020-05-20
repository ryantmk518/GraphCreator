#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
 public:
  Node(char);
  ~Node();
  void setName(char);
  void setAdj(Node*);
  char getName();
  Node* getAdj();
 private:
  char name;
  Node* adj;
};

#endif
