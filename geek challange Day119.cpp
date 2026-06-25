#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool kSubstr(string &s, int k) {
        int n = s.size();
        if (n % k != 0)
            return false;
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i += k) {
            freq[s.substr(i, k)]++;
        }
        if (freq.size() == 1)
            return true;
        if (freq.size() > 2)
            return false;
        for (auto &p : freq) {
            if (p.second == 1)
                return true;
        }

        return false;
    }
};

int main() {
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    Solution obj;
    if (obj.kSubstr(s, k))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}