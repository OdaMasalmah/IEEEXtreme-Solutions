// Link: https://csacademy.com/ieeextreme-practice/task/bit-soccer/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()

void solve() {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i: v) cin >> i;

        int q; cin >> q;
        while ( q-- ) {
                int X; cin >> X;
                int an= 0;
                for (int i= 0; i< n; i++) {
                        if ((v[i]| X)== X) { // same one with X
                                an|= v[i];
                        }
                }

                bool ok= 1;

                for (int i= 40; i>= 0; i--) { // check all one's bit appear
                        if (X& ((long long)1<< i)) { 
                                if (an& ((long long)1<< i)) {
                                        continue;
                                } else ok= 0;
                        }
                }
                
                cout << (ok? "YES\n": "NO\n");
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
