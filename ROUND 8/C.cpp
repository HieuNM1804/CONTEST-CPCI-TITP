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

int gt[20];

void solve(){
	int n, op; cin >> n >> op;
	int a[n + 1];
	map<int, int> m;
	if(op == 2){
		int k; cin >> k;	
		FOR(i, 1, n){
			FOR(j, 1, n){
				if(!m[j]){
					if(k > gt[n - i]){
						k -= gt[n - i];
					}
					else{
						a[i] = j;
						m[a[i]] = 1;
						break;
					}
				}
			}
		}
		FOR(i, 1, n) cout << a[i] << ' ';
		cout << endl;
	}
	else{
		FOR(i, 1, n) cin >> a[i];
		int ans = 1;
		map<int, int> m;
		FOR(i, 1, n){
			FOR(j, 1, a[i] - 1){
				if(!m[j]){
					ans += gt[n - i];
				}
			}
			m[a[i]] = 1;
		}
		cout << ans << endl;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	gt[0] = gt[1] = 1;
	FOR(i, 2, 15) gt[i] = gt[i - 1] * i;
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}
