#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> res;
        for (int x : arr) {
            if (!res.empty() &&
                ((res.back() >= 0 && x < 0) ||
                 (res.back() < 0 && x >= 0))) {

                res.pop_back();
            }
            else {
                res.push_back(x);
            }
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> ans = obj.makeBeautiful(arr);
    cout << "Beautiful Array: ";
    if (ans.empty()) {
        cout << "[]";
    }
    else {
        for (int x : ans) {
            cout << x << " ";
        }
    }
    return 0;
}