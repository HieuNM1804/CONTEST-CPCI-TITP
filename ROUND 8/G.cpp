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
#define int long long

using namespace std;

const int base = 311, m = 1e9 + 7, N = 2e6 + 100;
int Pow[N], h1[N], h2[N];

void CalcPow(){
	Pow[0] = 1;
	for(int i = 1; i < N; ++i) Pow[i] = (base * (Pow[i - 1] % m)) % m;
}

void build(int h[], string s){
	h[0] = s[0];
	for(int i = 1; i < s.size(); ++i){
		h[i] = (base * h[i - 1] % m + s[i]) % m;
	}
}

int get(int h[], int l, int r){
	if(l == 0) return h[r];
	else return (h[r] - h[l - 1] * Pow[r - l + 1] % m + m) % m;
}

void solve(){
	CalcPow();
	string a, b; cin >> a >> b;
	build(h1, a);
    build(h2, b);
    vector<int> ans;
    FOR(i, 0, sz(a) - sz(b)){
        if(get(h1, i, i + sz(b) - 1) == h2[sz(b) - 1]){
            ans.pb(i + 1);
        }
    }
    for(auto x: ans) cout << x << ' ';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}
