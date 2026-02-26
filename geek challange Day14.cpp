#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {       
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<long long>> pre(n + 1,
            vector<long long>(m + 1, 0));       
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pre[i][j] = mat[i-1][j-1]
                          + pre[i-1][j]
                          + pre[i][j-1]
                          - pre[i-1][j-1];
            }
        }      
        int count = 0;
        int maxSide = min(n, m);
        for(int size = 1; size <= maxSide; size++) {
            for(int i = 0; i + size <= n; i++) {
                for(int j = 0; j + size <= m; j++) {
                    int r1 = i, c1 = j;
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    long long sum =
                        pre[r2+1][c2+1]
                      - pre[r1][c2+1]
                      - pre[r2+1][c1]
                      + pre[r1][c1];
                    if(sum == x)
                        count++;
                }
            }
        }  
        return count;
    }
};
int main() {  
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> mat(n, vector<int>(m));
       for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    } 
    int x;
    cin >> x;  
    Solution obj;
    cout << obj.countSquare(mat, x) << endl;
    return 0;
}