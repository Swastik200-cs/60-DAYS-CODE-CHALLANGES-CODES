#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findIndex(string &s) {
        int n = s.size();

        vector<int> close(n + 1, 0);

        // close[i] = number of ')' from i to n-1
        for (int i = n - 1; i >= 0; i--) {
            close[i] = close[i + 1] + (s[i] == ')');
        }

        int open = 0;

        for (int i = 0; i <= n; i++) {
            if (open == close[i])
                return i;

            if (i < n && s[i] == '(')
                open++;
        }

        return n;
    }
};

int main() {
    string s;

    cout << "Enter bracket string: ";
    cin >> s;

    Solution obj;
    cout << "Equal Point Index: " << obj.findIndex(s) << endl;

    return 0;
}