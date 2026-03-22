#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0; i<n;i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==2) {
                    q.push({i,j});
                }
                else if(mat[i][j]==1) {
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int time=0;
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        while(!q.empty()) {
            int size=q.size();
            bool rotten=false;
            for(int i=0;i<size;i++) {
                auto [x,y]=q.front();
                q.pop();
                for(int d=0;d<4;d++) {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(nx>= 0 && ny>= 0 && nx<n && ny<m && mat[nx][ny]==1) 
                    {
                        mat[nx][ny]=2;
                        q.push({nx, ny});
                        fresh--;
                        rotten=true;
                    }
                }
            }
            if(rotten) time++;
    }
    return (fresh==0) ? time:-1;
    }
};
int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };
    int result = obj.orangesRot(mat);
    cout << "Minimum time required: " << result << endl;
    return 0;
}