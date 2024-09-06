#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) s.size()
#define ii pair<int, int>
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long

using namespace std;

void solve(){
	int n; cin >> n;
	int a[n + 1], b[n + 1], c[n + 1];
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n) c[i] = a[i] - b[i];
	sort(c + 1, c + n + 1, greater<int>());
	int ans = 0, s = 0;
	FOR(i, 1, n){
		if(s + c[i] < 0) break;
		ans++;
		s += c[i];
	}
	cout << ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
}
