#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        vector<int> result;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            long long sum;
            if (l == 0) sum = prefix[r];
            else sum = prefix[r] - prefix[l - 1];
            int len = r - l + 1;
            result.push_back(sum / len);
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<int> result = obj.findMean(arr, queries);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}