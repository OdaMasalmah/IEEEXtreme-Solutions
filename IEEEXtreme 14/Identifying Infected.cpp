#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;
const int N= 1001;
int n, m;
vector<int> adj[N];
vector<int> vis;
vector<int> path;

void solve() {
        cin >> n>> m;
        for(int i= 0; i< m; i++) {
                int u, v; cin >> u>> v;
                u--;
                v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }

        vis.resize(n);
        path.resize(n);

        int t; cin >> t;

        while ( t-- ) {
                int f, s; cin >> f>> s;
                f--;
                s--;

                auto BFS= [&](int f, int s, int wh)->vector<int>{
                        queue<int> q;
                        q.push(f);
                        for (int i= 0; i< n; i++) vis[i]= 0;
                        for (int i= 0; i< n; i++) path[i]= -1;
                        if (wh!= -1) vis[wh]= 1;
                        while (q.size()) {
                                int nd= q.front();
                                q.pop();
                                vis[nd]= 1;
                                for (auto X: adj[nd]) {
                                        if (!vis[X]) {
                                                path[X]= nd;
                                                q.push(X);
                                                vis[X]= 1;
                                        }
                                }
                        }
                        vector<int> ans;
                        int cur= s;
                        while (cur != -1) {
                                if (cur!= s&& cur!= f)
                                        ans.push_back(cur);
                                cur= path[cur];
                        }
                        return ans;
                };

                vector<int> ans= BFS(f, s, -1);
                int an= ans.size()+ 2;
                for (auto X: ans) {
                        vector<int> get= BFS(f, s, X);
                        if (get.size()> 0) an--;
                }
                cout << an<< "\n";
        }
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
