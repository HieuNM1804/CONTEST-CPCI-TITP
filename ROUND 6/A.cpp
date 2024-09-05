#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define ii pair<int, int>
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long

using namespace std;

vector<int> dp(5009);

void solve(){
	int n = 5005;
	FOR(i, 1, n) dp[i] = i;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n / i; ++j){
			dp[i * j] = min(dp[i * j], dp[i] + dp[j] + 2);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j < i; ++j){
			dp[i] = min(dp[i], dp[i - j] + 2 + dp[j]);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
	int T = 1;
	cin >> T;
	while(T--) {
        int x; cin >> x;
        cout << dp[x] << endl;
    }
}
