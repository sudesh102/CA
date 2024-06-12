#include <bits/stdc++.h>
using namespace std;

void display(vector<pair<pair<int, int>, float>> &k)
{
    cout << "Profit       " << "Weight      " << "Pbyw        " << endl;
    for (const auto &i : k)
    {
        cout << i.first.first << "          " << i.first.second << "          " << i.second << endl;
    }
    cout << endl;
}
bool comp(const pair<pair<int, int>, float> &a, const pair<pair<int, int>, float> &b)
{
    return a.second > b.second;
}
float fractional_knap(vector<pair<pair<int, int>, float>> &k, int cap)
{
    sort(k.begin(), k.end(), comp);
    cout << endl;
    cout << "After sorting:";
    display(k);

    float finalPro = 0.0;

    int index = 0;

    for (int i = 0; i < k.size(); i++)
    {
        if (cap > 0 && k[i].first.second <= cap)
        {
            cap -= k[i].first.second;
            finalPro += float(k[i].first.first);
            index++;
        }
    }
    if (cap > 0)
    {
        finalPro += (cap * k[index].first.first) / (k[index].first.second);
    }
    return finalPro;
}
int main()
{
    int n;
    cout << "Enter the no. of ";
    cin >> n;
    float cap;
    cout << "Enter the cap of knapsack:";
    cin >> cap;
    vector<pair<pair<int, int>, float>> kanp;
    int pro, wt;
    float pbyw;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Profit:";
        cin >> pro;
        cout << "Enter Wt:";
        cin >> wt;
        pbyw = (float)pro / wt;

        kanp.push_back(make_pair(make_pair(pro, wt), pbyw));
    }
    display(kanp);
    float finalProfit = fractional_knap(kanp, cap);
    cout << "Final Profit:" << finalProfit << endl;
    return 0;
}