#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
         vector<vector<int>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        } 
        vector<int> tin(V,-1), low(V,-1), vis(V,0);
        vector<int> ans;
        int timer=0;
        function<void(int,int)> dfs = [&](int node,int parent){
            vis[node]=1;
            tin[node]=low[node]=timer++;
            int children=0;
            for(int nei:adj[node]){
                if(nei==parent) 
                continue;
                if(!vis[nei]){
                    dfs(nei, node);
                    low[node]=min(low[node],low[nei]);
                    if(low[nei]>=tin[node] && parent != -1){
                        ans.push_back(node);
                    }
                    children++;
                }
                else{
                    low[node] = min(low[node], tin[nei]);
                }
            }
            if(parent==-1 && children>1){
                ans.push_back(node);
            }
        };
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        if(ans.empty()) return {-1};
        return ans;
    }
};
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges(E, vector<int>(2));
    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution obj;
    vector<int> result = obj.articulationPoints(V, edges);
    for(int x : result){
        cout << x << " ";
    }
    return 0;
}