#include <iostream>
using namespace std;

class Solution {
public:
    int solve(string &s, int idx, int prevSum) {
        if (idx == s.size())
            return 1;
        int ans = 0;
        int sum = 0;
        for (int i = idx; i < s.size(); i++) {
            sum += s[i] - '0';
            if (sum >= prevSum) {
                ans += solve(s, i + 1, sum);
            }
        }
        return ans;
    }
    int validGroups(string &s) {
        return solve(s, 0, 0);
    }
};

int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.validGroups(s);
    return 0;
}