// Link: https://csacademy.com/ieeextreme-practice/task/tree-fun/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 

const int N= 100011;
const int logN= 18;

int dp[N][logN], depth[N], c[N];
vector<int> adj[N];

void dfs(int u, int pa) {
        dp[u][0]= pa;
        for (auto x: adj[u]) {
                if (x== pa) continue;

                depth[x]= depth[u]+ 1;
                dfs(x, u);
        }
}

void dfs2(int u, int pa){
        for (auto x: adj[u]) {
                if (x== pa) continue;

                dfs2(x, u);
                c[u]+= c[x];
        }
}

int lca(int a, int b) {
        if (depth[a]< depth[b]) swap(a, b);

        for (int i= logN- 1; i>= 0; i--) { // put it in the same depth
                if ((depth[a]- (1<< i))>= depth[b]) {
                        a= dp[a][i];
                }
        }

        if (a== b) return a; // in the same V

        for (int i= logN- 1; i>= 0; i--) { // jump to get the node before lca
                if (dp[a][i]!= dp[b][i]) {
                        a= dp[a][i];
                        b= dp[b][i];
                }
        }
        return dp[a][0];
}

void solve(){
        int n, q; cin >> n>> q;
        for (int i= 0; i< n- 1; i++) {
                int u, v; cin >> u>> v;
                u++;
                v++;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        function<void()> precal= [&]()->void{
                memset(dp, -1, sizeof(dp));
                dfs(1, -1);

                for (int k= 1; k< logN; k++) {
                        for (int i= 1; i<= n; i++) {
                                if (dp[i][k- 1]== -1) continue;
                                dp[i][k]= dp[dp[i][k- 1]][k- 1]; // fill parent of i to all power of two
                        }
                }
                return;
        };

        precal();

        while (q--) {
                int a, b, cst; cin >> a>> b>> cst;
                a++; b++;
                int lc= lca(a, b);
                c[a]+= cst;
                c[b]+= cst;
                c[lc]-= cst;
                c[dp[lc][0]]-= cst;
        }
        dfs2(1, -1);
        int mnans= -1e18;
        for (int i= 1; i<= n; i++) mnans= max(mnans, c[i]);
        cout << mnans<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
