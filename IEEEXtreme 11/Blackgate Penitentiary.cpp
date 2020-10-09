// Link: https://csacademy.com/ieeextreme-practice/task/8761fb7efefcf1d890df1d8d91cae241/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

vector<string> v[300];

void solve() {
        int n; cin >> n;

        for (int i= 0; i< n; i++) {
                string str; cin >> str;
                int x; cin >> x;
                v[x].push_back(str);
        }

        int cur= 0;
        for (int i= 120; i<= 250; i++) {
                if (v[i].size()) {
                        sort(all(v[i]));
                        for (auto X: v[i]) cout << X<< " ";
                        cout << cur+ 1<< " "<< cur+ v[i].size()<< "\n";
                        cur+= v[i].size();
                }
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
