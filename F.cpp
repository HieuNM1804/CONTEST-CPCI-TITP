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
#define int long long

using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int> (5));
    FOR(i, 0, n - 1){
        FOR(j, 0, 4) cin >> v[i][j];
        sort(v[i].begin(), v[i].end());
    }
    map<vector<int>, int> m;
    FOR(i, 0, n - 1){
        FOR(mask, 1, (1 << 5) - 1){
            vector<int> x;
            FOR(j, 0, 4){
                if(bit(mask, j)) x.pb(v[i][j]);
            }
            m[x]++;
        }
    }
    long long cnt = 0;
    for(auto it : m){
        int x = sz(it.fi);
        if(x % 2) cnt += it.se * (it.se - 1) / 2;
        else cnt -= it.se * (it.se - 1) / 2;
    }
    cout << 1ll * n * (n - 1) / 2 - cnt << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}