#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int, int>>
#define ii pair<ll, ll>
#define mp make_pair
#define fi first
#define se second
#define pb pusa_back
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int a[m][n];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        int res = 0;
        res += 2 * m * n;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] == 0) res-=2;
                if(i == 0) res += a[i][j];
                if(i == m - 1) res += a[i][j];
                if(i > 0) res += abs(a[i][j] - a[i-1][j]);
                if(j == 0) res += a[i][j];
                if(j == n - 1) res += a[i][j];
                if(j > 0) res += abs(a[i][j] - a[i][j-1]);
            }
        }
        cout << res << endl;
    }
    return 0;
}