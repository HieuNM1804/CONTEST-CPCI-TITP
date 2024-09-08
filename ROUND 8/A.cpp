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
#define double long double

using namespace std;

struct Point{
	double x, y;
};

double dis(Point a, Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


Point Tam(Point a, Point b, Point c) {
    double D = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    double x = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / D;
    double y = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / D;
    return {x, y};
}

void solve(){
	int n; cin >> n;
	Point a[n + 1];
	FOR(i, 1, n) cin >> a[i].x >> a[i].y;
	double ans = 1e18;
	if(n == 2){
		double d = dis(a[1], a[2]);
		ans = d / 2;
	}
	else{
		FOR(i, 1, n){
			FOR(j, i + 1, n){
				FOR(k, j + 1, n){
					Point tam = Tam(a[i], a[j], a[k]);
					double r = max({dis(a[j], tam), dis(a[k], tam), dis(a[i], tam)});
					int ok = 1;
					FOR(_, 1, n){
						if(dis(a[_], tam) > r){
							ok = 0;
							break;
						}
					}
					if(ok) ans = min(ans, r);
				}
			}
		}
		FOR(i, 1, n){
			FOR(j, i + 1, n){
				double x = (a[i].x + a[j].x) / 2;
				double y = (a[i].y + a[j].y) / 2;
				Point td = {x, y};
				int ok = 1;
				double r = dis(a[i], td);
				FOR(k, 1, n){
					if(dis(a[k], td) > r){
						ok = 0;
						break;
					}
				}
				if(ok) ans = min(ans, r);
			}
		}
	}
	cout << fixed << setprecision(6) << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) solve();
	return 0;
}