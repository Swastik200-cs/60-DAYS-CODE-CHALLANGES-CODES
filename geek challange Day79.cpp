#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            return __builtin_popcount(a) > __builtin_popcount(b);
        });
        
        return arr;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    vector<int> result = obj.sortBySetBitCount(arr);
    for (int x : result) {
        cout << x << " ";
    }  
    return 0;
}