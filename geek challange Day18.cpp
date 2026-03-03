#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        if(n <= 2) return n;
        int left = 0;
        int maxLen = 0;
        int num1 = -1, num2 = -1;
        int last1 = -1, last2 = -1; 
        for(int right = 0; right < n; right++) {         
            if(arr[right] == num1) {
                last1 = right;
            }
            else if(arr[right] == num2) {
                last2 = right;
            }
            else if(num1 == -1) {
                num1 = arr[right];
                last1 = right;
            }
            else if(num2 == -1) {
                num2 = arr[right];
                last2 = right;
            }
            else {
                if(last1 < last2) {
                    left = last1 + 1;
                    num1 = arr[right];
                    last1 = right;
                } else {
                    left = last2 + 1;
                    num2 = arr[right];
                    last2 = right;
                }
            }           
            maxLen = max(maxLen, right - left + 1);
        }   
        return maxLen;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {3, 1, 2, 2, 2, 2};  
    int result = obj.totalElements(arr);
    cout << "Length of longest subarray with at most 2 distinct elements: "
         << result << endl;
    return 0;
}