#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int,long> mp;
        long ans = 0;
        int xr = 0;
        mp[0] = 1;
        for (auto x : arr) {
            xr ^= x;
            ans += mp[xr ^ k];
            mp[xr]++;
        }
        return ans;
    }
};
int main() {
    Solution obj;
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter value of k: ";
    cin >> k;
    long result = obj.subarrayXor(arr, k);
    cout << "Number of subarrays with XOR = " << k << " is: " << result << endl;
    return 0;
}