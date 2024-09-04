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
    int n; cin >> n;
    int a[n];
    FOR(i, 0, n - 1) cin >> a[i];
    map<int, vector<int>> m;
    FOR(mask, 0, (1 << n) - 1){
        int sum = 0;
        FOR(i, 0, n - 1){
            if(bit(mask, i)) sum += a[i];
        }
        m[sum].pb(mask);
    }
    set<int> ans;
    for(auto it : m){
        vector<int> v = it.se;
        FOR(i, 0, sz(v) - 1){
            FOR(j, i + 1, sz(v) - 1){
                if((v[i] & v[j]) == 0){
                    ans.insert(it.fi);
                    break;
                }
            }
        }
    }
    cout << sz(ans) << endl;
    for(int x : ans) cout << x << " ";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}