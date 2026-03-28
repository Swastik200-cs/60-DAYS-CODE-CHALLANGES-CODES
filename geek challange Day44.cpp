#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n=arr.size();
        int sum=0;
        for(int x : arr) sum += x;
        if ((sum+diff) %2!= 0||sum < diff) return 0;
        int target=(sum + diff) / 2;
        vector<int> A(target + 1, 0);
        A[0]=1;
        for(int num:arr) {
            for(int j=target;j>=num;j--) {
                A[j] += A[j - num];
            }
        }
        return A[target];
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 1, 1, 1};
    int diff = 0;
    cout << "Number of partitions: " 
         << sol.countPartitions(arr, diff) << endl;
    return 0;
}