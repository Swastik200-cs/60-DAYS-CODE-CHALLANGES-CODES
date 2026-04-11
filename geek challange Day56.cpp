#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        vector<int> smaller(n,-1);
        vector<int> greater(n,-1);
         int X=0; // Let us take the Minimum index as X //
         for (int i=1;i<n;i++) { 
            if (arr[i]<=arr[X]) {
                X=i;
            } else {
                smaller[i]=X;
            }
        }
        int Y=n-1; // Let us take the Minimum index as Y //
        for (int i=n-2;i>=0;i--) {
            if (arr[i]>=arr[Y]) {
                Y=i;
            } else {
                greater[i]=Y;
            }
        }
        for (int i=0;i<n;i++) {
            if (smaller[i] !=-1 && greater[i] !=-1) {
                return {arr[smaller[i]],arr[i],arr[greater[i]]};
            }
        }
        return {}; //Returns an empty vector when no valid values exists//
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
    vector<int> result = obj.find3Numbers(arr);
    if (result.empty()) {
        cout << "0 (No such subsequence exists)" << endl;
    } else {
        cout << "1 (Subsequence found): ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}