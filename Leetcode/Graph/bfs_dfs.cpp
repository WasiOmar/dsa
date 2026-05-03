#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    vector<bool> visited;
    int v;

    void dfsHelper(int node, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, result);
            }
        }
    }

public:
    Graph(int v) {
        this->v = v;
        adj.resize(v);
        visited.resize(v, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line if the graph is directed
    }

    void resetVisited() {
        fill(visited.begin(), visited.end(), false);
    }

    void bfs(int start) {
        resetVisited();
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (auto neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    vector<int> dfs() {
        resetVisited();
        vector<int> result;
        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                dfsHelper(i, result);
            }
        }
        return result;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS starting from node 0: ";
    g.bfs(0);

    vector<int> dfsResult = g.dfs();
    cout << "DFS of the graph: ";
    for (int node : dfsResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}