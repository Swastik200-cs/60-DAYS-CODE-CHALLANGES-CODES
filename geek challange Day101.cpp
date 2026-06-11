#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkElements(int start, int end, vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        for (int i = start; i <= end; i++) {
            if (s.find(i) == s.end()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 4, 5, 2, 7, 8, 3};
    int start = 2;
    int end = 5;
    if (obj.checkElements(start, end, arr)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}