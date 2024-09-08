#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) s.size()
#define ii pair<int, int>
#define bit(x,i) (( (x) >> (i)) & (1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
//#define int long long
 
using namespace std;
 
const int N = 5e5 + 100;
int st[N * 4], a[N * 4];
vector<ii> qr[N];
 
void update(int id, int l, int r, int pos, int val){
	if(l > pos || r < pos) return;
	if(l == r && r == pos){
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}
 
int get(int id, int l, int r, int u, int v){
	if(r < u || l > v) return 0;
	if(u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return get(id * 2, l, mid, u, v) 
		+ get(id * 2 + 1, mid + 1, r, u, v);
}
 
void solve(){
	int n, q; cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, q){
		int x, y;
		cin >> x >> y;
		qr[x].pb({y, i});
	}
	vector<int> ans(q + 1, -1);
	map<int, int> id;
	FOD(i, n, 1){
		if(id.count(a[i])) update(1, 1, n, id[a[i]], 0);
		id[a[i]] = i;
		update(1, 1, n, id[a[i]], 1);
		for(auto it : qr[i]){
			ans[it.se] = get(1, 1, n, i, it.fi);
		}
	}
	FOR(i, 1, q) cout << ans[i] << endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
}
