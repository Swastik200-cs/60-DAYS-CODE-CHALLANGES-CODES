#include <iostream>
using namespace std;
class Solution {
public:
    string URLify(string &s) {
        string result = "";
        for(char c : s) {
            if(c == ' ')
                result += "%20";
            else
                result += c;
        }    
        return result;
    }
};
int main() {
    Solution obj;
    string s;
    cout << "Enter string: ";
    getline(cin, s); 
    string result = obj.URLify(s);
    cout << "Output: " << result << endl;
    return 0;
}