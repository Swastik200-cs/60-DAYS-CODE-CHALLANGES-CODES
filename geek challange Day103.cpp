#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool wifiRange(string &s, int x) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                bool covered = false;
                for (int j = max(0, i - x); j <= min(n - 1, i + x); j++) {
                    if (s[j] == '1') {
                        covered = true;
                        break;
                    }
                }
                if (!covered)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    string s = "10010";
    int x = 1;
    if (obj.wifiRange(s, x))
        cout << "true";
    else
        cout << "false";
    return 0;
}