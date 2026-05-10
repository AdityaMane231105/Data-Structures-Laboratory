#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

class Graph {
    int vertices;
    vector< vector<int> > adj;

public:
    Graph(int v) {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i];

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    g.BFS(start);

    cout << endl;

    system("pause");

    return 0;
}
