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
#define T tuple<int, int, int>

using namespace std;

int n, m;
char a[1005][1005];
int d[1005][1005];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};


bool ok(int i, int j){
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

void solve(){
	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
	memset(d, 0x3f, sizeof d);
	multiset<T> q;
	FOR(i, 1, n){
		if(a[i][1] == '#'){
			q.insert({0, i, 1});
			d[i][1] = 0;
		}
		else{
			q.insert({1, i, 1});
			d[i][1] = 1;
		}
	}
	int ans = 1e9;
	while(q.size()){
		auto [w, i, j] = *q.begin(); 
		q.erase(q.begin());
		if(w > d[i][j]) continue;
		if(j == m){
			ans = min(ans, w);
			break;
		}
		FOR(k, 0, 7){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(ok(i1, j1)){
				if(a[i1][j1] == '#'){
					if(d[i1][j1] > w ){
						q.insert({w, i1, j1});
						d[i1][j1] = w;
					}
				}
				else{
					if(d[i1][j1] > w + 1){
						q.insert({w + 1, i1, j1});
						d[i1][j1] = w + 1;
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int TC = 1;
	//cin >> TC;
	while(TC--) solve();
}