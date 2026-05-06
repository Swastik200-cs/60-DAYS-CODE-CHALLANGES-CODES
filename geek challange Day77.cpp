#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < arr.size(); i++) {
            minHeap.push(arr[i]);

            // Keep only k largest elements
            if (minHeap.size() > k) {
                minHeap.pop();
            }

            // If less than k elements, answer is -1
            if (minHeap.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(minHeap.top());
            }
        }

        return result;
    }
};

int main() {
    int n, k;
    
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    vector<int> ans = obj.kthLargest(arr, k);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}