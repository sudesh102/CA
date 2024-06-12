#include <bits/stdc++.h>
using namespace std;
int bs(int a[], int key, int size)
{
    int h = size - 1, l = 0;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (a[mid] == key)
        {
            return a[mid];
        }
        else if (key < a[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
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
    int ans = bs(a, key, n-1);
    if(ans==-1)
    {
        cout<<"Not ffound";
    }
    else{
        cout<<"Found"<<ans<<endl;
    }
        return 0;
}