#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        int n=houses.size();
        vector<int> minDist(n,INT_MAX);
        vector<bool> visited(n,false);
        minDist[0]=0;
        int totalCost=0;
        for(int i=0;i<n;i++) {
            int u=-1;
            for(int j=0;j<n;j++) {
                if(!visited[j] && (u ==-1||minDist[j]<minDist[u])) {
                    u=j;
                }
            }
            visited[u]=true;
            totalCost += minDist[u];
            //Updating the distances
            for(int v=0;v<n;v++) {
                if(!visited[v]){
                    int dist = abs(houses[u][0]-houses[v][0]) + abs(houses[u][1]-houses[v][1]);
                    minDist[v]=min(minDist[v],dist);
                }
            }
        }
        return totalCost;
    }
};
int main() {
    int n;
    cin >> n;
    vector<vector<int>> houses(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> houses[i][0] >> houses[i][1];
    }
    Solution obj;
    cout << obj.minCost(houses) << endl;
    return 0;
}