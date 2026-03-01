#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0;        
        int j = m - 1;    
        int minDiff = INT_MAX;
        vector<int> result(2);
        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            int diff = abs(sum - x);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = arr1[i];
                result[1] = arr2[j];
            }
            if (sum > x)
                j--;
            else
                i++;  
        }
        return result;
    }
};
int main() {
    Solution obj;
    vector<int> arr1 = {1, 4, 5, 7};
    vector<int> arr2 = {10, 20, 30, 40};
    int x = 32;
    vector<int> ans = obj.findClosestPair(arr1, arr2, x);
    cout << "Closest Pair: [" << ans[0] << ", " << ans[1] << "]" << endl;
    return 0;
}