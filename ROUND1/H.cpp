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

const int N = 1e6 + 10;
int f[N];

void solve(){
    memset(f, 0, sizeof f);
    int n; cin >> n;
    FOR(i, 1, n){
        int x; cin >> x;
        f[x]++;
    }
    FOD(i, 1000000, 1){
        int c = 0;
        for(int j = i; j < N; j += i){
            c += f[j];
            if(c >= 2){
                cout << i << endl;
                return;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}