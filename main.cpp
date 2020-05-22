#include <iostream>
#include "node.h"
#include "edge.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include "stdlib.h"
#include "assert.h"

//Graph Creator. Ryan Thammakhoune

using namespace std;

void addEdge(Node* start, Node* end);

int main() {
  vector<Node*> vertex;
  vector<Edge*> edge;
  bool quit = false;
  while (quit == false) {
    cout << "Enter Add Vertex, Add Edge, Remove Vertex, Remove Edge, Print, Quit" << endl;
    char* in = new char[999];
    cin.getline(in, 999);
    if (strcmp(in, "Add Vertex") == 0) {
      cout << "Enter vertex name" << endl;
      char* name = new char[99];
      cin.getline(name, 99);
      Node* node = new Node(name); //Creating vertex and adding to the vector
      vertex.push_back(node);
    }
    else if (strcmp(in, "Add Edge") == 0) {
      cout << "Enter start node" << endl;
      char* start = new char[99];
      cin.getline(start, 99);
      cout << "Enter end node" << endl;
      char* end = new char[99];
      cin.getline(end, 99);
      bool valid1 = false;
      bool valid2 = false;
      Node* first = new Node(NULL);
      Node* last = new Node(NULL);
      vector<Node*> :: iterator it;
      for (it = vertex.begin(); it != vertex.end(); it++) {
        if (strcmp((*it) ->  getName(), start) == 0) {
          cout << "Found start" << endl;
          valid1 = true;
          first = *(it);
        }
        else if (strcmp((*it) -> getName(), end) == 0) {
          cout << "Found end" << endl;
          valid2 = true;
          last = *(it);
        }
      }
      if (valid1 == true && valid2 == true) {
        cout << "Enter weight of edge" << endl;
        char* weight = new char[99];
        cin.getline(weight, 99);
        int w = atoi (weight);
        Edge* newEdge = new Edge(w, first, last);
        edge.push_back(newEdge);
      }
      else {
        cout << "One of the nodes entered does not exist" << endl;
      }
    }
    else if (strcmp(in, "Remove Vertex") == 0) {
      cout << "Enter name of vertex to remove" << endl;
      char* remove = new char[99];
      cin.getline(remove, 99);
      vector<Node*> :: iterator i;
      bool found = false;
      for (i = vertex.begin(); i != vertex.end(); i++) {
        if (strcmp((*i) -> getName(), remove) == 0) {
          bool found = true;
          vertex.erase(i);
        }
      }
      vector<Edge*> :: iterator ite;
      for (ite = edge.begin(); ite != edge.end(); ite++) {
        
      }
    }
    else if (strcmp(in, "Remove Edge") == 0) {
      cout << "Removing edge" << endl;
    }
    else if (strcmp(in, "Print") == 0) {
      cout << "Printing" << endl;
    }
    else if (strcmp(in, "Quit") == 0) {
      quit = true;
    }
  }
}
