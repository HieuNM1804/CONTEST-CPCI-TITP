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
    int n, k; cin >> n >> k;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    multiset<int> s;
    FOR(i, 1, k - 1) s.insert(a[i]);
    int ans = 2e9;
    FOR(i, k, n){
        s.insert(a[i]);
        ans = min(ans, *s.rbegin() - *s.begin());
        s.erase(s.find(a[i - k + 1]));
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