#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumXOR(vector<int> &arr) {
        int n = arr.size();
        long long totalSum = 0;
        for (int bit = 0; bit < 32; bit++) {
            long long count1 = 0;
            for (int num : arr) {
                if (num & (1 << bit)) {
                    count1++;
                }
            }
            long long count0 = n - count1;
            totalSum += count1 * count0 * (1LL << bit);
        }
        return totalSum;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {7, 3, 5};
    cout << "Sum of XOR of all pairs: " << obj.sumXOR(arr) << endl;
    return 0;
}