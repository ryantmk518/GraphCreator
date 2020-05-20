#include <iostream>
#include "node.h"

using namespace std;

//Node class

Node::Node(char newName) {
  name = newName;
  adj = NULL;
}

Node::~Node() {
  adj = NULL;
}

void Node::setName(char newName) {
  name = newName;
}

void Node::setAdj(Node* newNode) {
  adj = newNode;
}

Node* Node::getAdj() {
  return adj;
}

char Node::getName() {
  return name;
}
