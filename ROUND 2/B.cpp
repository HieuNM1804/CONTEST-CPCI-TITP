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
    int n; cin >> n;
    set<int> s;
    FOR(x, 0, 9){
        FOR(y, 0, 9){
            FOR(mask, 0, (1ll << 10ll) - 1){
                int num = 0;
                FOR(i, 0, 9){
                    if(bit(mask, i)) num = num * 10 + x;
                    else num = num * 10 + y;
                    if(num >= 1 && num <= n) s.insert(num);
                }
            }
        }
    }
    cout << sz(s) << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}