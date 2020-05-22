#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

//Node Header: Intializes functions and variables

class Node{
 public:
  Node(char* );
  ~Node();
  char* getName();
  void setName(char*);
 private:
  char* name;
};

#endif
