#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        int count = 0;
        for (int x = 0; x < n; x++) {
            for (int y = x; y < n; y++) {
                if (arr[y] < arr[x])
                    break;
                count++;
            }
        }
        return count;
    }
};
int main() {
    vector<int> arr = {1, 2, 1};
    Solution obj;
    cout << obj.countSubarrays(arr) << endl;
    return 0;
}