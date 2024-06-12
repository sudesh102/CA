#include <bits/stdc++.h>
using namespace std;
void display(vector<pair<string, pair<int, int>>> &j)
{
    cout << "Job ID\t\t" << "Profit\t\t" << "Deadline\t\t" << endl;

    for (const auto &i : j)
    {
        cout << i.first << "\t\t" << i.second.first << "\t\t" << i.second.second << endl;
    }
    cout << endl;
}
bool comp(const pair<string, pair<int, int>> &a, const pair<string, pair<int, int>> &b)
{
    return a.second.first > b.second.first;
}
int max_dead(const vector<pair<string, pair<int, int>>> &j)
{
    int maxi = 0;
    for (const auto &i : j)
    {
        maxi = max(maxi, i.second.second);
    }
    return maxi;
}
int job_sequence(vector<pair<string, pair<int, int>>> &j)
{
    sort(j.begin(), j.end(), comp);

    cout << "After sorting ascending order of profit" << endl;
    display(j);
    int max_deadline = max_dead(j);
    vector<string> sequence(max_deadline + 1, "-1");

    float tProfit = 0.0;
    for (const auto &i : j)
    {
        for (int d = i.second.second; d >= 1; d--)
        {
            if (sequence[d] == "-1")
            {
                sequence[d] = i.first;
                tProfit += i.second.first;
                break;
            }
        }
    }
    cout << "Job sequence with max profit:" << endl;
    for (int i = 1; i <= max_deadline; i++)
    {
        if (sequence[i] != "-1")
        {
            cout << sequence[i] << " ";
        }
    }
    cout << endl;
    cout << "Total Profit:" << tProfit << endl;
}
int main()
{
    int n;
    cout << "Enter the no of jobs:";
    cin >> n;

    vector<pair<string, pair<int, int>>> job;
    string job_id;
    int pro, dead;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Job Id:";
        cin >> job_id;
        cin.ignore();
        cout << "ENter profit:";
        cin >> pro;
        cin.ignore();
        cout << "Enter dead line:";
        cin >> dead;
        cin.ignore();

        job.push_back(make_pair(job_id, make_pair(pro, dead)));
    }
    display(job);
    job_sequence(job);
    return 0;
}