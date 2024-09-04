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

void solve(){
    string s; 
    string mi = to_string(INT_MAX);
    string ma = to_string(LLONG_MAX);
    int ans = 0;
    while(cin >> s){
        int check_num = 0;
        for(char x : s){
            if(x < '0' || x > '9') check_num = 1;
        }
        if(check_num) continue;
        if(sz(s) < sz(mi)) continue;
        if(sz(s) == sz(mi) && s <= mi) continue;
        if(sz(s) > sz(ma)) continue;
        if(sz(s) == sz(ma) && s > ma) continue;
        ans += stoll(s);
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