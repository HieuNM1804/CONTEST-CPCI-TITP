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
    int n, m, maxx = -1; cin >> n >> m;
    map<int, int> mp;
    FOR(i, 1, n){
        int x; cin >> x;
        mp[x]++;
        maxx = max(maxx, mp[x]);
    }
    int ans = -1, res = -1;
    for(auto it : mp){
        if(it.se == maxx) it.se = -1;
        if(it.se > res){
            res = it.se;
            ans = it.fi;
        }
    }
    if(ans == -1) cout << "NONE\n";
    else cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}