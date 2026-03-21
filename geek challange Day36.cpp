#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size(); 
        vector<int> original = arr;
        sort(arr.begin(), arr.end());
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        catalan[1] = 1; 
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = catalan[i] * catalan[n - i - 1];
        }
        vector<int> result;
        for (int x : original) {
            result.push_back(mp[x]);
        }   
        return result;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    vector<int> ans = obj.countBSTs(arr);
    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}