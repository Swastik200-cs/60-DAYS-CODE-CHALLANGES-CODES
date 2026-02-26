#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {       
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        for (int i = 0; i < s1.length(); i++) {          
            char a = s1[i];
            char b = s2[i];
            if (m1.count(a) && m1[a] != b)
                return false;
            if (m2.count(b) && m2[b] != a)
                return false;
            m1[a] = b;
            m2[b] = a;
        }
        return true;
    }
};
int main() {
    Solution obj;
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    if (s1.length() != s2.length()) {
        cout << "false" << endl;
        return 0;
    }
    bool result = obj.areIsomorphic(s1, s2);
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}