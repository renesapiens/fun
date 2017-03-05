#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Graph {
private:
    int num_vertex;
    list<int> *graph_adj;
public:
    Graph(int vertex);
    void addEdge(int v, int w);
    void topSortUtil(int vertex, bool *visited, stack<int> &st);
    void topSort();
};

Graph::Graph(int v) {
    num_vertex = v;
    graph_adj = new list<int>[num_vertex];
}

void Graph::addEdge(int vertex, int weight) {
    graph_adj[vertex].push_back(weight);
}

// Used to visit all the vertex and recursively add them to the stack.
void Graph::topSortUtil(int vertex, bool *visited, stack<int> &st) {
    visited[vertex] = true;

    for(auto it = graph_adj[vertex].begin(); it != graph_adj[vertex].end(); it++) {
        if(!visited[*it])
            topSortUtil(*it, visited, st);
    }
    st.push(vertex);
}

void Graph::topSort() {
    // Stack used to get the order of elements.
    stack<int> st;
    // Keep track of visited vertex
    bool *visited = new bool[num_vertex];

    for (int i = 0; i < num_vertex; i++)
        visited[i] = false;

    // Visit each vertex and get the topological
    // sort. If vertex is already visited just skip.
    for(int i = 0; i < num_vertex; i++) {
        if(!visited[i])
            topSortUtil(i, visited, st);
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    Graph graph(8);
    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(2, 6);
    graph.addEdge(2, 5);
    graph.addEdge(2, 4);
    graph.addEdge(1, 5);
    graph.addEdge(6, 7);
    graph.addEdge(7, 3);
    graph.addEdge(4, 7);

    cout << "Printing topological sort of the graph: ";
    graph.topSort();
    return 0;
}
