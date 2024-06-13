#include<iostream>
using namespace std;
int val[1000],wt[1000];
int knapsack(int n,int cap)
{
    if(cap<=0)
    return 0;

    if(n<=0)
    return 0;

    if(wt[n-1]>cap)
    return knapsack(n-1,cap);

    return max(knapsack(n-1,cap),knapsack(n-1,cap-wt[n-1])+val[n-1]);


}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>wt[i];

    for(i=0;i<n;i++)
    cin>>val[i];

    int cap;
    cin>>cap;

    cout<<knapsack(n,cap);



}
