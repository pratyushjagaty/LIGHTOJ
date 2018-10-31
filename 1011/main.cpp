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
const long long MAXN = 17;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli n, a[MAXN][MAXN], dp[17][1 << 17];

int check(lli s, lli idx) {
    return (int)((1 << (n - idx + 1)) & s);
}

lli f(lli x, lli marked) {
    lli j, ans = 0;
    if (x > n) {
        return 0;
    }
    if(dp[x][marked] != -1)
        return dp[x][marked];
    for (j = 1; j <= n; j++) {
        if (!check(marked, j)) {
            ans = max(ans, a[x][j] + f(x + 1, marked | (1 << (n - j + 1))));
        }
    }
    return dp[x][marked] = ans;
}
void solve() {
    lli i, j;
    cin >> n;
    mem(dp, -1);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << f(1, 0) << endl;
}

int main()
{
    opt;
    lli t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}