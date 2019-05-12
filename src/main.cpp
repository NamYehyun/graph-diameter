#include <fstream>
#include <iostream>
#include <sstream>

#include "graph.h"

using namespace std;


void build_graph(string& infile, Graph& graph);


int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    if (argc < 2) {
        return EXIT_FAILURE;
    }

    Graph graph;
    string infile(argv[1]);
    build_graph(infile, graph);

    for (auto const& ie: graph.id_to_edge) {
        cout << "edge " << ie.first << ": " << ie.second->u << " - " << ie.second->v << endl;
    }

    return EXIT_SUCCESS;
}


void build_graph(string& path, Graph& graph) {
    string line;
    ifstream infile(path);
    while (getline(infile, line)) {
        if (line.find('#') != string::npos) {
            continue;
        }

        int u, v;
        istringstream iss(line);
        iss >> u >> v;
        
        graph.addEdge(u, v);
    }

    return;
}

