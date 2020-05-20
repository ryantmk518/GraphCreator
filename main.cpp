#include <iostream>
#include "node.h"
#include "edge.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include "stdlib.h"
#include "assert.h"

//Graph Creator. Ryan Thammakhoune

using namespace std;

int main() {
  bool quit = false;
  while (quit == false) {
    cout << "Enter Vertex, Edge" << endl;
    char in[999];
    cin.getline(in, 999);
    if (strcmp(in, "Vertex") == 0) {
      cout << "Enter vertex" << endl;
    }
    else if (strcmp(in, "Edge") == 0) {
      cout << "Enter start and end nodes" << endl;
    }
  }
}
