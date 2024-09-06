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

bool lk(int n){
    while(n){
        if(n % 10 != 4 && n % 10 != 7) return 0;
        n /= 10;
    }
    return 1;
}

const int N = 1e5 + 100;
vector<int> adj[N];
int p[N], sz[N], dad, c;

void dfs(int u){
    c++;
    p[u] = dad;
    for(int v : adj[u]){
        if(!p[v]) dfs(v);
    }
}

void solve(){
    int n; cin >> n;
    FOR(i, 2, n){
        int x, y, w; cin >> x >> y >> w;
        if(!lk(w)){
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }
    FOR(i, 1, n){
        if(!p[i]){
            c = 0;
            dad++;
            dfs(i);
            sz[p[i]] = c;
        }
    }
    int ans = 0;
    FOR(i, 1, n){
        int ver = n - sz[p[i]];
        ans += ver * (ver - 1);
    }
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}