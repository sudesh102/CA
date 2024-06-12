#include <bits/stdc++.h>
using namespace std;
int pro[1000], wt[1000], dp[1000][1000];

int knapsack(int n, int cap)
{
    if (cap <= 0)
        return 0;
    if (n <= 0)
        return 0;
    if(dp[n][cap]!=-1)
    {
        return dp[n][cap];
    }    

    if(wt[n-1]>cap)
    {
        dp[n][cap]=knapsack(n-1,cap);
    }
    else 
    {
        dp[n][cap]=max(knapsack(n-1,cap),knapsack(n-1,cap-wt[n-1])+pro[n-1]);
    }
    return dp[n][cap];
}
int main()
{
    int n;
    cout << "Enter the no. of items:";
    cin >> n;

    cout << "Enter the Weights:";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << "Enter the profits:";
    for (int i = 0; i < n; i++)
    {
        cin >> pro[i];
    }

    int cap;
    cout << "Enter the capcity:";
    cin >> cap;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout<<"Maximim Profit is:"<<knapsack(n,cap)<<endl;
    return 0;
}