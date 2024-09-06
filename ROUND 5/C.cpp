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
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];
    double p, ans = 0;
    if (k == 1) {
    	sort(a + 1, a + n + 1);
        if(n % 2 == 1) p = a[n / 2 + 1]; 
        else p = (a[n / 2] + a[n / 2 + 1]) / 2.0; 
        FOR(i, 1, n) ans += abs(a[i] - p);
    } 
	else {
        double sum  = accumulate(a + 1, a + n + 1, 0.0);
        p = sum / n; 
        FOR(i, 1, n) ans += (a[i] - p) * (a[i] - p);
    }
    cout << fixed << setprecision(2) << ans;    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}