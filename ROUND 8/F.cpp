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

int gt[200005];

int Pow(int n, int k){
	if(k == 0) return 1;
	int x = Pow(n, k / 2) % MOD;
	if(k % 2) return (((x % MOD) * (x % MOD) % MOD) * n % MOD) % MOD;
	else return (x % MOD) * (x % MOD) % MOD;
}

int calc(int a, int b) {
    if (b > a || b < 0) return 0;
    int fact_a = gt[a];
    int fact_b = gt[b];
    int fact_c = gt[a - b];
    int inv_fact_b = Pow(fact_b, MOD - 2);
    int inv_fact_c = Pow(fact_c, MOD - 2);
    return (((fact_a % MOD) * (inv_fact_b % MOD) % MOD) * (inv_fact_c % MOD)) % MOD;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<ii> a;
    FOR(i, 0, k - 1){
        int x, y; cin >> x >> y;
        a.pb({x, y});
    }
    FOR(i, 0, k - 1){
        if(a[i].fi == 1 && a[i].se == 1){
            cout << 0 << endl;
            return;
        }
    }
    a.pb({n, m});  
    sort(a.begin(), a.end());
    int ans = calc(n + m - 2, n - 1);
    int dp[k + 5] = {};
    FOR(i, 0, sz(a) - 1){
        dp[i] = calc(a[i].fi + a[i].se - 2, a[i].fi - 1) % MOD;
        FOR(j, 0, i - 1){
            if(a[j].fi <= a[i].fi && a[j].se <= a[i].se){
                dp[i] = (dp[i] - dp[j] * calc(a[i].fi - a[j].fi + a[i].se - a[j].se, a[i].fi - a[j].fi) % MOD + MOD) % MOD;
            }
        }
    }
    cout << dp[sz(a) - 1] % MOD << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    gt[0] = gt[1] = 1;
    FOR(i, 2, 200000){
        gt[i] = gt[i - 1] * i % MOD;
        gt[i] %= MOD;
    }
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}