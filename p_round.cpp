//███████╗ ██████╗ ██╗   ██╗██╗   ██╗███████╗███╗   ██╗ ██████╗ ███████╗██████╗
//██╔════╝██╔═══██╗██║   ██║██║   ██║██╔════╝████╗  ██║██╔════╝ ██╔════╝██╔══██╗
//███████╗██║   ██║██║   ██║██║   ██║█████╗  ██╔██╗ ██║██║  ███╗█████╗  ██████╔╝
//╚════██║██║   ██║██║   ██║╚██╗ ██╔╝██╔══╝  ██║╚██╗██║██║   ██║██╔══╝  ██╔══██╗
//███████║╚██████╔╝╚██████╔╝ ╚████╔╝ ███████╗██║ ╚████║╚██████╔╝███████╗██║  ██║
//╚══════╝ ╚═════╝  ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define range(i, n) for (int i = 0; i < n; i++)
#define range1(i, n) for (int i = 1; i <= n; i++)
#define mod9 1000000009
#define mod7 1000000007
#define INF 1e18
#define sp(y) fixed << setprecision(y)
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define test(x) \
    int x;      \
    cin >> x;   \
    while (x--)
#define ff first
#define ss second
#define pii pair<int, int>
#define mii map<int, int>
#define mp make_pair
#define append push_back
#define pb pop_back
#define fast_io std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define input(x) cin >> (x)

// Prioriti round robin sheduling
struct process
{
    int pid, ar, bt, pr;
};

bool comp(process a, process b)
{
    if (a.at == b.at)
    {
        return a.pr < b.pr;
    }
    return a.ar < b.ar;
}
int wait[1005];
int turn[1005];
int remaining[1005];
process p[1005];
signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        cin >> p[i].at >> p[i].bt >> p[i].pr;
        remaining[i] = p[i].bt;
    }
    int x;
    cin >> x;
    sort(p, p + n, comp);
    queue<int> q;
    q.push(0);
    int cnt = 0;
    int time = 0;
    int vis[1005] = {0};
    vis[0] = 1;
    while (n != cnt)
    {
        int idx = -1;
        vector<int> v;
        while (q.empty() == false)
        {
            int i = q.front();
            v.push_back(i);
            q.pop();
        }
        int mx = 1000000;
        for (int i = 0; i < v.size(); i++)
        {
            if (p[v[i]].pr < mx)
            {
                mx = p[v[i]].pr;
                idx = v[i];
            }
        }
        if (remaining[idx] == p[idx].bt)
        {
            time = max(time, p[idx].at);
        }
        if (remaining[idx] - x > 0)
        {
            remaining[idx] -= x;
            time += x;
        }
        else
        {
            time += remaining[idx];
            cnt++;
            //vis[idx] = 1;
            remaining[idx] = 0;
            turn[idx] = time - p[idx].at;
            wait[idx] = turn[idx] - p[idx].bt;
        }
        for (int i = 1; i < n; i++)
        {
            if (remaining[i] > 0 && vis[i] == 0 && p[i].at <= time)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        if (remaining[idx] > 0)
        {
            q.push(idx);
        }
        if (q.empty())
        {
            for (int i = 1; i < n; i++)
            {
                if (remaining[i] > 0)
                {
                    q.push(i);
                    vis[i] = 1;
                    break;
                }
            }
        }
    }
    cout << "Waiting Time : ";
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << wait[i] << " ";
        sum += wait[i];
    }
    cout << endl;
    cout << "Average waiting Time : " << (sum * 1.0) / n << endl;
    cout << "Turn Around Time : ";
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << turn[i] << " ";
        sum += turn[i];
    }
    cout << endl;
    cout << "Average Turn Around Time : " << (sum * 1.0) / n << endl;
}