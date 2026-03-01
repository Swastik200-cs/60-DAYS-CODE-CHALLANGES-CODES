#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    sol.pushZerosToEnd(arr);
    cout << "Array after moving zeros to end:\n";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}