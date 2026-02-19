#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> result;

        for (int i = low; i <= high; i++) {
            if (s.find(i) == s.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low, high;
    cout << "Enter low and high range: ";
    cin >> low >> high;

    vector<int> result = obj.missinRange(arr, low, high);

    cout << "Missing numbers in range: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
