#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    string largestSwap(string &s) {
        int n=s.size();
         vector<int> a(n);
         a[n-1]=n-1;
         for(int i=n-2; i>=0; i--){
             if(s[i]>s[a[i+1]])
                a[i]=i;
             else
                a[i]=a[i+1];
         }
         for(int i=0;i<n;i++){
              if(s[i]<s[a[i]]){
                char x = s[i];
                char y = s[a[i]];
                s[i] = y;
                s[a[i]] = x;
                break;
            }
        }
        return s;
    }
};
int main() {
    string s;
    cout << "Enter number string: ";
    cin >> s;
    Solution obj;
    string result = obj.largestSwap(s);
    cout << "Largest after one swap: " << result << endl;
    return 0;
}