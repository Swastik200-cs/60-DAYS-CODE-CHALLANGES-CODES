#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int x = 0; 
        for (int i = 0; i < k; i++) {
            x ^= arr[i];
        }
        int y = x;
        for (int i = k; i < n; i++) {
            x ^= arr[i - k];
            x ^= arr[i];
            y = max(y, x);
        }
        return y;
    }
};
int main() {
    vector<int> arr = {2, 5, 8, 1, 1, 3};
    int k = 3;
    Solution obj;
    cout << "Maximum XOR of subarray of size k: "
         << obj.maxSubarrayXOR(arr, k) << endl;

    return 0;
}