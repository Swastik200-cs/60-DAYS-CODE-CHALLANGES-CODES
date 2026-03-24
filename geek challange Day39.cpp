#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &p:prerequisites){
            int x=p[0],y=p[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            count++;
            for(auto &nbr:adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr]==0) {
                    q.push(nbr);
                }
            }
        }
        return count == n;
    }
};
int main() {
    int n, m;
    cout << "Enter number of courses: ";
    cin >> n;
    cout << "Enter number of prerequisites: ";
    cin >> m;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    cout << "Enter prerequisite pairs (x y):\n";
    for(int i = 0; i < m; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    Solution obj;
    if(obj.canFinish(n, prerequisites)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }
    return 0;
}