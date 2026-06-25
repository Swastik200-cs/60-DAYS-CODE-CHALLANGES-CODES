#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();
        if (isPowerOfTwo(n))
            k /= 2;
        else
            k *= 2;
        if (k > n || n - k <= 0)
            return "-1";
        string st;
        int remove = k;
        for (char ch : s) {
            while (!st.empty() && remove > 0 && st.back() > ch) {
                st.pop_back();
                remove--;
            }
            st.push_back(ch);
        }
        while (remove > 0 && !st.empty()) {
            st.pop_back();
            remove--;
        }
        return st.empty() ? "-1" : st;
    }
};

int main() {
    Solution obj;

    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    cout << "Lexicographically Smallest String: "
         << obj.lexicographicallySmallest(s, k) << endl;
    return 0;
}