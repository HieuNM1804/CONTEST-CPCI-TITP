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

int ok(int a, int b, int c){
    return a + b > c;
}

void solve(){
    int n; cin >> n;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];
    multiset<int> s;
    int ans = 0, r = 1;
    FOR(i, 1, n - 2){
        while(sz(s) < 3 && r <= n){
            s.insert(a[r]);
            r++;
        }
        bool f = 0;
        while(1){
            auto x = *s.begin();
            auto y = *next(s.begin());
            auto z = *s.rbegin();
            if(ok(x, y, z)){
                f = 1;
                if(r <= n){
                    s.insert(a[r]);
                    r++;
                }
                else break;
            }
            else{
                if(f) s.erase(s.find(a[--r]));
                break;
            }
        }
        if(f) ans = max(ans, r - i);
        s.erase(s.find(a[i]));
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