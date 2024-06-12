#include <bits/stdc++.h>
using namespace std;
void display(vector<pair<string, pair<int, int>>> &j)
{
    cout << "Job id   " << "Profit   " << "Deadline   " << endl;
    for (const auto &i : j)
    {
        cout << i.first << "     " << i.second.first << "     " << i.second.second << endl;
    }
    cout << endl;
}
bool comp(const pair<string, pair<int, int>> &a, const pair<string, pair<int, int>> &b)
{
    return a.second.first > b.second.first;
}
int max_dead(const vector<pair<string, pair<int, int>>> &d)
{
    int maxi = 0;
    for (const auto &i : d)
    {
        maxi = max(maxi, i.second.second);
    }
    return maxi;
}
void job_sequence(vector<pair<string, pair<int, int>>> &j)
{
    int max_deadline = max_dead(j);

    vector<string> sequence(max_deadline + 1, "-1");

    float tProfit = 0.0;
    for (const auto &i : j)
    {
        for (int d = max_deadline; d >= 1; d--)
        {
            if (sequence[d] == "-1")
            {
                sequence[d] = i.first;
                tProfit += i.second.first;
                break;
            }
        }
    }

    cout << "Job sequence with max deadline :" << endl;
    for (int i = 0; i <= max_deadline; i++)
    {
        if (sequence[i] != "-1")
        {
            cout << sequence[i] << " ";
        }
    }
    cout << endl;
    cout << "Total profit: " << tProfit << endl;
}
int main()
{
    int n;
    cout << "Enter the no.of jobs:";
    cin >> n;
    vector<pair<string, pair<int, int>>> job;
    string job_id;
    int pro, dead;

    for (int i = 0; i < n; i++)
    {
        cout << "Job id:";
        cin >> job_id;
        cin.ignore();
        cout << "Enter pro:";
        cin >> pro;
        cin.ignore();
        cout << "Enter deadline:";
        cin >> dead;
        cin.ignore();
        job.push_back(make_pair(job_id, make_pair(pro, dead)));
    }
    display(job);
    sort(job.begin(), job.end(), comp);
    display(job);

    job_sequence(job);
    return 0;
}