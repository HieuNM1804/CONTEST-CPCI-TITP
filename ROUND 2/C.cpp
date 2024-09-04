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
    int n; cin >> n; n *= 2;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    FOR(i, 1, n){
        cin >> a[i];
        b[i] = a[i];
        c[i] = i;
    }
    if(a == c || b == c){
        cout << 0;
        return;
    }
    for(int step = 1; step <= n; ++step){
        if(step % 2){
            for(int i = 1; i <= n; i += 2) swap(a[i], a[i + 1]);
            for(int i = 1; i <= n / 2; i++) swap(b[i], b[i + n / 2]);
        }
        else{
            for(int i = 1; i <= n; i += 2) swap(b[i], b[i + 1]);
            for(int i = 1; i <= n / 2; i++) swap(a[i], a[i + n / 2]);
        }
        if(a == c || b == c){
            cout << step;
            return;
        }
    }
    cout << -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}