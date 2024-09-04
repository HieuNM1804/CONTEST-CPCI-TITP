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
#define int long long

using namespace std;

// Hieuobad qua non

void solve(){
    int n; cin >> n;
    map<string, int> m;
    FOR(i, 0, n - 1){
        string s; cin >>s;
        sort(s.begin(), s.end());
        m[s]++;
    }
    int ans = 0;
    for(auto it : m){
        if(it.se >= 2) ans += (it.se) * (it.se - 1) / 2;
    }
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}