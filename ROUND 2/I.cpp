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
//#define int long long

using namespace std;

vector<int> adj[200005];
int p[200005], sz[200005], used[200005];

int find(int u){
    if(u == p[u]) return u;
    return p[u] = find(p[u]);
}

void add(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
}

void solve(){
    int n, m; cin >> n >> m;
    FOR(i, 1, n){
        p[i] = i;
        sz[i] = 1;
    }
    FOR(i, 1, m){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> ver;
    FOR(i, 1, n){
        int x; cin >> x;
        ver.pb(x);
    }
    reverse(ver.begin(), ver.end());
    int c = 0;
    vector<string> ans;
    for(int u : ver){
        c++;
        used[u] = 1;
        for(int v : adj[u]){
            if(used[v] && find(u) != find(v)){
                add(u, v);
                c--;
            }
        }
        if(c == 1) ans.pb("YES");
        else ans.pb("NO");
    }
    reverse(ans.begin(), ans.end());
    for(string s : ans) cout << s << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
