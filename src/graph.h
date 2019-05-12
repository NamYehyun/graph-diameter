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
    unsigned long long next_edge_id;

    unordered_set<Node*> nodes;
    unordered_map<unsigned long long, Node*> id_to_node;

    unordered_set<Edge*> edges;
    unordered_map<unsigned long long, Edge*> id_to_edge;

    Graph(void);
    ~Graph(void);

    Node* getNode(unsigned long long);
    Node* addNode(unsigned long long);

    Edge* addEdge(unsigned long long, unsigned long long);
};

#endif

