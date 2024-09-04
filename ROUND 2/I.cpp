#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define ii pair<int, int>
#define pb push_back
#define bit(x,i) ((x>>i)&1)
//#define int long long

using namespace std;

const int N = 2e5 + 100;
vector<int> adj[N], a(N);
int used[N], p[N], sz[N];

int find(int u){
	if(u == p[u]) return u;
	p[u] = find(p[u]);
	return p[u];
}

void add(int u, int v){
	u = find(u);
	v = find(v);
	if(sz[u] < sz[v]) swap(u, v);
	p[v] = u;
	sz[u] += sz[v];
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		p[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i <= m; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<string> ans;
	int cnt = 0;
	for(int i = n-1; i >= 0; --i){
		int u = a[i];
		used[u] = 1;
		cnt++;
		for(int v : adj[u]){
			if(used[v]){
				if(find(u) != find(v)){
					add(u, v);
					cnt--;
				}
			}
		}
		if(cnt == 1) ans.pb("YES\n");
		else ans.pb("NO\n");
	}
	for(int i = n-1; i >= 0; --i) cout << ans[i];
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();
}
 
