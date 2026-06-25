#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] - arr[i - 1] < k) {
                ans += arr[i] + arr[i - 1];
                i--;
            }
        }
        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;
    Solution obj;
    int result = obj.sumDiffPairs(arr, k);
    cout << "Sum of pairs = " << result << endl;
    return 0;
}