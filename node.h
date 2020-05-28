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
  void setAdj(char*);
  vector<char*> getAdj();
 private:
  char* name;
  vector<char*> adj;
};

#endif
