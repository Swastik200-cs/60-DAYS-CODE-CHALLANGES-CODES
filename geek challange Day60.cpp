#include <iostream>
using namespace std;
class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string result=" ";
         for(char ch:s) {
            if(ch!=' ') {
                result +=ch;
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    string s;
    cout << "Enter the string: ";
    getline(cin, s); 
    string output = obj.removeSpaces(s);
    cout << "Output: " << output << endl;
    return 0;
}