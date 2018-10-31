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

const long long INF = 10000005;
const long long MOD = 1000000007;
const long long MAXN = 1005;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli n, k;
vlli v(MAXN);

lli f(lli x) {
    lli i = 0, sum = 0, cnt = 0;
    while (i < n + 1) {
        if (sum + v[i] <= x) {
            sum += v[i];
        } else {
            sum = v[i];
            cnt++;
        }
        i++;
    }
    return (cnt <= k);
}

void go(lli ans) {
    lli i, sum = 0;
    lli cnt = k + 1;
    rep(i, n + 1) {
        sum += v[i];
        if (sum > ans or n - i + 2 == cnt) {
            sum -= v[i];
            cnt--;
            cout << sum << endl;
            sum = v[i];
        }
    }
    cout << sum << endl;
}
void solve() {
    lli i;
    cin >> n >> k;
    lli lo = 0, hi = INF, ans = -1;
    rep (i, n + 1) {
        cin >> v[i];
        lo = max(lo, v[i]);
    }
    while (lo <= hi) {
        lli mid = (lo + hi) / 2;
        if (f(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
    go(ans);
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