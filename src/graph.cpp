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


Graph::Graph(void): next_edge_id(0) {}

Graph::~Graph(void) {
    for (auto const& node: id_to_node) {
        delete node.second;
    }
}

Node* Graph::addNode(unsigned long long id) {
    Node* node = new Node();

    nodes.insert(node);
    id_to_node[id] = node;

    return node;
}

Node* Graph::getNode(unsigned long long id) {
    if (id_to_node.find(id) == id_to_node.end()) {
        return addNode(id);
    }

    return id_to_node[id];
}


Edge* Graph::addEdge(unsigned long long uid, unsigned long long vid) {
    Node* u = getNode(uid);
    Node* v = getNode(vid);
    Edge* edge = new Edge(u, v);

    u->edges.insert(edge);
    v->edges.insert(edge);

    edges.insert(edge);
    id_to_edge[next_edge_id++] = edge;

    return edge;
}

