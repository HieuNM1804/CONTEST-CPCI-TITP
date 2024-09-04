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
#define int long long

using namespace std;

char a[105][105];
int n, m, s, e, x, y;
int f[105][105][4], used[105][105][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool ok(int i, int j){
	return (i >= 1 && j >= 1 && i <= n && j <= m && (a[i][j] == '.' || a[i][j] == 'S' || a[i][j] == 'G'));
}

int cook(int i, int j){
	return (a[i][j] == '#' || a[i][j] == '>' || a[i][j] == '<'|| a[i][j] == '^' || a[i][j] == 'v');
}

void solve(){
	memset(used, 0, sizeof used);
	memset(f, 0, sizeof f);
	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
	FOR(i, 1, n){
		FOR(j, 1, m){
			if(a[i][j] == 'S'){
				s = i;
				e = j;
			}
			else if(a[i][j] == 'G'){
				x = i;
				y = j;
			}
			else if(a[i][j] == '^'){
				FOR(k, j + 1 , m){
					if(cook(i, k)) break;
					f[i][k][0] = 1;
				}
				FOR(k, i + 1, n){
					if(cook(k, j)) break;
					f[k][j][1] = 1;
				}
				FOD(k, j - 1 , 1){
					if(cook(i, k)) break;
					f[i][k][2] = 1;
				}
				FOD(k, i -1 , 1){
					if(cook(k, j)) break;
					f[k][j][3] = 1;
				}
			}
			else if(a[i][j] == '>'){
				FOR(k, i + 1 , n){
					if(cook(k, j)) break;
					f[k][j][0] = 1;
				}
				FOD(k, j - 1 , 1){
					if(cook(i, k)) break;
					f[i][k][1] = 1;
				}
				FOD(k, i -1 , 1){
					if(cook(k, j)) break;
					f[k][j][2] = 1;
				}	
				FOR(k, j + 1 , m){
					if(cook(i, k)) break;
					f[i][k][3] = 1;
				}			
			}
			else if(a[i][j] == 'v'){
				FOD(k, j -1, 1){
					if(cook(i, k)) break;
					f[i][k][0] = 1;
				}
				FOD(k, i -1, 1){
					if(cook(k, j)) break;
					f[k][j][1] = 1;
				}	
				FOR(k, j + 1 , m){
					if(cook(i, k)) break;
					f[i][k][2] = 1;
				}
				FOR(k, i +1, n){
					if(cook(k, j)) break;
					f[k][j][3] = 1;
				}			
			}
			else if(a[i][j] == '<'){
				FOD(k, i - 1 , 1){
					if(cook(k, j)) break;
					f[k][j][0] = 1;
				}	
				FOR(k, j + 1 , m){
					if(cook(i, k)) break;
					f[i][k][1] = 1;
				}
				FOR(k, i + 1 , n){
					if(cook(k, j)) break;
					f[k][j][2] = 1;
				}
				FOD(k, j - 1 , 1){
					if(cook(i, k)) break;
					f[i][k][3] = 1;
				}				
			}
		}
	}
	queue<T> q;
	q.push({s, e, -1});
	used[s][e][3] = 1;
	while(q.size()){
		auto [i, j, step] = q.front(); q.pop();
		if(i == x && j == y){
			cout << step + 1 << endl;
			return;
		}
		FOR(k, 0, 3){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(ok(i1, j1) && !f[i1][j1][(step + 1) % 4] && !used[i1][j1][(step + 1) % 4]){
				used[i1][j1][(step + 1) % 4] = 1;
				q.push({i1, j1, step + 1});
			}
		}
	}
	cout << "impossible\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int TC = 1;
	cin >> TC;
	FOR(_, 1, TC){
		solve();
	}
	return 0;
}
