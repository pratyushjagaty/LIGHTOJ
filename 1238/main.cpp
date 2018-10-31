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
const long long MAXN = 25;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli m, n;
plli a, b, c, home;
lli blossom[MAXN][MAXN], buttercup[MAXN][MAXN], bubbles[MAXN][MAXN];
char graph[MAXN][MAXN];

bool check(lli x, lli y) {
    return (x >= 1 and x <= m and y >= 1 and y <= n);
}
lli bfs1() {
    mem(blossom, 0);
    queue<pair<plli, lli>> q;
    q.push({{a.first, a.second}, 0});
    while (!q.empty()) {
        pair<plli, lli> front = q.front();
        q.pop();
        if (blossom[front.first.first][front.first.second] or !check(front.first.first, front.first.second)) continue;
        if (graph[front.first.first][front.first.second] == '#') continue;
        if (graph[front.first.first][front.first.second] == 'm') continue;
        blossom[front.first.first][front.first.second] = 1;
        if (front.first.first ==  home.first and front.first.second == home.second) return front.second;
        lli i;
        rep(i, 4) {
            q.push({{front.first.first + dx[i], front.first.second + dy[i]}, front.second + 1});
        }
    }
}


lli bfs2() {
    mem(buttercup, 0);
    queue<pair<plli, lli>> q;
    q.push({{b.first, b.second}, 0});
    while (!q.empty()) {
        pair<plli, lli> front = q.front();
        q.pop();
        if (buttercup[front.first.first][front.first.second] or !check(front.first.first, front.first.second)) continue;
        if (graph[front.first.first][front.first.second] == '#') continue;
        if (graph[front.first.first][front.first.second] == 'm') continue;
        buttercup[front.first.first][front.first.second] = 1;
        if (front.first.first ==  home.first and front.first.second == home.second) return front.second;
        lli i;
        rep(i, 4) {
            q.push({{front.first.first + dx[i], front.first.second + dy[i]}, front.second + 1});
        }
    }
}


lli bfs3() {
    mem(bubbles, 0);
    queue<pair<plli, lli>> q;
    q.push({{c.first, c.second}, 0});
    while (!q.empty()) {
        pair<plli, lli> front = q.front();
        q.pop();
        if (bubbles[front.first.first][front.first.second] or !check(front.first.first, front.first.second)) continue;
        if (graph[front.first.first][front.first.second] == '#') continue;
        if (graph[front.first.first][front.first.second] == 'm') continue;
        bubbles[front.first.first][front.first.second] = 1;
        if (front.first.first ==  home.first and front.first.second == home.second) return front.second;
        lli i;
        rep(i, 4) {
            q.push({{front.first.first + dx[i], front.first.second + dy[i]}, front.second + 1});
        }
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            graph[i][j] = s[j - 1];
            if (graph[i][j] == 'a') a.first = i, a.second = j;
            if (graph[i][j] == 'b') b.first = i, b.second = j;
            if (graph[i][j] == 'c') c.first = i, c.second = j;
            if (graph[i][j] == 'h') home.first = i, home.second = j;
        }
    }
    lli x = bfs1();
    lli y = bfs2();
    lli z = bfs3();
    cout << max(x, max(y, z)) << endl;
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