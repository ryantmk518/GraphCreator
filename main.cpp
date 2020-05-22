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
  int vertices = 0;
  while (quit == false) {
    cout << "Enter Add Vertex, Add Edge, Remove Vertex, Remove Edge, Print, Quit" << endl;
    char* in = new char[999];
    cin.getline(in, 999);
    if (strcmp(in, "Add Vertex") == 0) {
      cout << "Enter vertex name (Please only one character long)" << endl;
      char* name = new char[99];
      cin.getline(name, 99);
      Node* node = new Node(name); //Creating vertex and adding to the vector
      vertex.push_back(node);
      vertices++;
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
      vector<Node*> :: iterator i = vertex.begin();
      bool found = false;
      while (i != vertex.end()) {
        if (strcmp((*i) -> getName(), remove) == 0) {
          cout << "Found erase" << endl;
          found = true;
          vertex.erase(i);
          vertices--;
        }
        else {
          i++;
        }
      }
      if (found == false) {
        cout << "Vertex doesn't exist" << endl;
      }
      vector<Edge*> :: iterator ite = edge.begin();
      while (ite != edge.end()) {
        if (strcmp((*ite) -> getStart() -> getName(), remove) == 0 || strcmp((*ite) -> getEnd() -> getName(), remove) == 0) {
          edge.erase(ite);
        }
        else {
          i++;
        }
      }
    }
    else if (strcmp(in, "Remove Edge") == 0) {
      cout << "Enter name of edge to remove" << endl;
      char* redge = new char[99];
      cin.getline(redge, 99);
      vector<Edge*> :: iterator a = edge.begin();
      while (a != edge.end()) {
        if (strcmp((*a) -> getStart() -> getName(), redge) == 0 || strcmp((*a) -> getEnd() -> getName(), redge) == 0) {
          edge.erase(a);
        }
        else {
          a++;
        }
      }
    }
    else if (strcmp(in, "Print") == 0) { //My brain hurty why did i do this its not even necessary
      cout << "Printing" << endl;
      cout << "    ";
      vector<Node*> :: iterator iter;
      for (iter = vertex.begin(); iter != vertex.end(); iter++) {
        cout << (*iter) -> getName() << "    ";
      }
      cout << '\n'<< endl;


      for (int b = 0; b < vertices; b++) { //b is row number
        int y = 0;
        char* column = new char[99];
        //Gets the column letter
        vector<Node*> :: iterator x;
        for (x = vertex.begin(); x != vertex.end(); x++) {
          if (b == y) {
            cout << (*x) -> getName() << "   ";
            column = (*x) -> getName();
            y++;
          }
          else {
            y++;
          }
        }
        for (int v = 0; v < vertices; v++) { //Column number
          int c = 0;
          vector<Node*> :: iterator iterate;
          for (iterate = vertex.begin(); iterate != vertex.end(); iterate++) {
            if (c == v) {
              //Check if has edge
              bool hasEdge = false;
              vector<Edge*> :: iterator iterating;
              for (iterating = edge.begin(); iterating != edge.end(); iterating++) {
                if (strcmp((*iterating) -> getStart()->getName(), (*iterate) -> getName()) == 0 && strcmp((*iterating) -> getEnd()->getName(), column) == 0) {
                  hasEdge = true;
                }
              }
              if (hasEdge == true) {
                cout << (*iterating) -> getWeight() << "   ";
              }
              c++;
            }
            else{
              c++;
            }
          }
        }
        cout << '\n' << endl;
      }
      cout << endl;
    }
    else if (strcmp(in, "Quit") == 0) {
      quit = true;
    }
  }
}
