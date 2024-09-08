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

const int N = 1e5 + 100;
int p[N], wei[N], sz[N];

int find(int u){
    if(u == p[u]) return u;
    int v = find(p[u]);
    wei[u] += wei[p[u]];
    return p[u] = v;
}

void add(int u, int v, int w) {
    int pU = find(u);
    int pV = find(v);
    if (pU == pV) return;
    if (sz[pU] < sz[pV]) { 
        swap(pU, pV); 
        swap(u, v);
        w = -w; 
    }
    p[pV] = pU;
    sz[pU] += sz[pV];
    wei[pV] = wei[u] - wei[v] + w; 
}

void solve(){
    int n, q; cin >> n >> q;
    FOR(i, 1, n){
        p[i] = i;
        sz[i] = 1;
        wei[i] = 0;
    }
    while(q--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == '!'){
            int w; cin >> w;
            add(a, b, w);
        }
        else{
            if(find(a) != find(b)) cout << "UNKNOWN" << endl;
            else cout << wei[b] - wei[a] << endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}