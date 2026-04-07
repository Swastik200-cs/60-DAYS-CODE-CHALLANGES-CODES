#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
        int n=men.size();
        vector<int> wife(n,-1); // man engaged to woman "w"
        vector<int> husband(n,-1); // woman engaged to man "m"
        vector<int> next(n,0);
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w=0;w<n;w++) {
            for (int i=0;i<n;i++) {
                rank[w][women[w][i]] = i;
            }
        }
        queue<int> freeMen;
        for (int i=0;i<n;i++) freeMen.push(i);
         while (!freeMen.empty()) {
            int m=freeMen.front();
            freeMen.pop();
            int w = men[m][next[m]]; 
            next[m]++;
            if (wife[w]==-1) { // Woman is free
                wife[w]=m;
                husband[m]=w;
            } 
            else {
                int m1=wife[w];
                if (rank[w][m] < rank[w][m1]) {
                    wife[w] = m;
                    husband[m] = w;
                    freeMen.push(m1);
                } 
                else {
                    freeMen.push(m); 
                }
            }
         }
         return husband;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> men(n, vector<int>(n));
    vector<vector<int>> women(n, vector<int>(n));
    // Input men preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> men[i][j];
        }
    }
    // Input women preferences
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> women[i][j];
        }
    }
    Solution obj;
    vector<int> result = obj.stableMarriage(men, women);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}