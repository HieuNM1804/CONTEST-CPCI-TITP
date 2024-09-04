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

int sz[100];

//Hieusobad qua non

void solve(){
	sz[0] = 3;
	FOR(i, 1, 50) sz[i] = sz[i - 1] * 2 + i + 3;
	int k; cin >> k;
	int n = lower_bound(sz, sz + 50, k) - sz;
	string s = "acc";
	while(1){
		if(n == 0){
			cout << s[k - 1] << endl;
			return;
		}
		else if(k > sz[n - 1] + n + 3){
			k -= sz[n - 1] + n + 3;
			n--;
		}
		else if(k > sz[n - 1]){
			if(k - sz[n - 1] == 1) cout << 'a' << endl;
			else cout << 'c' << endl;
			return;
		}
		else n--;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}

