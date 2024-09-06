#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) s.size()
#define ii pair<int, int>
#define bit(x,i) (( (x) >> (i)) & (1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long

using namespace std;

string s; 
int n;

bool ok(int step, int x1, int y1, int x2, int y2, int ox, int oy){
	int k = step / n;
	int q = step % n;
	FOR(i, 1, q){
		if(s[i - 1] == 'L') x1--;
		else if(s[i - 1] == 'R') x1++;
		else if(s[i - 1] == 'U') y1++;
		else y1--;
	}
	x1 += ox * k;
	y1 += oy * k;
	return (abs(x1 - x2) + abs(y1 - y2)) <= step;
}

void solve(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
	int ox = 0, oy = 0;
	for(char x : s){
		if(x == 'L') ox--;
		else if(x == 'R') ox++;
		else if(x == 'U') oy++;
		else oy--;
	}
	int l = 1, r = 1e12, ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(ok(mid, x1, y1, x2, y2, ox, oy)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
	return 0;
}
