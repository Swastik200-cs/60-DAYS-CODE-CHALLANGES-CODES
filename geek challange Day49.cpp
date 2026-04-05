#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n=mat.size();  // here mat refers to a square matrix
        vector<int> result; // used for Vector to store final answer
        for (int sum=0;sum<=2*(n-1);sum++) {
            int start=max(0,sum-(n-1));
             int end=min(n-1,sum);
            for (int i=start;i<=end;i++) {
                int j=sum-i;
                result.push_back(mat[i][j]);
            }
        }
        return result; // Return the final list.
    }
};
int main() {
    int n;
    cin >> n;   // Input size of matrix
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    Solution obj;
    vector<int> ans = obj.diagView(mat);
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
