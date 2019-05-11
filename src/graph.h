#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_set>
#include <unordered_map>

using namespace std;


class Node;
class Edge;
class Graph;


class Node {
public:
    unordered_set<Edge*> edges;

    Node(void);
    ~Node(void);
};


class Edge {
public:
    Node* u;
    Node* v;

    Edge(Node*, Node*);
    ~Edge(void);
};


class Graph {
public:
    unsigned long long num_nodes;
    unsigned long long num_edges;

    unordered_map<unsigned long long, Node*> nodes;
    unordered_map<unsigned long long, Edge*> edges;

    Graph(void);
    ~Graph(void);

    int addNode(Node*);

    int addEdge(Edge*);
    int addEdge(Node*, Node*);
};

#endif

