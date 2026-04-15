class Solution {
    struct T {
        map<char, T*> c;
        string w = "";
    };

    T* root = new T();
    vector<string> ans;
    int n, m;

    void add(string &s) {
        T* t = root;
        for (char x : s) {
            if (!t->c[x]) t->c[x] = new T();
            t = t->c[x];
        }
        t->w = s;
    }

    void dfs(vector<vector<char>>& b, int i, int j, T* t) {
        char x = b[i][j];
        if (x == '#' || !t->c.count(x)) return;

        t = t->c[x];

        if (t->w != "") {
            ans.push_back(t->w);
            t->w = ""; // avoid dup
        }

        b[i][j] = '#';

        if (i > 0) dfs(b, i-1, j, t);
        if (j > 0) dfs(b, i, j-1, t);
        if (i < n-1) dfs(b, i+1, j, t);
        if (j < m-1) dfs(b, i, j+1, t);

        b[i][j] = x;
    }

public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        n = b.size();
        m = b[0].size();

        for (auto &s : w) add(s);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(b, i, j, root);

        return ans;
    }
};