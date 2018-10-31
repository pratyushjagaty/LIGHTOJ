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
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);
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
const long long MAXN = 35;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

string s, t;
unsigned long ans1;
lli dp[MAXN][MAXN], dp1[MAXN][MAXN];

lli f(lli x, lli y){
    lli ans = 0;
    if (x >= s.length() or y >= t.length()) {
        return 0;
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    if(s[x] == t[y]) {
        ans = max(ans, 1 + f(x + 1, y + 1));
    }
    ans = max(ans, f(x + 1, y));
    ans = max(ans, f(x, y + 1));
    return dp[x][y] = ans;
}

lli go(lli x, lli y) {
    lli ans = 0;
    if (x >= s.length() or y >= t.length()) {
        return 1;
    }
    if(dp1[x][y] != -1)
        return dp1[x][y];
    if (s[x] == t[y]) {
        if (f(x, y) == 1 + f(x + 1, y + 1))
            ans += go(x + 1, y + 1);
    } else {
        if (f(x, y) == f(x, y + 1)) {
            ans += go(x, y + 1);
        }
        if (f(x, y) == f(x + 1, y)) {
            ans += go(x + 1, y);
        }
    }
    return dp1[x][y] = ans;
}
void solve() {
    s.clear(), t.clear();
    cin >> s >> t;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            dp[i][j] = dp1[i][j] = -1;
        }
    }
    ans1 = (s.length() + t.length() - f(0, 0));
    lli ans2 = go(0, 0);
    cout << ans1 << " " << ans2 << endl;
}

int main()
{
    opt;
    lli t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": "; solve();
    }
    return 0;
}