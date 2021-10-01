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
bool comp(pii a, pii b)
{
    if (a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff < b.ff;
}
pair<int, int> p[1005]; //arrival time, burst time
int wait[1005], turn[1005];
signed main()
{
    int n;
    cin >> n; //no. of processes
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].ff >> p[i].ss;
    }
    // sort(p, p + n, comp);
    // int time = p[0].ff + p[0].ss;
    // wait[0] = 0;
    // turn[0] = p[0].ss;
    int vis[n + 1] = {0};
    //vis[0] = 1;
    int time = 0;
    int x = 0; // no. of processes completed
    while (n != x)
    {
        int min = INF;
        int ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].ff <= time && !vis[i])
            {
                if (p[i].ss < min)
                {
                    min = p[i].ss;
                    ind = i;
                }
            }
            if (p[i].ss == min) //if same burst time
            {
                if (p[i].ff < p[ind].ff)
                {
                    ind = i;
                }
            }
        }
        if (ind != -1)
        {
            wait[ind] = time - p[ind].ff;
            turn[ind] = wait[ind] + p[ind].ss;
            vis[ind] = 1;
            time += p[ind].ss;
            x++;
        }
        else
        {
            time++;
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

    return 0;
}