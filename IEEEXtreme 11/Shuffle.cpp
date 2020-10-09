// Link: https://csacademy.com/ieeextreme-practice/task/0186cd4b3a330dc501606737e090e0da/statement/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

struct BipartiteMatching{
    vector<vector<int> > g;
    vector<int> L, R, vis;

    BipartiteMatching(int n, int m) :
    g(n+1), L(n+1, -1), R(m+1, -1), vis(n+1) {}

    void AddEdge(int a, int b){
        g[a].emplace_back(b);
    }

    bool match(int u){
        if(vis[u]) return false;
        vis[u] = 1;

        for(auto v : g[u]){
            if(R[v] == -1){
                L[u] = v;
                R[v] = u;
                return true;
            }
        }
        for(auto v : g[u]){
            if(match(R[v])){
                L[u] = v;
                R[v] = u;
                return true;
            }
        }
        return false;
    }
    int solve(){
        int ok = 1;
        while(ok--){
            fill(vis.begin(), vis.end(), 0);
            int n = (int)L.size()-1;
            for(int i=1;i<=n;i++){
                if(L[i] == -1) ok |= match(i);
            }
        }
        int res = 0;
        int n = (int)L.size()-1;
        for(int i=1;i<=n;i++) res += (L[i] != -1);
        return res;
    }
};

const int N= 201;
set<int> can[N];
bool bpGraph[N][N];

void solve() {
        int n; cin >> n;
        string str, T;
        getline(cin, str);

        for (int i= 0; i< n; i++) {

                getline(cin, str);
                istringstream ss(str);

                int freq[N]= {0};
                freq[i]= 1;
                int nm= 0;

                do {
                        ss >> T;
                        nm= stoi(T);
                        freq[nm]= 1;
                }while (ss);

                for (int j= 0; j< n; j++) {
                        if (freq[j]== 0) {
                                bpGraph[j][i]= 1;
                        }
                }
        }

        BipartiteMatching bpp(N, N);

        for (int i= 0; i< N; i++) {
                for (int j= 0; j< N; j++) {
                        if (bpGraph[i][j]) bpp.AddEdge(i+ 1, j+ 1);
                }
        }
        cout << n- bpp.solve()<< "\n";
}



int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
