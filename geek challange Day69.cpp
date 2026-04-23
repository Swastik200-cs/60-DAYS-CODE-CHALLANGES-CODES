#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        long long total = 0;
        // Calculate total sum
        for (int num : arr) {
            total += num;
        }
        if (total % 2 != 0) return false;

        long long target = total / 2;
        long long currSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            if (currSum == target && i < arr.size() - 1) {
                return true;
            }
        }

        return false;
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
    Solution obj;
    if (obj.canSplit(arr)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}