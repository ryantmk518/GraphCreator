#include <iostream>
#include "edge.h"

using namespace std;

//Edge class

Edge::Edge(int newWeight, Node* newStart, Node* newEnd) {
  weight = newWeight;
  start = newStart;
  end = newEnd;
}

Edge::~Edge() {
  weight = 0;
}

void Edge::setWeight(int newWeight) {
  weight = newWeight;
}

int Edge::getWeight() {
  return weight;
}

void Edge::setStart(Node* newStart) {
  start = newStart;
}

void Edge::setEnd(Node* newEnd) {
  start = newEnd;
}

Node* Edge::getStart() {
  return start;
}

Node* Edge::getEnd() {
  return end;
}
