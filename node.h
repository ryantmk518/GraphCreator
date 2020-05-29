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
  void removeAdj(char*);
  void setWeight(int);
  vector<int> getWeight();
  void replaceAdj(vector<Node*>);
  void replaceWeight(vector<int>);
 private:
  vector<int> weights;
  char* name;
  vector<Node*> adj;
};

#endif
