#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    string minWindow(string &s, string &p) {
        vector<int> f(256, 0);
        for (char c : p) 
            f[c]++;
        int l = 0, cnt = p.size(), st = 0, mn = INT_MAX;
        for (int r = 0; r < s.size(); r++) {
            if (f[s[r]]-- > 0)
                cnt--;
            while (cnt == 0) {
                if (r - l + 1 < mn) {
                    mn = r - l + 1;
                    st = l;
                }
                if (++f[s[l++]] > 0)
                    cnt++;
            }
        }
        return mn == INT_MAX ? "" : s.substr(st, mn);
    }
};
int main() {
    Solution obj;
    string s = "timetopractice";
    string p = "toc";
    string result = obj.minWindow(s, p);
    cout << "Smallest window: " << result << endl;
    return 0;
}