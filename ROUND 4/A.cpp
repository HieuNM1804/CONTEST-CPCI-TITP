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

struct hcn{
	int x, y;
};

void solve(){
	hcn a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if(a.x < a.y) swap(a.x, a.y);
	if(b.x < b.y) swap(b.x, b.y);
	if(c.x < c.y) swap(c.x, c.y);
	if(a.x == b.x && b.x == c.x){
		if(a.y + b.y + c.y == a.x){
			cout << a.x;
			return;
		}
	}
	if(a.x == b.x){
		if(a.y + b.y == c.x && c.y + a.x == c.x){
			cout << c.x;
			return;
		}
	}
	if(a.x == c.x){
		swap(b, c);
		if(a.y + b.y == c.x && c.y + a.x == c.x){
			cout << c.x;
			return;
		}
	}
	if(b.x == c.x){
		swap(a, c);
		if(a.y + b.y == c.x && c.y + a.x == c.x){
			cout << c.x;
			return;
		}
	}
	cout << 0;
}


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}