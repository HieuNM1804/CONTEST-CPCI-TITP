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
//#define int long long

using namespace std;

// Hieuobad qua non

void solve(){
    int n; cin >> n;
    int a[n + 1], mi[n + 1];   
    FOR(i, 1, n){
        cin >> a[i];
    }
    mi[1] = a[1];
    FOR(i, 2, n){
        mi[i] = min(mi[i - 1], a[i]);
    }
    int ans = 1;
    FOR(i, 2, n) if(a[i] < mi[i - 1]) ans++;
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}