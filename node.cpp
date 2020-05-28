#include <iostream>
#include "node.h"
#include <vector>

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

void Node::setAdj(char* newAdj) {
  adj.push_back(newAdj);
}

vector<char*> Node::getAdj() {
  return adj;
}

