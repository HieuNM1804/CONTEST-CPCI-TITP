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

int a[20];
int n, s;

int calc(){
    int res = 0;
    vector<int> l(n + 1), r(n + 1);
    l[1] = a[1];
    for(int i = 2; i <= n; ++i){
        l[i] = max(l[i - 1], a[i]);
    }
    r[n] = a[n];
    for(int i = n - 1; i >= 1; --i){
        r[i] = max(r[i + 1], a[i]);
    }
    for(int i = 2; i < n; ++i){
        int add = min(l[i], r[i]) - a[i];
        res += max(0ll, add);
    }
    return res;
}

void solve(){
	cin >> n >> s;
	FOR(i, 1, n) cin >> a[i];
	int ans = 0;
	FOR(i, 1, n - 1){
		FOR(j, 1, n){
			FOR(k, 0, s){
				a[i] += k;
				a[j] += (s - k);
				ans = max(ans, calc());
				a[i] -= k;
				a[j] -= (s - k);
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}