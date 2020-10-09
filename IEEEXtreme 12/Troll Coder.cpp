// Link: https://csacademy.com/ieeextreme-practice/task/troll-coder/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n; cin >> n;
        vector<int> v(n, 0);

        int res= 0, x= 0;

        auto ask= [&]() {
                cout << "Q ";
                for (auto X: v) cout << X<< " ";
                cout << endl;
        };

        ask();
        cin >> x;

        for (int i= 0; i< n; i++) {
                v[i]= 1;
                
                ask();
                int r;
                cin >> r;
                
                if (r< x) {
                        v[i]= 0;
                } else {
                    x= r;
                }
        }
        
        cout << "A ";
        for (auto X: v) cout << X<< " ";
        cout << endl;
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
