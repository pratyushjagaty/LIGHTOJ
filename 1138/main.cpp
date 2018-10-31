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
#define printS(s) printf("%s\n",s)

#define rep(i,a) for(i = 0 ; i < a ; i++)
#define repr(i,a) for(i = a ; i >= 0 ; i--)
#define REP(i,a,b) for(i = a ; i <= b ; i++)
#define REPR(i,a,b) for(i = a ; i >= b ; i--)
#define mem(a,b)memset(a,b,sizeof(a))
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define sqr(x) (x)*(x)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back

#define endl '\n'

const long long INF = 20000000000;
const long long MOD = 1000000007;
const long long MAXN = 100005;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli f(lli x) {
    lli sumT = 0, sumF = 0;
    lli X = x;
    while (X) {
        sumT += X / 2;
        X /= 2;
    }
    X = x;
    while (X) {
        sumF += X / 5;
        X /= 5;
    }
    return min(sumF, sumT);
}
void solve() {
    lli n;
    scan(n);
    lli lo = 0, hi = INF, ans = -1;
    while (lo <= hi) {
        lli mid = (lo + hi) / 2;
        if (f(mid) == n) {
            ans = mid;
            hi = mid - 1;
        } else if (f(mid) < n){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    ans != -1 ? print(ans) : printS("impossible");
}

int main()
{
    //opt;
    lli t = 1;
    scan(t);
    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        solve();
    }
    return 0;
}