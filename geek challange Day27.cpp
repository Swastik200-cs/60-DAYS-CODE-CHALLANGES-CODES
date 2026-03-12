#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n=arr.size();
        int size=arr.size();  
        vector<int> mark(size, 0);
        int x = 0;
        int y = 0;
        for (int i=0;i<size;i++) {
            if (i>=k) {
                x^=mark[i-k];
            }
            if((arr[i]^x)==0) {
                if (i+k>size) return -1;
                 mark[i]=1;
                  x^= 1;
                  y++;
            }
        }
        return y;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1};
    int k = 2;
    int result = sol.kBitFlips(arr, k);
    cout << "Minimum flips required: " << result << endl;
    return 0;
}