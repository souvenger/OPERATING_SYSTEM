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

pair<int, int> p[1005]; //
int wait[1005];
int turn[1005];
int remaining[1005];
signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].ff >> p[i].ss;
        remaining[i] = p[i].ss;
    }
    int x;
    cin >> x;
    sort(p, p + n);
    queue<int> q;
    q.push(0);
    int cnt = 0;
    int time = 0;
    int vis[1005] = {0};
    vis[0] = 1;
    while (n != cnt)
    {
        int idx = q.front();
        q.pop();
        if (remaining[idx] == p[idx].ss)
        {
            time = max(time, p[idx].ff);
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
            turn[idx] = time - p[idx].ff;
            wait[idx] = turn[idx] - p[idx].ss;
        }
        for (int i = 1; i < n; i++)
        {
            if (remaining[i] > 0 && vis[i] == 0 && p[i].ff <= time)
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