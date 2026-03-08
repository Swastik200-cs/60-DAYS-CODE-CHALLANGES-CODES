#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        for (int &x : arr)
            x = x * x;
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (arr[l] + arr[r] == arr[i])
                    return true;
                else if (arr[l] + arr[r] < arr[i])
                    l++;
                else
                    r--;
            }
        }
        return false;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {3, 2, 4, 6, 5};
    if (obj.pythagoreanTriplet(arr))
        cout << "true";
    else
        cout << "false";
    return 0;
}