#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& arr, int k) {
        int n = arr.size();
        
        if (k >= n) {
            return *max_element(arr.begin(), arr.end());
        }
        
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;
        
        for (int board : arr) {
            high += board;
        }
        
        while (low < high) {
            long long mid = (low + high) / 2;
            
            int painters = 1;
            long long curr_sum = 0;
            
            for (int board : arr) {
                if (curr_sum + board <= mid) {
                    curr_sum += board;
                } else {
                    painters++;
                    curr_sum = board;
                }
            }
            
            if (painters <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};