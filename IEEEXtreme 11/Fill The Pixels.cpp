// Link: https://csacademy.com/ieeextreme-practice/task/bd45c86a844acd8ffc58b6a965cb0197/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 998244353

const int MX= 1001;
bool vis[MX][MX];

void solve() {
        int m, n; cin >> m>> n;
        vector<string> str(n);

        for (int i= 0; i< n; i++) cin >> str[i];

        auto initVis= [&](){
                for (int i= 0; i< n; i++)
                for (int j= 0; j< m; j++)
                        vis[i][j]= 0;
        };

        function<void(int, int, vector<int>, vector<int>)> DFS= [&](int x, int y, vector<int> dx, vector<int> dy)->void {
                if (x< 0|| x>= n|| y< 0|| y>= m|| vis[x][y]== 1|| str[x][y]== '0') return;
                vis[x][y]= 1;
                for (int i= 0; i< (int)dx.size(); i++) {
                        int tox= x+ dx[i];
                        int toy= y+ dy[i];
                        DFS(tox, toy, dx, dy);
                }
                return;
        };



        auto go=[&](vector<int> dx, vector<int> dy) {
                int ans= 0;

                initVis();

                for (int i= 0; i< n; i++) {
                        for (int j= 0; j< m; j++) {
                                if (!vis[i][j]&& str[i][j]== '1') {
                                        DFS(i, j, dx, dy);
                                        ans+= 1;
                                }
                        }
                }
                return ans;
        };

        cout << go({1, -1, 0, 0}, {0, 0, 1, -1})<< " "
        << go({1, 1, -1, -1}, {1, -1, 1, -1})<< " "
        << go({1, -1, 0, 0, 1, 1, -1, -1}, {0, 0, 1, -1, 1, -1, 1, -1})<< "\n";
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
