// Link: https://csacademy.com/ieeextreme-practice/task/979a09a0cd8c4e98dd0a690f39a55bd2/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007

const int N= 1001;
int f[N], sz[N];

int get(int u) {
        if (u== f[u]) return u;
        else return f[u]= get(f[u]);
}

bool union_(int u, int v) {
        int x= get(u);
        int y= get(v);
        if (x== y) return 1;
        else {
                if (sz[y]> sz[x]) swap(x, y);
                f[y]= x;
        }
        return 0;
}

void solve() {
        int n, m; cin >> n>> m;

        for (int i= 0; i<= n; i++) {
                f[i]= i;
                sz[i]= 1;
        }

        bool loop= 0;

        for (int i= 0; i< m; i++) {
                int u, v; cin >> u>> v;
                if (union_(u, v)) loop= 1;
        }

        cout << loop<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
