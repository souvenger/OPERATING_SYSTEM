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
int wait[1000];
int turn[1000];
pair<int, int> a[1000]; // arrival time, burst time

void waiting_time(int n)
{
    sort(a, a + n);
    wait[0] = 0;
    int time = a[0].ff + a[0].ss;
    for (int i = 1; i < n; i++)
    {
        if (time >= a[i].ff)
        {
            wait[i] = time - a[i].ff;
            time += a[i].ss;
        }
        else
        {
            wait[i] = 0;
            time = a[i].ff + a[i].ss;
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
}
void turn_around_time(int n)
{
    sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        turn[i] = wait[i] + a[i].ss;
        sum += turn[i];
    }
    cout << "Turn Around Time : ";
    for (int i = 0; i < n; i++)
    {
        cout << turn[i] << " ";
    }
    cout << endl;
    cout << "Average Turn Around Time : " << (sum * 1.0) / n << endl;
}
signed main()
{
    int n; // no of processes
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; // arrival time
        int y; // burst time
        cin >> x >> y;
        a[i] = mp(x, y);
    }
    waiting_time(n);
    turn_around_time(n);

    return 0;
}