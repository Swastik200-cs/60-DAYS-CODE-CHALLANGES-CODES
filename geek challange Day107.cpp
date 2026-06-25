#include <iostream>
using namespace std;

class Solution {
public:
    bool isSumOfConsecutive(int n) {
        return (n & (n - 1)) != 0;
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;
    if (obj.isSumOfConsecutive(n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}