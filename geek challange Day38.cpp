#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V,-1);
        for (auto &e : edges) {
            adj[e[0]]=e[1];
        }
        vector<int>visited(V,0);
        int maxCycle=-1;
        for (int i=0;i<V;i++) {
            if (visited[i]) continue;
             unordered_map<int,int> stepMap;
             int node=i;
             int step=0;
             while (node !=-1 && !visited[node]) {
                 visited[node]=1;
                 stepMap[node]=step++;
                 node=adj[node];
                 if (node !=-1 && stepMap.count(node)) {
                    int cycleLength =step-stepMap[node];
                    maxCycle=max(maxCycle,cycleLength);
                    break;
                }
            }
        }
        return maxCycle;
    }
};
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution obj;
    cout << obj.longestCycle(V, edges) << endl;
    return 0;
}