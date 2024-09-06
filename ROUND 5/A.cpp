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

/*
KIẾP NẠN
Test dễ sai :
Input:
abc
bca
Output:
Yes
Ta đổi abc->adc->bdc->bda->bca
Input:
acb
zxx
Output:
No
*/

bool can_change(string a, string b){
    map<char, set<char>> m;
    FOR(i, 0, sz(a) - 1){
        if(a[i] != b[i]){
            m[a[i]].insert(b[i]);
        }
    }
    for(auto it : m){
        if(sz(it.se) >= 2) return 0;
    }
    map<char, char> mp;
    FOR(i, 0, sz(a) - 1){
        if(mp.find(a[i]) != mp.end() && mp[a[i]] != b[i]) return 0;
        mp[a[i]] = b[i];
    }
    return 1;
}


void solve(){
    string s1, s2; cin >> s1 >> s2;
    if(can_change(s1, s2) && can_change(s2, s1)) cout << "Yes\n";
    else cout << "No\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}