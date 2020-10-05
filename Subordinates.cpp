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
vvi adj;
vi subtr;
mapll m;
void dfs(ll i, ll p)
{
    for (auto it : adj[i])
    {
        if (it == p)
            continue;
        dfs(it, i);
        subtr[i] += subtr[m[it]++];
    }
}
void solve()
{
    ll n;
    cin >> n;
    adj.resize(n);
    subtr.assign(n, 0);
    fr(i, 1, n)
    {
        ll x;
        cin >> x;
        x--;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    /* fr(i,0,n)
   {
       cout << i << "->";
       for (auto it : adj[i])
           cout << it << "  ";
       cout << '\n';
   }*/
    dfs(0, -1);
    fr(i, 0, n) cout << subtr[i] << " ";
}
int main()
{
    fast();
    ll t = 1;
    //  cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}