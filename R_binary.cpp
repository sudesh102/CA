#include <bits/stdc++.h>
using namespace std;
int r_bs(int a[],int key,int low,int high)
{
    if(low==high)
    {
        if(a[low]==key)
        {
            return low;
        }
        else{
            return 0;
        }
    }
    else{
        int mid =(low+high)/2;
        if(a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]<key)
        {
            return r_bs(a,key,mid+1,high);
        }
        else{
            return r_bs(a,key,low,mid-1);
        }
    }
}
int main()
{
    int n;
    cout << "Enter the size:";

    cin >> n;

    int a[n], key;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the key to search:";
    cin >> key;
    int ans = r_bs(a, key,0,n);
    if(ans==-1)
    {
        cout<<"Not ffound";
    }
    else{
        cout<<"Found"<<ans<<endl;
    }
        return 0;
}