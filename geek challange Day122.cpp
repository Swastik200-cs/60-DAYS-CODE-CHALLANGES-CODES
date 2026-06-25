#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumCost(vector<int>& cost, int w) {
    const int INF = 1e9;
    vector<int> dp(w + 1, INF);
    dp[0] = 0;
    int n = cost.size();
    for (int i = 0; i < n; i++) {
        if (cost[i] == -1) continue;
        int wt = i + 1;
        for (int j = wt; j <= w; j++) {
            dp[j] = min(dp[j], dp[j - wt] + cost[i]);
        }
    }
    return (dp[w] == INF) ? -1 : dp[w];
}

int main() {
    int n, w;
    cout << "Enter number of packet types: ";
    cin >> n;
    vector<int> cost(n);
    cout << "Enter costs: ";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << "Enter required weight: ";
    cin >> w;
    cout << "Minimum Cost = " << minimumCost(cost, w) << endl;
    return 0;
}