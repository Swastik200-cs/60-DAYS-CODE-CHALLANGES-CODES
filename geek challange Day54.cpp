#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int count0=0;
        
        for(int num:arr) { // it will count the number of zeros
            if(num==0) count0++;
        }
        
        for(int i=0;i<count0;i++) { // it will fill the zeros properly in their places.
            arr[i]=0; 
        }
        
        for(int i=count0;i<arr.size();i++) { 
            arr[i]=1; //it will fill the One's properly in their places.
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (0s and 1s only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution obj;
    obj.segregate0and1(arr);
    cout << "After segregation: ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}