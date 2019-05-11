#include "graph.h"


Node::Node(void) {}

Node::~Node(void) {
    for (Edge* const edge: edges) {
        if (edge->u == this) {
            edge->v->edges.erase(edge);
        } else {
            edge->u->edges.erase(edge);
        }
        delete edge;
    }
}


Edge::Edge(Node* _u, Node* _v): u(_u), v(_v) {}

Edge::~Edge(void) {}


Graph::Graph(void): num_nodes(0), num_edges(0) {}

Graph::~Graph(void) {
    for (auto const& node: nodes) {
        delete node.second;
    }
}

int Graph::addNode(Node* node) {
    nodes[num_nodes++] = node;
    return 0;
}

int Graph::addEdge(Edge* edge) {
    edges[num_edges++] = edge;
    edge->u->edges.insert(edge);
    edge->v->edges.insert(edge);
    return 0;
}

int Graph::addEdge(Node* u, Node* v) {
    Edge* edge = new Edge(u, v);
    return addEdge(edge);
}

