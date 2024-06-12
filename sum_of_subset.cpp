#include <bits/stdc++.h>
using namespace std;
void sum_subset(int x[],int w[],int subset,int &count,int cs,int k,int r)
{
    x[k]=1;
    if(cs+w[k]==subset)
    {
        cout<<endl<<"Subset "<<++count<<endl;

        for(int i=0;i<=k;i++)
        {
            if(x[i]==1)
            {
                cout<<w[i]<<" ";
            }
        }
        cout<<endl;
    }
    else if(cs+w[k]+w[k+1]<=subset)
    {
        sum_subset(x,w,subset,count,cs+w[k], k+1,r-w[k]);
    }
    if(cs+r-w[k]>=subset && cs+w[k]<=subset)
    {
        x[k]=0;
        sum_subset(x,w,subset,count,cs, k+1,r-w[k]);
    }
}
int main(){
    int n;
    cout<<"Enter the no. of elements:";
    cin>>n;

    int x[n],w[n],subset,count=0,sum=0;

    cout<<"Enter the weingts in ascending order:";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<"Enter the sum";
    cin>>subset;

    for(int i=0;i<n;i++)
    {
        sum+=w[i];
    }

    if(sum<subset)
    {
        cout<<"NO Solution found";
    }

    sum_subset(x, w, subset, count, 0, 0, sum);

    if(count==0)
    {
        cout<<"No Solution Found"<<endl;
    }

    return 0;
}