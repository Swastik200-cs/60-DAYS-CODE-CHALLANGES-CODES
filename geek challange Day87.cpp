#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    bool palindromePair(vector<string>& arr) {
        int n = arr.size();

        // Need at least 2 strings
        if (n < 2)
            return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j)
                    continue;

                string temp = arr[i] + arr[j];

                if (isPalindrome(temp))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<string> arr = {"geekf", "geeks", "or", "keeg", "abc", "bc"};

    if (obj.palindromePair(arr))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}