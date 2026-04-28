#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int count = 0;
        int maxHeight = 0;
        for (int i=0;i<arr.size();i++) {
            if (arr[i]>=maxHeight) {
                count++;
                maxHeight=arr[i];
            }
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter number of buildings: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter building heights: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    int result = obj.visibleBuildings(arr);
    cout << "Buildings receiving sunlight: " << result << endl;
    return 0;
}