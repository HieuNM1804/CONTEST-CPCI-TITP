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

const int N = 3e5 + 100;
int st[N * 4];

void update(int id, int l, int r, int pos, int val){
	if(l > pos || r < pos) return;
	if(l == r && r == pos){
		st[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v){
	if(r < u || l > v) return INT_MAX;
	if(u <= l && r <= v) return st[id];
	int mid = (l + r) / 2;
	return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve(){
	int n; cin >> n;
	int a[n + 1], b[n + 1];
	FOR(i, 1, n){
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	FOR(i, 1, n) cin >> b[i];
	FOR(i, 1, n){
		int l = 1, r = n, id = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(get(1, 1, n, 1, mid) <= b[i]){
				id = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if(id == -1 || a[id] != b[i]){
			cout << "NO\n"; 
			return;
		}
		update(1, 1, n, id, 2e9);
	}
	cout << "YES\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}
