// Link: https://csacademy.com/ieeextreme-practice/task/pirates/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

const int N= 100001;
const int M= 1001;
int vis[M][M];
string v[M];
set<int> adj[N]; // for the new graph
int cost[N];

const int logN= 18;
int dp[N][logN], depth[N];

void dfs(int u, int pa) {
        dp[u][0]= pa;
        for (auto x: adj[u]) {
                if (x== pa) continue;

                depth[x]= depth[u]+ 1;
                dfs(x, u);
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

int lenght(int a, int b) { // length between two node
        int l= lca(a, b);
        return (depth[a]- depth[l]+ depth[b]- depth[l]);
}

void solve() {
        int n, m, Q; cin >> n>> m>> Q;
        for (int i= 0; i< n; i++) cin >> v[i];
        // TODO: convert it the undirected graph
        // every V should have index and mapping all cell to this index

        int dx[]= {1, -1, 0, 0, 1, 1, -1, -1}; // direction
        int dy[]= {0, 0, -1, 1, 1, -1, 1, -1};

        auto bad= [&](int x, int y)->bool{
                if (x< 0|| y< 0|| x>= n|| y>= m) return 1;
                return 0;
        };

        function<void(int, int, int, char)> DFS= [&](int x, int y, int id, char val)->void{
                if (bad(x, y)|| v[x][y]!= val|| vis[x][y]!= 0)
                        return;
                vis[x][y]= id;
                for (int i= 0; i< 8; i++) DFS(x+ dx[i], y+ dy[i], id, val);
        };

        int id= 1; // number of V

        for (int i= 0; i< n; i++) {
                for (int j= 0; j< m; j++) {
                        if (vis[i][j]== 0) {
                                DFS(i, j, id, v[i][j]);
                                id++;
                        }
                }
        }



        for (int r= 0; r< n; r++) {
                for (int c= 0; c< m; c++) {
                        int i= vis[r][c];
                        for (int ii= 0; ii< 8; ii++) {
                                int tox= r+ dx[ii];
                                int toy= c+ dy[ii];
                                if (bad(tox, toy)|| vis[tox][toy]== i) continue;
                                else {
                                        adj[i].insert(vis[tox][toy]);
                                        adj[vis[tox][toy]].insert(i);
                                }
                        }

                }
        }

        function<void()> precal= [&]()->void{
                memset(dp, -1, sizeof(dp));
                dfs(1, -1);

                for (int k= 1; k< logN; k++) {
                        for (int i= 1; i< id; i++) {
                                if (dp[i][k- 1]== -1) continue;
                                dp[i][k]= dp[dp[i][k- 1]][k- 1]; // fill parent of i to all power of two
                        }
                }
                return;
        };

        precal();

        while (Q--) {
                int x, y, tox, toy; cin >> x>> y>> tox>> toy;
                // answering
                int f= vis[x- 1][y- 1], to= vis[tox- 1][toy- 1];
                cout << lenght(f, to)/ 2<< "\n";
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
return 0;
}
