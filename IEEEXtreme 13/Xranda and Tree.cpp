// Link: https://csacademy.com/ieeextreme-practice/task/xranda-and-tree/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()

const int mod= 1000000007;
const int N= 100001;
int f[N], sz[N];

int get(int u) {
        if (u== f[u]) return u;
        else return f[u]= get(f[u]);
}

void union_(int u, int v) {
        int x= get(u);
        int y= get(v);
        if (x== y) return;
        else {
                if (sz[y]> sz[x]) swap(x, y);
                f[y]= x;
                sz[x]+= sz[y];
        }
}

void solve() {
        int n; cin >> n;

        for (int i= 0; i<= n; i++) {
                f[i]= i;
                sz[i]= 1;
        }

        vector<pair<int, pair<int, int>>> vb;
        for (int i= 0; i< n- 1; i++) {
                int u, v, c; cin >> u>> v>> c;
                vb.push_back({c, {u, v}});
        }

        sort(all(vb));

        int an= 0;
        for (int i= 0; i< n- 1; i++) {
                int c= vb[i].first;
                int y= vb[i].second.first;
                int x= vb[i].second.second;
                x= get(x);
                y= get(y);

                an= ((an% mod)+ (c% mod* sz[x]% mod* sz[y]% mod)% mod)% mod;
                union_(x, y);
        }
        cout << an<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
