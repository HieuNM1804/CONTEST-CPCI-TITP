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

void solve(){
	int n; cin >> n;
	int a0 = 0, a1 = 1;
	for(int i = 2; i <= 5e7; ++i){
		int x = (a0 + a1) % n;
		if(x == 1 && a1 == 0){
			cout << i - 1 << endl;
			return;
		}
		a0 = a1;
		a1 = x;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
}

