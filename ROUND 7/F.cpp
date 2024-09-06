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

int C[105][105];

int Pow(int n, int k){
	if(k == 0) return 1;
	int x = Pow(n, k / 2) % MOD;
	if(k % 2) return (((x % MOD) * (x % MOD) % MOD) * n % MOD) % MOD;
	else return (x % MOD) * (x % MOD) % MOD;
}


void nCk(){
	for(int i = 0; i <= 100; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; ++j){
			C[i][j] = (C[i - 1][j] % MOD) + (C[i - 1][j - 1] % MOD) % MOD;
			C[i][j] %= MOD;
		}
	}
}


void solve(){
	int n, k; cin >> n >> k;
	int a[n + 1];
	int le = 0, chan = 0;
	FOR(i, 1, n){
		cin >> a[i];
		if(a[i] % 2 == 0) chan++;
		else le++;
	}
	int ans = 0;
	if(k == 0){
		if(le == 0){
			cout << Pow(2, chan) << endl;
		}
		else if(chan == 0){
			for(int i = 0; i <= le; i += 2) ans += C[le][i];
			cout << ans % MOD << endl;
		}
		else{
			for(int i = 0; i <= le; i += 2) ans += C[le][i];
			ans %= MOD;
			ans *= Pow(2, chan);
			cout << ans % MOD << endl;
		}
	}
	else{
		int ans = 0;
		for(int i = 1; i <= le; i += 2){
			ans += C[le][i];
			ans %= MOD;
		}
		if(chan) ans *= Pow(2, chan);
		cout << ans % MOD << endl;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	nCk();
	while(T--) solve();
	return 0;
}
