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
#define T tuple<int, int, int>
#define int long long

using namespace std;


int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char a[1005][1005];
vector<ii> apple, door;
int used[1005][1005];
int dis[10][1005][1005];

// dis[i][j][k] = khoảng cách ngắn nhất cây táo thứ i tới ô (j, k)

bool ok(int i, int j){
	return (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] != '#');
}

void BFS(int x, int y, int id){
    queue<T> q;
    q.push({x, y, 0});
    memset(used, 0, sizeof used);
    used[x][y] = 1;
    while(q.size()){
        auto [i, j, step] = q.front();
        dis[id][i][j] = step;
        q.pop();
        FOR(k, 0, 3){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(ok(i1, j1) && !used[i1][j1]){
                if(a[i1][j1] == 'D'){
                    for(auto [i2, j2] : door){
                        q.push({i2, j2, step + 1});
                        used[i2][j2] = 1;
                    }
                }
                else{
                    q.push({i1, j1, step + 1});
                    used[i1][j1] = 1;
                }
            }
        }
    }
}

void solve(){
    FOR(i, 0, 9){
        FOR(j, 1, 1000){
            FOR(k, 1, 1000){
                dis[i][j][k] = 1e18;
            }
        }
    }
	cin >> n >> m;
	FOR(i, 1, n) {
		FOR(j, 1, m){
			cin >> a[i][j];
			if(a[i][j] == 'A'){
				apple.pb({i, j});
			}
            if(a[i][j] == 'D'){
                door.pb({i, j});
            }
		}
	}
	int sz = apple.size();
    FOR(i, 0, sz - 1){
        BFS(apple[i].fi, apple[i].se, i);
    }
	int ans = 1e18;
	vector<int> hv(sz);
	FOR(i, 0, sz - 1) hv[i] = i;
	do{
		int a[10];
		FOR(i, 0, sz - 1) a[hv[i]] = i;
		int s = 0;
		FOR(i, 0, sz - 2){
            s += dis[a[i]][apple[a[i + 1]].fi][apple[a[i + 1]].se];
            if(s >= 1e18 || s < 0){ // tràn số ( < 0) hoặc k có đường đi(> 1e18)
                cout << -1;
                return;
            }
        }
		ans = min(ans, s);
	} while(next_permutation(hv.begin(), hv.end()));
    cout << ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int CASE = 1;
	//cin >> CASE;
	while(CASE--) solve();
}