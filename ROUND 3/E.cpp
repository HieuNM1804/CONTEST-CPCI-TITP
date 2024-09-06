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

void solve(){
    int n; cin >> n;
    int a[n + 1];
    vector<int> l(n + 1, -1), r(n + 2, INT_MAX);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) l[i] = max(l[i - 1], a[i]);
    FOD(i, n, 1) r[i] = min(r[i + 1], a[i]);
    vector<int> ans;
    FOR(i, 1, n) if(a[i] > l[i - 1] && a[i] < r[i + 1]) ans.pb(a[i]);
    cout << sz(ans) << ' ';
    for(int i = 0; i < min(100, sz(ans)); i++) cout << ans[i] << ' ';
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}