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
#define int long long

using namespace std;

const int N = 2e7 + 100;
int a[N + 5];
unordered_map<int, int> m;

void sang1(){
	FOR(i, 1, N) a[i] = i;
	int k = sqrt(N);
	for(int i = 2; i <= k; ++i){
		if(a[i] == i){
			for(int j = i * i; j <= N; j += i)
				if(a[j] == j) a[j] = i;
		}
	}
}

int p[N + 5];
vector<int> nt;

void sang2(){
	for(int i = 2; i <= sqrt(N); ++i){
		if(p[i] == 0){
			for(int j = i * i; j <= N; j += i) p[j] = 1;
		}
	}
	FOR(i, 2, N) if(p[i] == 0) nt.pb(i);
}

int b[1000006]; 
vector<int> v;

void solve(){
	int n; cin >> n;
	FOR(i, 1, n){
		cin >> b[i];
	}
	FOR(i, 1, n-1){
		if(!b[i] && !b[i + 1]){
			cout << -1 << endl;
			return;
		}
		if(b[i] == 1){
			cout << -1 << endl;
			return;
		}
		if(b[i] && b[i + 1] && __gcd(b[i], b[i + 1]) != 1){
			cout << -1 << endl;
			return;
		}
	}
	if(b[n] == 1){
	   	cout << -1 << endl;
		return;
	}
	if(b[1] == 0) v.pb(b[2]);
	if(b[n] == 0) v.pb(b[n - 1]);
	FOR(i, 2, n - 1){
		if(!b[i]){
			v.pb(b[i - 1]);
			v.pb(b[i + 1]);
		}
	}
	if(v.size() == 0){
		cout << 1 << endl;
		return;
	}
	for(int x : v){
		while(x != 1){
			int k = a[x];
			m[k] = 1;
			while(x % k == 0) x /= k;
		}
	}
	int ans;
	for(int x : nt){
		if(!m[x]){
			cout << x; 	
			break;
		}
	}
	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	sang1();
	sang2();
	while(T--) solve();
}
