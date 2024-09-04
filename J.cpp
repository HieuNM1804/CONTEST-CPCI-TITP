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
	int n; cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	vector<int> l(n + 1, 0), r(n + 1, n + 1);
	stack<int> st;
	FOR(i, 1, n){
		while(!st.empty() && a[i] <= a[st.top()])
			st.pop();
		if(st.empty()) l[i] = 0;
		else l[i] = st.top();
		st.push(i);	
	}
	while(!st.empty())
	st.pop();
	FOD(i, n, 1){
		while(!st.empty() && a[i] <= a[st.top()])
			st.pop();
		if(st.empty()) r[i] = n + 1;
		else r[i] = st.top();
		st.push(i);
	}
	vector<int> ans(n + 1, 0);
	FOR(i, 1, n){
		int len = (r[i] - 1) - (l[i] + 1) + 1;
		ans[len] = max(ans[len], a[i]);
	}
	FOD(i, n - 1, 1)
		ans[i] = max(ans[i], ans[i + 1]);
	FOR(i, 1, n)
		cout << ans[i] << ' ';
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--) solve();
}

