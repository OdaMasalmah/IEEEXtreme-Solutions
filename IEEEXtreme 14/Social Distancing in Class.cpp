#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (ll)(v).size()
#define int long long
#define mod 1000000007

const int N= 300001;
vector<int> g[N];
int cost[N];

int bfs(int fr= 1) {
        queue<pair<int, int>> p;
        lp(i, N) cost[i]= -1e18;
        p.push({fr, 0});
        cost[fr]= 0;
        while ( p.size() ) {
                int nd= p.front().first, cnt= p.front().second;
                p.pop();
                for (auto x: g[nd]) {
                        if (cost[x]>= 0)continue; // i see before
                        else {
                                cost[x]= cnt+ 1;
                                p.push({x, cnt+ 1});
                        }
                }
        }
        int mx= -1, idx= 0;
        lp(i, N) if (mx< cost[i]) { mx= cost[i]; idx= i; }
        return idx;
}

void solve() {
        int n; cin >> n;
        lp(i, n- 1) {
                int u; cin >> u;
                u--;
                g[i+ 1].push_back(u);
                g[u].push_back(i+ 1);
        }
        int fr= bfs();
        int an= bfs(fr);

        double ans= 0;
        auto calc= [&](int c) {
                return c* (c+ 1)* (c* 2+ 1)/ 6;
        };

        for (int i= 0; i< n; i++) {
                ans+= calc(cost[i]);
        }
        cout << ans<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
