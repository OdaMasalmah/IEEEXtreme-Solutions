// Link: https://csacademy.com/ieeextreme-practice/task/minimum-permutation/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int unsigned long long
#define sz(v) (int)(v).size()
#define mod 1000000007

void solve() {
        int n, m; cin >> n>> m;
        vector<int> v;
        for (int i= 0; i< n; i++) {
                int x; cin >> x;
                v.push_back(x);
        }

        vector<int> st;
        for (int i= 0; i< m; i++) {
                int s; cin >> s;
                st.push_back(s);
        }

        sort(all(st));

        int i=0, j= 0;

        for (; i< n&& j< m;) {
                if (st[j]< v[i]) {
                        cout << st[j]<< " ";
                        j++;
                } else {
                        cout << v[i]<< " ";
                        i++;
                }
        }

        while (i< n) cout << v[i++]<< " ";
        while (j< m) cout << st[j++]<< " ";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
