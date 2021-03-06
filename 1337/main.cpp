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

#define scan(n) scanf("%lld",&n)
#define scan2(a,b) scanf("%lld %lld",&a,&b)
#define scan3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define print(n) printf("%lld\n",n)
#define scanS(s) scanf("%s",&s)
#define printS(s) printf("%s",s)

#define ff first
#define ss second
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define repr(i,a) for(i = a ; i >= 0 ; i--)
#define REP(i,a,b) for(i = a ; i <= b ; i++)
#define REPR(i,a,b) for(i = a ; i >= b ; i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define opt ios_base::sync_with_stdio(false);
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define sqr(x) (x)*(x)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define UN(v) sort(all(v)), v.resize(unique(all(v))-v.begin())

#define endl '\n'

const long long INF = 100000000000000000;
const long long MOD = 1000000007;
const long long MAXN = 505;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli m, n, q, totalConnectedComponents;
char g[MAXN][MAXN];
lli ids[MAXN][MAXN];

bool check(lli x, lli y) {
    return !(x < 1 or x > m or y < 1 or y > n or g[x][y] == '#');
}

void dfs(lli x, lli y, lli id) {
    if (ids[x][y]) return;
    if (!check(x, y)) return;
    ids[x][y] = id;
    if (g[x][y] == 'C') totalConnectedComponents++;
    lli i;
    rep(i, 4) {
        dfs(x + dx[i], y + dy[i], id);
    }
}

void solve() {
    lli id = 1;
    map<lli, lli> mp;
    cin >> m >> n >> q;
    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            g[i][j] = s[j - 1];
        }
    }
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (g[i][j] == 'C' and !ids[i][j]) {
                totalConnectedComponents = 0;
                dfs(i, j, id);
                mp[id] = totalConnectedComponents;
                id++;
            }
        }
    }
    while (q--) {
        lli x, y;
        cin >> x >> y;
        lli locationID = ids[x][y];
        cout << mp[locationID] << endl;
    }
}

void init() {
    mem(ids, 0);
    totalConnectedComponents = 0;
}

int main()
{
    opt;
    lli t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ":\n";
        init();
        solve();
    }
    return 0;
}