#include <iostream>
#include "graph.h"

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Graph graph;
    Node* one = new Node();
    Node* two = new Node();
    graph.addNode(one);
    graph.addNode(two);
    graph.addEdge(one, two);

    return EXIT_SUCCESS;
}

