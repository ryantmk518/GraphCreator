#include <iostream>
#include "node.h"

using namespace std;

//Node class

Node::Node(char* newName) {
  name = newName;
}

Node::~Node() {
  
}

void Node::setName(char* newName) {
  name = newName;
}

char* Node::getName() {
  return name;
}
