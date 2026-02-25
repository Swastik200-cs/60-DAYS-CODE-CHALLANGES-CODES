#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> first;
        int prefix = 0;
        int maxLen = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > k)
                prefix += 1;
            else
                prefix -= 1;
            if(prefix > 0)
                maxLen = i + 1;
            if(first.find(prefix) == first.end())
                first[prefix] = i;
            if(first.find(prefix - 1) != first.end())
                maxLen = max(maxLen, i - first[prefix - 1]);
        }
        return maxLen;
    }
};
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter k: ";
    cin >> k;
    Solution obj;
    int result = obj.longestSubarray(arr, k);
    cout << "Longest Subarray Length = " << result << endl;
    return 0;
}