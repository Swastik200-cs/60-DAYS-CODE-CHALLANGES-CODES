#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        set<int> s1(a.begin(),a.end());
        set<int> resultSet;
        for (int x:b) {
            if (s1.count(x)) {
                resultSet.insert(x);
            }
        }
        return vector<int>(resultSet.begin(),resultSet.end());
    }
};
int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    Solution obj;
    vector<int> result = obj.intersection(a, b);
    if (result.empty()) {
        cout << "No intersection elements found" << endl;
    } else {
        cout << "Intersection elements: ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}