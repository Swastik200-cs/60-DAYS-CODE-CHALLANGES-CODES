#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int findMaxProduct(vector<int>& arr) {

        long long mod = 1000000007;
        int negativeCount = 0;
        int zeroCount = 0;
        long long product = 1;
        int maxNegative = -11;
        for (int element : arr) {
            if (element == 0) {
                zeroCount++;
                continue;
            }
            if (element < 0) {
                negativeCount++;
                maxNegative = max(maxNegative, element);
            }
            product *= element;
        }
        if (zeroCount == arr.size()) {
            return 0;
        }
            zeroCount + negativeCount == arr.size()) {
            return 0;
        }
        if (negativeCount % 2 == 1) {
            product = product / maxNegative;
        }
        product = (product % mod + mod) % mod;

        return (int)product;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {-1, 0, -2, 4, 3};
    int answer = obj.findMaxProduct(arr);
    cout << "Maximum Product = " << answer << endl;
    return 0;
}