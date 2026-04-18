#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ones = 0;
        for(int x:arr) 
        if(x == 1) ones++;
        int maxGain = 0;
        for(int i=0;i<n;i++) {
            int zeros = 0,onesInside = 0;
            for(int j=i;j<n;j++) {
                if(arr[j] == 0) zeros++;
                else onesInside++;
                int gain=zeros-onesInside;
                maxGain=max(maxGain, gain);
            }
        }
        return ones + maxGain;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 0, 0, 1, 0};
    cout << obj.maxOnes(arr) << endl;  // Output: 4
    return 0;
}