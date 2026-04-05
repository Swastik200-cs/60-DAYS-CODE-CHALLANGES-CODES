#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> result;
        int X=1<<n;
        for(int i=0;i<X;i++){
            int gray =i^(i>>1);
            string s ="";
            for(int j=n-1;j>=0;j--) {
                s+= ((gray>>j)&1)?'1':'0';
            }
            result.push_back(s);
        }
        return result;
        }
};
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution obj;
    vector<string> ans = obj.graycode(n);
    cout << "Gray Code Sequence:\n";
    for(auto &code : ans) {
        cout << code << endl;
    }

    return 0;
}