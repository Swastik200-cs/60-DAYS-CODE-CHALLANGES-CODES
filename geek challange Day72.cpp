#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        unordered_set<int> s1(a.begin(), a.end());
        unordered_set<int> s2;
        vector<int> result;
        for (int x : b) {
            if (s1.count(x)) {
                s2.insert(x);
            }
        }
        for (int x : c) {
            if (s2.count(x)) {
                result.push_back(x);
                s2.erase(x); 
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> ans = obj.commonElements(a, b, c);
    if (ans.empty()) {
        cout << "[]";
    } else {
        cout << "[ ";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "]";
    }
    return 0;
}