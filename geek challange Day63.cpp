#include <iostream>
#include <string>
using namespace std;

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int oddCount = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int count = 0;
            for(char c : s) {
                if(c == ch) count++;
            }
             if(count % 2 != 0) {
                oddCount++;
             }
        }
        return oddCount <=1;
    }
};
int main() {
    string s;
    cin >> s;
    Solution obj;
    if(obj.canFormPalindrome(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}