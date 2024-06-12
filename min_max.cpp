#include <bits/stdc++.h>
using namespace std;
void min_max(int a[], int low, int high, int &min, int &max)
{
    int min1, max1, mid;

    if (low == high)
    {
        min = max = a[low];
    }
    else if (low == high - 1)
    {

        if (a[low] < a[high])
        {
            min = a[low];
            max = a[high];
        }
        else
        {
            max = a[low];
            min = a[high];
        }
    }
    else
    {
        mid = (low + high) / 2;
        min1 = min;
        max1 = max;
        min_max(a, low, mid, min, max);
        min_max(a, mid + 1, high, min1, max1);

        if (min > min1)
        {
            min = min1;
        }

        if (max < max1)
        {
            max = max1;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int a[n], min, max;
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    min_max(a, 0, n - 1, min, max);

    cout << "Min=" << min << endl;
    cout << "max=" << max << endl;

    return 0;
}