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
	int n; cin >> n;
	string s; cin >> s;
	int cong = 0, tru = 0;
	for(char x : s){
		if(x == '+') cong++;
		else tru++;
	}
	int q; cin >> q;
	while(q--){
		int a, b; cin >> a >> b;
		if(a == b){
			if(cong == tru) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			int dis = (cong - tru) * b;
			if(abs(dis) % abs(a - b) == 0){
				int k = -dis / (a - b);
				if(k >= -tru && k <= cong) cout << "YES\n";
				else cout << "NO\n";
			}
			else cout << "NO\n";
		}
	}
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}