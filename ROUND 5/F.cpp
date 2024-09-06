#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define sz(x) (int)(x).size()
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
//#define int long long

using namespace std;


struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point circum(Point a, Point b, Point c) {
    double D = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    double x = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / D;
    double y = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / D;
    return {x, y};
}

bool check(int n, int k, vector<Point>pts) {
    FOR(i, 0, n - 1) {
        FOR(j, i + 1, n - 1) {
            FOR(l, j + 1, n - 1) {
                Point A = pts[i], B = pts[j], C = pts[l];
                Point O = circum(A, B, C);
                double r = distance(O, A); 
                int cnt = 0;
                for (int m = 0; m < n; m++) {
                    if (m == i || m == j || m == l) continue;
                    double d = distance(O, pts[m]);
                    if (d < r) cnt++;
                }
                if (cnt == k) return true;
            }
        }
    }
    return false;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<Point> pts(n);
    FOR(i, 0, n - 1) cin >> pts[i].x >> pts[i].y;
    if (check(n, k, pts)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}