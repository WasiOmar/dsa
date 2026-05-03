#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
       // adj[v].push_back(u); // remove this line if the graph is directed
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

    void sorthelper(int node,stack<int> &st){
        visited[node]=1;
        for(auto x: adj[node]){
            if(visited[x]==0)
                sorthelper(x,st);
        }
        st.push(node);
    }
    void topological_sort(){
        resetVisited();
        stack<int>st;
        for(int i=0;i<v;i++){
            if(visited[i]==0)
                sorthelper(i,st);
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

   g.topological_sort();

    return 0;
}