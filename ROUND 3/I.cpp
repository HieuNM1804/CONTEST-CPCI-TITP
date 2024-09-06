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

int prime(int n){
    if(n < 2) return 0;
    FOR(i, 2, sqrt(n)){
        if(n % i == 0) return 0;
    }
    return 1;
}

void solve(){
    int n; cin >> n;
    int ans = 0;
    FOR(i, 2, n / 2){
        if(prime(i) && prime(n - i)) ans++;
    }
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}