// Link: https://csacademy.com/ieeextreme-practice/task/xtreme-rappers/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define int long long
#define mod 1000000007

void solve() {
        int a, b; cin >> a>> b;
        int one= min({(a+ b)/ 3, a, b});
        cout << one<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
