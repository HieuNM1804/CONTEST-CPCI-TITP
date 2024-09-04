#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define ii pair<int, int>
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
//#define int long long

using namespace std;

void solve(){
    string s; cin >> s;
    int len = sz(s);
    s = "$" + s;
    int n; cin >> n;
    int p[n + 5] = {};
    FOR(i, 1, n){
        int x; cin >> x;
        p[x]++;
        p[len - x + 2]--;
    }
    FOR(i, 1, len) p[i] += p[i - 1];
    FOR(i, 1, len){
        if(p[i] % 2) cout << s[len - i + 1];
        else cout << s[i];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}