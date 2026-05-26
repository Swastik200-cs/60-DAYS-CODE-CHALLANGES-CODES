#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findSmallest(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long res = 1;
        for (int x : arr) {
            if (x > res)
                break;
            res += x;
        }
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {3, 1, 2};
    cout << "Smallest positive number that cannot be represented: "
         << obj.findSmallest(arr) << endl;
    return 0;
}