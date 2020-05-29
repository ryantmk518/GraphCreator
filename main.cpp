#include <iostream>
#include "node.h"
#include "edge.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include "stdlib.h"
#include "assert.h"
#include <climits>



//Graph Creator. Ryan Thammakhoune

using namespace std;

bool checkConnect(Node* begin, Node* stop);




int main() {
  vector<Node*> vertex;
  vector<Edge*> edge;
  bool quit = false;
  int vertices = 0;
  while (quit == false) {
    cout << "Enter Add Vertex, Add Edge, Remove Vertex, Remove Edge, Shortest Path, Print, Quit" << endl;
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
          valid1 = true;
          first = *(it);
        }
        else if (strcmp((*it) -> getName(), end) == 0) {
          valid2 = true;
          last = *(it);
        }
      }
      first->setAdj(last);
      if (valid1 == true && valid2 == true) {
        cout << "Enter weight of edge" << endl;
        char* weight = new char[99];
        cin.getline(weight, 99);
        int w = atoi (weight);
        Edge* newEdge = new Edge(w, first, last);
        edge.push_back(newEdge);
        first->setWeight(w);
      }
      else {
        cout << "One of the nodes entered does not exist" << endl;
      }
    }
    else if (strcmp(in, "Remove Vertex") == 0) {
      Node* temp = new Node(NULL);
      cout << "Enter name of vertex to remove" << endl;
      char* remove = new char[99];
      cin.getline(remove, 99);
      vector<Node*> :: iterator i = vertex.begin();
      bool found = false;
      while (i != vertex.end()) {
        if (strcmp((*i) -> getName(), remove) == 0) {
          temp = (*i);
          found = true;
          vertex.erase(i);
          vertices--;
        }
        else {
          i++;
        }
      }
      vector<Node*> :: iterator ite2;
      for (ite2=vertex.begin();ite2 != vertex.end(); ite2++) {
        vector<Node*> adjEdge = (*ite2)->getAdj();
        vector<int> adjWeight = (*ite2)->getWeight();
        int counting = -1;
        vector<Node*> :: iterator ite3;
        for (ite3 = adjEdge.begin(); ite3 != adjEdge.end(); ite3++) {
          counting++;
          if ((*ite3) == temp) {
            adjEdge.erase(ite3);
            adjWeight.erase(adjWeight.begin() + counting);
            (*ite3)->replaceAdj(adjEdge);
            (*ite3)->replaceWeight(adjWeight);
            break;
          }
        }
      }
      if (found == false) {
        cout << "Vertex doesn't exist" << endl;
      }
      vector<Edge*> :: iterator ite = edge.begin(); //Finds every edge that contains the vertex and deletes it
      while (ite != edge.end()) {
        if (strcmp((*ite) -> getStart() -> getName(), remove) == 0 || strcmp((*ite) -> getEnd() -> getName(), remove) == 0) {
          edge.erase(ite);
        }
        else {
          ite++;
        }
      }
    }
    else if (strcmp(in, "Remove Edge") == 0) {

      cout << "Enter name of start node to remove" << endl;
      char* rstart = new char[99];
      cin.getline(rstart, 99);
      cout << "Enter name of end node to remove" << endl;
      char* rend = new char[99];
      cin.getline(rend, 99);
      vector<Node*> :: iterator p;
      for (p = vertex.begin(); p != vertex.end(); p++) { //Delete from the adjacency list
        if (strcmp((*p) -> getName(), rstart) == 0) {
          Node* v1 = (*p);
          vector<Node*> adjE = v1 -> getAdj();
          vector<int> adjW = v1 -> getWeight();
          vector<Node*> :: iterator ite4;
          int counter = -1;
          for (ite4 = adjE.begin(); ite4 != adjE.end(); ite4++) {
            counter++;
            if (strcmp((*ite4)->getName(), rend) == 0) {
              adjW.erase(adjW.begin() + counter);
              v1->removeAdj(rend);
              v1->replaceWeight(adjW);
              break;
            }
          }
        }
      }
      vector<Edge*> :: iterator a = edge.begin(); //Remove the edge from the edge list
      while (a != edge.end()) {
        if (strcmp((*a) -> getStart() -> getName(), rstart) == 0 && strcmp((*a) -> getEnd() -> getName(), rend) == 0) {
          edge.erase(a);
        }
        else {
          a++;
        }
      }
    }
    else if (strcmp(in, "Print") == 0) { 
      cout << "Printing" << endl;
      cout << "    ";
      vector<Node*> :: iterator iter;
      for (iter = vertex.begin(); iter != vertex.end(); iter++) {
        cout << (*iter) -> getName() << "   ";
      }
      cout << '\n'<< endl;
      vector<Node*> :: iterator x;
      for (x = vertex.begin(); x != vertex.end(); x++) { //Each row
        Node* newNode = (*x);
        cout << newNode->getName() << "   ";
        vector<Node*> :: iterator y;
        for (y = vertex.begin(); y != vertex.end(); y++) {
          if (checkConnect((newNode),(*y)) == true) {

            cout << "T   ";
          }
          else {
            cout << "F   ";
          }
        }
        cout << '\n' << endl;
      }
    }

    else if (strcmp(in, "Test") == 0) {
      vector<Edge*> :: iterator iterator;
      for (iterator = edge.begin(); iterator != edge.end(); iterator++) {
        cout << (*iterator) -> getStart() -> getName() << ", " << (*iterator) -> getEnd() -> getName() << endl;
      }
      vector<Node*> :: iterator itr;
      for (itr = vertex.begin(); itr != vertex.end(); itr++) {
        vector<Node*> newVector = (*itr) -> getAdj();
        vector<Node*> :: iterator itt;
        for (itt = newVector.begin(); itt != newVector.end(); itt++) {
          cout << (*itt)->getName()  << endl;
        }
      }
    }











      //oop I small brained
      /*
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
      }*/


    else if (strcmp(in, "Shortest Path") == 0) { //With help from geeks for geeks
      /*
      cout << "Enter start node" << endl;
      char* Start = new char[99];
      cin.getline(Start, 99);
      cout << "Enter end node" << endl;
      char* End = new char[99];
      cin.getline(End, 99);
      vector<vector<Node*>> paths;
      vector<Node*> temp1;
      vector<Node*> temp2;
      vector<Node*> temp3;
      vector<Node*> temp4;
      vector<int> length;
      bool complete = false;
      vector<Node*> :: iterator m;
      for (m = vertex.begin(); m != vertex.end(); m++) {
        if (strcmp((*m)->getName(), Start) == 0) {
          temp1.push_back((*m));
        }
      }
      */


      


    }

    else if (strcmp(in, "Quit") == 0) {
      quit = true;
      break;
    }
  }
}
    

bool checkConnect(Node* begin, Node* stop) {
  vector<Node*> newVector = begin->getAdj();
  vector<Node*> :: iterator n;
  for (n = newVector.begin(); n != newVector.end(); n++) {
    if (strcmp((*n)->getName(), stop->getName()) == 0) {
      return true;
    }
    else {
  
    }
  }
  return false;
}

