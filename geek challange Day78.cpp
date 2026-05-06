#include <iostream>
using namespace std;

class Solution
{
public:
    int findPosition(int n)
    {
        if (n == 0 || (n & (n - 1)) != 0)
            return -1;
        int position = 1;
        while (n > 1)
        {
            n = n >> 1;
            position++;
        }
        return position;
    }
};

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution obj;
    int result = obj.findPosition(n);
    cout << "Position of set bit: " << result << endl;
    return 0;
}