#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        int n=arr.size();
        int buy=-arr[0]; // buying the first stock
        int cash=0; //we donot have any stock we are free to choose.
        for(int i=1;i<n;i++) {
            cash=max(cash,buy+arr[i]-k); //selling the stock.
            buy=max(buy,cash-arr[i]); // buying the stock.
        }
        return cash;
    }
};
int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter stock prices: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cout << "Enter transaction fee: ";
    cin >> k;
    Solution obj;
    int result = obj.maxProfit(arr, k);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}