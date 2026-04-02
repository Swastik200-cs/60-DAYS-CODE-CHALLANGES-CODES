#include <iostream>
using namespace std;
class Solution {
public:
    int countWays(int n,int k) {
        if (n==1) return k;
        int same=0;
        int diff=k;
        for (int i = 2; i <= n; i++) {
            int new_same=diff;
            int new_diff=(same+diff)*(k-1);
            same=new_same;
            diff=new_diff;
        }
        return same+diff;
    }
};

int main() {
    Solution obj;
    int n=3,k=2;
    cout << obj.countWays(n,k) << endl;
    return 0;
}