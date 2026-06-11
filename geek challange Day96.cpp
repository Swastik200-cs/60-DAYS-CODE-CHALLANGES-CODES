#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> s;
        for (long long x : arr) {
            if (target == 0) {
                if (x == 0) {
                    if (!s.empty())
                        return true;
                }
                else {
                    if (s.count(0))
                        return true;
                }
            }
            else {
                if (x != 0 && target % x == 0) {
                    long long need = target / x;
                    if (s.count(need)) {
                        return true;
                    }
                }
            }
            s.insert(x);
        }
        return false;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {10, 20, 9, 40};
    long long target = 400;
    if (obj.isProduct(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}