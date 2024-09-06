#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) s.size()
#define ii pair<int, int>
#define bit(x,i) (((x)>>(i))&(1))
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FOD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define MOD 1000000007
#define int long long

using namespace std;

struct HCN{
	int x, y, z;
};

struct HT{
	int r, h;	
};

vector<HCN> a;
vector<HT> b;
int F1[305], F2[105];

bool a_on_b(HCN a, HCN b){
    return (a.x < b.x && a.y < b.y) || (a.x < b.y && a.y < b.x);
}

void solve(){
	a.clear();
	b.clear();
	memset(F1, 0, sizeof F1);
	memset(F2, 0, sizeof F2);
	int n, m; cin >> n >> m;
	FOR(i, 1, n){
		int X, Y, Z; cin >> X >> Y >> Z;
		a.pb({X, Y, Z});
		a.pb({X, Z, Y});
		a.pb({Y, Z, X});
	}
	n *= 3;
	FOR(i, 1, m){
		int r, h; cin >> r >> h;
		b.pb({r, h});
	}
	sort(a.begin(), a.end(), [](HCN h1, HCN h2){
		return h1.x * h1.y > h2.x * h2.y;
	});
	sort(b.begin(), b.end(), [](HT h1, HT h2){
		return h1.r > h2.r;
	});
	int i1 = 0, i2 = 0;
	while(i1 < n && i2 < m){
		if(a[i1].x * a[i1].x + a[i1].y * a[i1].y > 4 * b[i2].r * b[i2].r){	
			FOR(i, 0, i1 - 1){
				if(a_on_b(a[i1], a[i])){
					F1[i1] = max(F1[i1], F1[i]);
				}
			}
			FOR(i, 0, m - 1){
				if(a[i1].x * a[i1].x + a[i1].y * a[i1].y < 4 * b[i].r * b[i].r){
					F1[i1] = max(F1[i1], F2[i]);
				}
			}
			F1[i1] += a[i1].z;
			i1++;
		}
		else{
			FOR(i, 0, n - 1){
				if(b[i2].r * 2 < min(a[i].x, a[i].y)){
					F2[i2] = max(F2[i2], F1[i]);
				}
			}
			FOR(i, 0, i2 - 1){
				F2[i2] = max(F2[i2], F2[i]);
			}
			F2[i2] += b[i2].h;
			i2++;
		}
	}
	while(i1 < sz(a)){
		FOR(i, 0, i1 - 1){
			if(a_on_b(a[i1], a[i])){
				F1[i1] = max(F1[i1], F1[i]);
			}
		}
		FOR(i, 0, m - 1){
			if(a[i1].x * a[i1].x + a[i1].y * a[i1].y < 4 * b[i].r * b[i].r){
				F1[i1] = max(F1[i1], F2[i]);
			}
		}
		F1[i1] += a[i1].z;
		i1++;		
	}
	while(i2 < m){
		FOR(i, 0, sz(a) - 1){
			if(b[i2].r * 2 < min(a[i].x, a[i].y)){
				F2[i2] = max(F2[i2], F1[i]);
			}
		}
		FOR(i, 0, i2 - 1){
			F2[i2] = max(F2[i2], F2[i]);
		}
		F2[i2] += b[i2].h;
		i2++;		
	}
	cout << max(*max_element(F1, F1 + 301), *max_element(F2, F2 + 101)) << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}
