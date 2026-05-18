class Solution {
public:
    bool dfs(int node, int par, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[node] = true;

        for (int neigh : graph[node]) {
            if (!visited[neigh]) {
                if (!dfs(neigh, node, visited, graph)) return false;
            } 
            else if (neigh != par) {
                return false; // cycle detected
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);

        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        if (!dfs(0, -1, visited, graph)) return false;

        // connectivity check
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};