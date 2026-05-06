#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int k = 0;
        for (int x : arr) {
            if (x == 1) k++;
        }
        if (k == 0) return -1;
        int currOnes = 0;
        for (int i = 0; i < k; i++) {
            if (arr[i] == 1) currOnes++;
        }

        int maxOnes = currOnes;

        for (int i = k; i < n; i++) {
            if (arr[i] == 1) currOnes++;
            if (arr[i - k] == 1) currOnes--;

            maxOnes = max(maxOnes, currOnes);
        }
        return k - maxOnes;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    int result = obj.minSwaps(arr);
    cout << "Minimum swaps required: " << result << endl;
    return 0;
}