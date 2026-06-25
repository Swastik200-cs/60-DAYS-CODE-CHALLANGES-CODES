#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            if (mp.find(x) == mp.end()) {
                ans.push_back(0);
                continue;
            }
            vector<int> &v = mp[x];
            int left = lower_bound(v.begin(), v.end(), l) - v.begin();
            int right = upper_bound(v.begin(), v.end(), r) - v.begin();
            ans.push_back(right - left);
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 1, 3, 1, 2, 3};
    vector<vector<int>> queries = {
        {0, 4, 1},
        {2, 5, 2},
        {1, 6, 3},
        {0, 6, 5}
    };

    Solution obj;
    vector<int> result = obj.freqInRange(arr, queries);
    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}