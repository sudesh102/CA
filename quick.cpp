#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int low, int high)
{
    int pivot = a[low], i = low, j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (a[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "After sort:";
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}