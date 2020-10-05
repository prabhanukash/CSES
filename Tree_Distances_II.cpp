#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define mset(a, k) memset(a, k, sizeof(a))
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define pqueue priority_queue<ll>
#define piqueue priority_queue<ll, vll, greater<ll>>
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define mapsl map<string, ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string, ll>
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
ll gcd(ll x, ll y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
const ll MAXN = (ll)(1 * 1e6 + 5);
vector<vi> adj;
vi down, ans, num;
ll n;
void calc_down(ll i = 0, ll p = -1)
{
    down[i] = 0;
    for (auto it : adj[i])
    {
        if (it == p)
            continue;
        calc_down(it, i);
        down[i] += down[it] + num[it];
        num[i] += num[it];
    }
    num[i] += 1;
}
void calc_ans(ll i = 0, ll p = -1)
{
    if (i == 0)
    {
        ans[i] = down[i];
    }
    else
    {
        ans[i] = ans[p] + n - 2 * num[i];
    }
    for (auto it : adj[i])
    {
        if (it == p)
            continue;
        calc_ans(it, i);
    }
}
void solve()
{
    //ll n;
    cin >> n;
    adj.resize(n);
    fr(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ans.resize(n);
    num.resize(n);
    down.resize(n);
    calc_down();
    calc_ans();
    for (auto it : ans)
        cout << it << " ";
    cout << '\n';
}
int main()
{
    fast();
    ll t = 1;
    //	cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}