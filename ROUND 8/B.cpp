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
	int a, b; cin >> a >> b;
	string f; cin >> f;
	int x = a / b;
	string s = to_string(x);
	a %= b;
	while(sz(s) <= (int)2e6){
		a *= 10;
		s += to_string(a / b);
		a %= b;
	}
	build(h1, f);
	build(h2, s);
	for(int i = 0; i + sz(f) - 1 < sz(s); ++i){
		if(get(h2, i, i + sz(f) - 1) == get(h1, 0, sz(f) - 1)){
			cout << i + 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}
