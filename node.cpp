#include <iostream>
#include "node.h"
#include <vector>
#include <cstring>

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

void Node::removeAdj(char* remove) {
  vector<char*> :: iterator ite1 = adj.begin();
  while (ite1 != adj.end()) {
    if (strcmp((*ite1), remove) == 0) {
      adj.erase(ite1);
    }
    else {
      ite1++;
    }
  }
}

