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

int c[30], d1[30], d2[30], ans, n;

void Try(int i){
    if(i > n){
        ans++;
        return;
    }
    for(int j = 1; j <= n; ++j){
        if(!c[j] && !d1[i - j + n] && !d2[i + j - 1]){
            c[j] = d1[i - j + n] = d2[i + j - 1] = 1;
            Try(i + 1);
            c[j] = d1[i - j + n] = d2[i + j - 1] = 0;
        }
    }
}

void solve(){
    cin >> n;
    Try(1);
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}