#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define sz(x) (int)(x).size()
#define bit(x, i) (((x) >> (i)) & (1))
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FOD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long

using namespace std;

int bs(int a[], int n, int x) {
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return 1;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
void solve() {
    int n, m, a, c;
    cin >> n >> m >> a >> c;
    int x[n + 10];
    cin >> x[0];
    for (int i = 1; i <= n; i++) x[i] = (a * x[i - 1] + c) % m;
    int kq = 0;
    for (int i = 1; i <= n; i++) kq += bs(x, n, x[i]);
    cout << kq;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}