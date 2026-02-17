#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        if (m == 0 || n == 0 || m > n)
            return 0;

        sort(a.begin(), a.end());

        int minDiff = INT_MAX;

        for (int i = 0; i + m - 1 < n; i++) {
            minDiff = min(minDiff, a[i + m - 1] - a[i]);
        }

        return minDiff;
    }
};