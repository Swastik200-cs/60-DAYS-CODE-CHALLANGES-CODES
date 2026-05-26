#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static const int MODULO_VALUE = 1000;
    bool isInsideRange(int value)
    {
        if (value >= 0 && value < MODULO_VALUE)
        {
            return true;
        }
        return false;
    }
    vector<int> initializeDistanceArray()
    {
        vector<int> distance(MODULO_VALUE, INT_MAX);
        return distance;
    }
    int calculateNextValue(int currentNode, int multiplier)
    {
        long long multiplicationResult =
            1LL * currentNode * multiplier;
        int finalValue =
            multiplicationResult % MODULO_VALUE;

        return finalValue;
    }
    bool shouldVisitNode(int currentDistance,
                         int existingDistance)
    {
        if (currentDistance < existingDistance)
        {
            return true;
        }
        return false;
    }
    void insertIntoQueue(queue<pair<int, int>>& bfsQueue,
                         int node,
                         int steps)
    {
        bfsQueue.push({node, steps});
    }

public:
    int minSteps(vector<int>& arr,
                 int start,
                 int end)
    {
        if (start == end)
        {
            return 0;
        }
        vector<int> distance =
            initializeDistanceArray();
        queue<pair<int, int>> bfsQueue;
        insertIntoQueue(bfsQueue, start, 0);
        distance[start] = 0;
        while (!bfsQueue.empty())
        {
            pair<int, int> currentPair =
                bfsQueue.front();
            bfsQueue.pop();
            int currentNode =
                currentPair.first;
            int currentSteps =
                currentPair.second;
            for (int multiplier : arr)
            {
                int nextNode =
                    calculateNextValue(currentNode,
                                       multiplier);
                int nextDistance =
                    currentSteps + 1;
                if (shouldVisitNode(nextDistance,
                                    distance[nextNode]))
                {
                    distance[nextNode] =
                        nextDistance;
                    if (nextNode == end)
                    {
                        return nextDistance;
                    }
                    insertIntoQueue(bfsQueue,
                                    nextNode,
                                    nextDistance);
                }
            }
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int index = 0;
         index < n;
         index++)
    {
        cin >> arr[index];
    }
    int start;
    int end;
    cin >> start;
    cin >> end;
    Solution solutionObject;
    int answer =
        solutionObject.minSteps(arr,
                                start,
                                end);
    cout << answer << endl;
    return 0;
}