#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int count=0;
        int len= 1;
        for (int i=1;i<n;i++) {
            if (arr[i]>arr[i-1]) {
                len++;
                count +=(len-1);
            } 
            else {
                len=1;
            }
        }
        return count;
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
    int result = obj.countIncreasing(arr);
    cout << "Number of strictly increasing subarrays: " << result << endl;
    return 0;
}