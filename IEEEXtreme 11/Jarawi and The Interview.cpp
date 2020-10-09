// Link: https://csacademy.com/ieeextreme-practice/task/6f960361da7beb7f3a083f4776c2cf79/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

vector<int> f[27];

void solve() {
        string str; cin >> str;
        int n= str.size();
        for (int i= 0; i< n; i++) f[str[i]- 'a'].push_back(i);

        int q; cin >> q;

        while (q--) {
                string s; cin >> s;
                int m= s.size();
                auto can= [&](int idx) {
                        for (int i= idx; i< m; i++)
                                if (f[s[i]- 'a'].size()== 0) return 0;

                        int cur= -1;
                        for (int i= idx; i< m; i++) {
                                int id= (s[i]- 'a');
                                auto pos= upper_bound(begin(f[id]), end(f[id]), cur);
                                if (pos== end(f[id])) return 0;
                                cur= *pos;
                        }
                        return 1;
                };

                int lo= 0, hi= s.size()+ 1;
                while (hi- lo> 1) {
                        int md= (hi+ lo)/ 2;
                        if (can(s.size()- md)) lo= md;
                        else hi= md;
                }

                cout << lo<< "\n";
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
