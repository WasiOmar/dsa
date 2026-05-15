class Solution {
public:
    int rows, cols;

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx, vector<vector<int>>& vis) {

        // success
        if (idx == word.size()) return true;

        // bounds + invalid
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;

        // already used
        if (vis[r][c]) return false;

        // mismatch
        if (board[r][c] != word[idx]) return false;

        // mark
        vis[r][c] = 1;

        // explore 4 dirs
        bool found =
            dfs(board, word, r + 1, c, idx + 1, vis) ||
            dfs(board, word, r - 1, c, idx + 1, vis) ||
            dfs(board, word, r, c + 1, idx + 1, vis) ||
            dfs(board, word, r, c - 1, idx + 1, vis);

        // unmark (backtrack)
        vis[r][c] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0, vis))
                    return true;
            }
        }

        return false;
    }
};