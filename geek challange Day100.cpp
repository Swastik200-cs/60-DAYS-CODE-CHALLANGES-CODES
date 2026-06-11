#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coin(vector<int>& arr) {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j) {
            if (arr[i] >= arr[j]) {
                i++;
            } else {
                j--;
            }
        }
        return arr[i];
    }
};
int main() {
    Solution obj;
    vector<int> arr = {5, 3, 1, 6, 9};
    cout << "Last remaining coin: "
         << obj.coin(arr) << endl;
    return 0;
}