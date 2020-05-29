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

void Node::setAdj(Node* newAdj) { //Add to adjacency list
  adj.push_back(newAdj);
}

vector<Node*> Node::getAdj() {
  return adj;
}

void Node::removeAdj(char* remove) { //Enter the name, and it will search and delete it
  vector<Node*> :: iterator ite1 = adj.begin();
  while (ite1 != adj.end()) {
    if (strcmp((*ite1)->getName(), remove) == 0) {
      adj.erase(ite1);
    }
    else {
      ite1++;
    }
  }
}

vector<int> Node::getWeight() {
  return weights;
}

void Node::setWeight(int newWeight) {
  weights.push_back(newWeight);
}

void Node::replaceWeight(vector<int> newW) { //Used if new vector is made
  weights = newW;
}

void Node::replaceAdj(vector<Node*> newA) {
  adj = newA;
}

