#include <bits/stdc++.h>
using namespace std;

void enterArray(string name, int n, vector<int> array)
{
    cout << "start entring value for " << name << endl;
    for (int i = 0; i < n; i++)
    {
        {
            int a;
            cout << "for " << i << "th term: ";
            cin >> a;
            array.push_back(a);
        }
    }
}

void resetDP(vector<vector<int>> dp, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp.at(i).at(j) = -1;
}

int knapSackRec(int W, vector<int> wt, vector<int> val, int index, vector<vector<int>> dp)
{
    if (index < 0)
        return 0;

    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W)
    {
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    }
    else
    {
        dp[index][W] = max(val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp),
                           knapSackRec(W, wt, val, index - 1, dp));
        return dp[index][W];
    }
}

int knapSack(int W, vector<int> wt, vector<int> val, int n)
{

    vector<vector<int>> dp;
    resetDP(dp, n);

    return knapSackRec(W, wt, val, n - 1, dp);
}
