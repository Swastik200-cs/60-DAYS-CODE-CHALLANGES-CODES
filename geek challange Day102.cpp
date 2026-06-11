#include<iostream>
#include <iostream>
using namespace std;
class Solution {
public:
    int minToggle(vector<int>& arr) {
        int n = arr.size(), r = 0, z = 0;
        for (int i = 0; i < n; i++) {
            z += (arr[i] == 0);
        }
        int ans = n;
        for (int i = 0; i <= n; i++) {
            int l = 0;
            for (int j = 0; j < i; j++) {
                l += (arr[j] == 1);
            }
            r = 0;
            for (int j = i; j < n; j++) {
                r += (arr[j] == 0);
            }
            ans = min(ans, l + r);
        }
        return ans;
    }
};