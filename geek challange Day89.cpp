#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0);
        int ans = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                ans = i;
            }
        }
        fill(vis.begin(), vis.end(), 0);
        dfs(ans, adj, vis);
        for (int x : vis) {
            if (!x) {
                return -1;
            }
        }
        return ans;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 2},
        {0, 3},
        {1, 0},
        {2, 1},
        {3, 4}
    };
    Solution obj;
    cout << "Mother Vertex: "
         << obj.findMotherVertex(V, edges);
    return 0;
}