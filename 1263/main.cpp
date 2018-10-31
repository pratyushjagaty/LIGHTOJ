/*
    ##############################
    #  Author: Pratyush Gaurav   #
    #  College: NIT ROURKELA     #
    ##############################
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli > plli;
typedef vector<lli> vlli;
typedef vector<plli > vplli;

#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define sqr(x) (x)*(x)
#define all(a) a.begin(),a.end()
#define UN(v) sort(all(v)), v.resize(unique(all(v))-v.begin())

#define endl '\n'

const long long INF = 100000000000000000;
const long long MOD = 1000000007;
const long long MAXN = 1005;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli n, m, totalConnectedComponents, money, sum;
vlli v(MAXN), vis(MAXN);
vlli g[MAXN];

void init() {
    money = 0;
    for (int i = 0; i < MAXN; ++i) {
        g[i].clear();
        vis[i] = 0;
        v[i] = -1;
    }
}

void dfs(lli x) {
    if (vis[x]) return;
    vis[x] = 1;
    totalConnectedComponents++;
    sum += v[x];
    for (auto i : g[x]) {
        dfs(i);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        money += v[i];
    }
    for (int i = 1; i <= m; ++i) {
        lli u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (money % n) {
        cout << "No" << endl;
        return;
    }
    lli avg = money / n;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        totalConnectedComponents = 0;
        sum = 0;
        dfs(i);
        if (sum % totalConnectedComponents or sum / totalConnectedComponents != avg) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    opt;
    lli t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        init();
        solve();
    }
    return 0;
}