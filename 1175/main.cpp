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
const long long MAXN = 205;

lli dx[]={0,0,-1,1,-1,-1,1,1};
lli dy[]={1,-1,0,0,1,-1,-1,1};

lli r, c, fire[MAXN][MAXN], vis[MAXN][MAXN];
char g[MAXN][MAXN];

bool check(lli x, lli y, lli fireTime) {
    return (x >= 1 and x <= r and y >= 1 and y <= c and g[x][y] != '#' and fire[x][y] > fireTime + 1);
}

void bfs() {
    queue<pair<plli, lli>> q;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (g[i][j] == 'F') q.push({{i, j}, 0});
        }
    }

    while (!q.empty()) {
        pair<plli, lli> p = q.front();
        q.pop();
        lli X = p.first.first, Y = p.first.second, fireTime = p.second;
        if (!check(X, Y, fireTime)) continue;
        fire[X][Y] = fireTime + 1;
        for (int i = 0; i < 4; ++i) {
            q.push({{X + dx[i], Y + dy[i]}, fireTime + 1});
        }
    }
}

bool gotOut(lli x, lli y) {
    return (x > r or x < 1 or y < 1 or y > c);
}

void solve() {
    cin >> r >> c;
    plli jane = {-1, -1};
    for (int i = 1; i <= r; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= c; ++j) {
            g[i][j] = s[j - 1];
            if (g[i][j] == 'J') jane.first = i, jane.second = j;
        }
    }
    bfs();

    queue<pair<plli, lli>> q;
    q.push({{jane.first, jane.second}, 1});
    while (!q.empty()) {
        pair<plli, lli> p = q.front();
        q.pop();
        lli X = p.first.first, Y = p.first.second, ans = p.second;
        if (gotOut(X, Y)) {
            cout << ans - 1 << endl;
            return;
        }
        if (vis[X][Y]) continue;
        if (!check(X, Y, ans - 1)) continue;
        vis[X][Y] = 1;
        for (int i = 0; i < 4; ++i) {
            q.push({{X + dx[i], Y + dy[i]}, ans + 1});
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    opt;
    lli t = 1;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        for (int j = 0; j < MAXN ; ++j) {
            for (int k = 0; k < MAXN; ++k) {
                vis[j][k] = 0;
                fire[j][k] = INF;
            }
        }
        solve();
    }
    return 0;
}