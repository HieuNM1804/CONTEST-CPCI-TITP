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

struct Square{
	int x, y, z, t;
};

int a[255][255], n;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<Square> v;
vector<int> X, Y;

bool ok(int i, int j){
	return (i >= 1 && j >= 1 && i <= 250 && j <= 250 && !a[i][j]);
}

void Compress(){
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for(auto& [x, y, z, t] : v){
		x = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
		z = lower_bound(X.begin(), X.end(), z) - X.begin() + 1;
		y = lower_bound(Y.begin(), Y.end(), y) - Y.begin() + 1;
		t = lower_bound(Y.begin(), Y.end(), t) - Y.begin() + 1;
	}
	for(auto& [x, y, z, t] : v){
		x *= 2;
		y *= 2;
		z *= 2;
		t *= 2;
	}
}

void dfs(int u, int v){
	a[u][v] = 1;
	stack<ii> st;
	st.push({u, v});
	while(st.size()){
		auto [i, j] = st.top(); st.pop();
		a[i][j] = 1;
		FOR(k, 0, 7){
			int i1 = i + dx[k];
			int j1 = j + dy[k];	
			if(ok(i1, j1)) st.push({i1, j1});
		}			
	}
}

void solve(){
	cin >> n;
	v.clear();
	X.clear();
	Y.clear();
	memset(a, 0, sizeof a);
	FOR(i, 1, n){
		int x, y, z, t; cin >> x >> y >> z >> t;
		v.pb({x, y, z, t});
		X.pb(x); X.pb(z);
		Y.pb(y); Y.pb(t);
	}
	Compress();
	for(auto [x, y, z, t] : v){
		FOR(i, x, z) a[y][i] = 1;
		FOD(i, y, t) a[i][z] = 1;
		FOD(i, z, x) a[t][i] = 1;
		FOR(i, t, y) a[i][x] = 1;
	}
	int ans = 0;
	FOR(i, 1, 250){
		FOR(j, 1, 250){
			if(!a[i][j]){
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}