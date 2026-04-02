#include <iostream>
using namespace std;
class Solution {
  public:
    int countStrings(int n) {
        if(n==1) // BaseCase is being declared
        return 2;
        int a=2; 
        int b=3;
        for(int i=3;i<=n;i++) { // Using Fibonacci-based DP approach
            int c=a+b; 
            a=b;
            b=c;
        }
        return b; // output 
    }
};
int main() {
    Solution obj;
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of valid binary strings: " << obj.countStrings(n) << endl;
    return 0;
}