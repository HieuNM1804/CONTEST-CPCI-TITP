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
//#define int long long

using namespace std;

int f[1000006];

void solve(){
	int n; cin >> n;
	int a[n + 1];
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0; 
	FOR(i, 1, n){
		int x = sqrt(a[i]), ok = 1;
		if(i + 1 <= n && a[i] == a[i + 1]){
			f[a[i]]++;
			continue;
		}
		FOR(j, 1, x){
			if(a[i] % j == 0){
				if(f[j] || f[a[i] / j]){
					ok = 0;
					break;
				}
			}
		}
		ans += ok;
		f[a[i]]++;
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
