#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string findLargest(vector<int> &arr) {
        vector<string> nums;
        for (int x : arr) {
            nums.push_back(to_string(x));
        }
        sort(nums.begin(), nums.end(),
             [](string a, string b) {
                 return a + b > b + a;
             });
        if (nums[0] == "0")
            return "0";
        string result = "";
        for (string &s : nums)
            result += s;
        return result;
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
    string ans = obj.findLargest(arr);
    cout << "Largest formed number: " << ans << endl;
    return 0;
}
