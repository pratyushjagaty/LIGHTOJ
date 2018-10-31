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
#define opt ios_base::sync_with_stdio(false);cin.tie(0);
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
const long long MAXN = 105;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli n, w, dp[MAXN][MAXN];
plli v[MAXN];

lli f(lli idx, lli moves) {
    if(idx < 0 or idx >= n or moves <= 0) return 0;

    if (dp[idx][moves] != -1) return dp[idx][moves];
    lli i, ans = 0, cnt = 0;

    REP(i, idx, n - 1) {
        if (v[i].first <= v[idx].first + w) cnt++;
    }
    lli idx1 = idx;

    while (idx1 < n and (v[idx1].first <= v[idx].first + w)) idx1++;

    ans = max(ans, cnt + f(idx1, moves - 1));
    ans = max(ans, f(idx + 1, moves));

    return dp[idx][moves] = ans;
}

void solve() {
    lli k, i, j;
    cin >> n >> w >> k;
    rep (i, n) {
        cin >> v[i].first >> v[i].second;
        swap(v[i].first, v[i].second);
    }
    sort(v, v + n);

    rep (i, MAXN) {
        rep(j, MAXN) {
            dp[i][j] = -1;
        }
    }
    lli ans = f(0, k);
    cout << ans << endl;
}

int main()
{
    opt;
    lli t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}