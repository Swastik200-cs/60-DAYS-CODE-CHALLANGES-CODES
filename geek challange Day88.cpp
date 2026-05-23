#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> seg;
    long long LCM(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }
    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = LCM(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    void update(int idx, int low, int high, int pos, int val) {

        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);
        seg[idx] = LCM(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    long long query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l)
            return 1;
        if (l <= low && high <= r)
            return seg[idx];
        int mid = (low + high) / 2;
        long long left = query(2 * idx + 1, low, mid, l, r);
        long long right = query(2 * idx + 2, mid + 1, high, l, r);
        return LCM(left, right);
    }
    vector<long long> RangeLCMQuery(vector<int>& arr,
                                    vector<vector<int>>& queries) {

        int n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
        vector<long long> ans;
        for (auto q : queries) {
            // Type 1 -> Update
            if (q[0] == 1) {
                int index = q[1];
                int value = q[2];
                update(0, 0, n - 1, index, value);
            }
            else {
                int l = q[1];
                int r = q[2];
                ans.push_back(query(0, 0, n - 1, l, r));
            }
        }
        return ans;
    }
};
int main() {
   vector<int> arr = {2, 3, 4, 5};
    vector<vector<int>> queries = {
        {2, 0, 2}, 
        {1, 1, 6}, 
        {2, 0, 2}
    };
    Solution obj;
    vector<long long> result = obj.RangeLCMQuery(arr, queries);
    cout << "LCM Query Results:\n";
    for (long long x : result) {
        cout << x << " ";
    }
    return 0;
}