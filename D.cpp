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

void solve(){
    int n, s, e, u, d; 
    cin >> n >> s >> e >> u >> d;
    int used[n + 1] = {};
    queue<ii> q;
    q.push({s, 0});
    used[s] = 1;
    while(q.size()){
        auto [i, step] = q.front(); q.pop();
        if(i == e){
            cout << step;
            return;
        }
        if(i + u <= n && !used[u + i]){
            q.push({i + u, step + 1});
            used[i + u] = 1;
        }
        if(i - d >= 1 && !used[i - d]){
            q.push({i - d, step + 1});
            used[i - d] = 1;
        }
    }
    cout << -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}