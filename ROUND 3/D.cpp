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
#define int long long

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    int a[n + 1], p[n + 1]; p[0] = 0;
    FOR(i, 1, n){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    int ans = 0;
    FOR(i, 1, n) p[i] %= k;
    map<int, int> m;
    m[0] = 1;
    FOR(i, 1, n){
        ans += m[p[i]];
        m[p[i]]++;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}