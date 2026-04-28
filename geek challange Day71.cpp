#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
          vector<int> st;
           for (int x : arr) {
            bool destroyed = false;
            while (!st.empty() && (st.back() > 0 && x < 0 || st.back() < 0 && x > 0)) {
                int top = st.back();
                
                if (abs(top)==abs(x)) {
                    st.pop_back();
                    destroyed = true;
                    break;
                }
                else if (abs(top) > abs(x)) {
                    destroyed = true;
                    break;
                }
                else {
                    st.pop_back();
                }
            }
            if (!destroyed) {
                st.push_back(x);
            }
        }
        return st;
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
    vector<int> result = obj.reducePairs(arr);
    cout << "Final Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}