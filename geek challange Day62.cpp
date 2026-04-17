#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int i=0, n=s.size();
         while (i<n && s[i]==' ') {
            i++;
        }
        int sign = 1;
        if (i < n && (s[i]=='+' || s[i]=='-')) {
            if (s[i]=='-') sign = -1;
            i++;
        }
        long result=0;   // Reading the  digits
        while (i<n && isdigit(s[i])) {
            int digit=s[i]-'0';
            
            if (result>(INT_MAX - digit)/10) { // handles the overflows.
                return sign== 1 ? INT_MAX:INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return sign * result;
    }
};
int main() {
    Solution obj;
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    int result = obj.myAtoi(s);
    cout << "Converted Integer: " << result << endl;
    return 0;
}