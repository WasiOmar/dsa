class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {

        // cycle detected
        if (state[node] == 1) {
            return false;
        }

        // already processed
        if (state[node] == 2) {
            return true;
        }

        // mark as visiting
        state[node] = 1;

        for (int neigh : graph[node]) {
            if (!dfs(neigh, graph, state)) {
                return false;
            }
        }

        // mark as fully visited
        state[node] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, graph, state)) {
                return false;
            }
        }

        return true;
    }
};