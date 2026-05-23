#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> computeLPS(vector<int>& pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {

            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> search(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> lps = computeLPS(b);
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && a[i] != b[j]) {

                if (j != 0) {
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }

        return ans;
    }
};
int main() {
    vector<int> a = {2, 4, 1, 0, 4, 1, 1};
    vector<int> b = {4, 1};
    Solution obj;
    vector<int> result = obj.search(a, b);
    cout << "Starting indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}