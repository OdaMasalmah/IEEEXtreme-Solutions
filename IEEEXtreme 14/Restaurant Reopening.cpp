#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,avx")
#pragma GCC optimize("unroll-loops")
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (ll)(v).size()
#define mod 1000000007

const int inf= 1e8;

int dx[]= {1, -1, 0, 0};
int dy[]= {0, 0, -1, 1};

int r, c;
int sx, sy;

vector<string> str;

int get(int i, int j) {
        return (i* c)+ j;
}

int calc(int i, int j, int mask) {
        if (j== c) {
                return calc(i+ 1, 0, mask);
        }
        if (i== r) {
                int cost= 0;
                queue<pair<int, int>> q;
                q.push({sx, sy});

                vector<vector<bool>> vis(21, vector<bool>(21, 0));
                while ( q.size() ) {
                        pair<int, int> pos= q.front();
                        q.pop();
                        vis[pos.first][pos.second]= 1;
                        if (str[pos.first][pos.second]== '.'&& (mask& 1<< get(pos.first, pos.second))) { // table
                                for (int i= 0; i< 4; i++) {
                                        int tox= dx[i]+ pos.first;
                                        int toy= dy[i]+ pos.second;
                                        if (tox>=0 && tox< r&& toy>= 0&& toy< c) {
                                                if (mask& (1<< get(tox, toy))) {
                                                                return -inf;
                                                }
                                        }
                                }
                                continue;
                        }
                        for (int i= 0; i< 4; i++) {
                                int tox= dx[i]+ pos.first;
                                int toy= dy[i]+ pos.second;
                                if (tox>=0 && tox< r&& toy>= 0&& toy< c&& str[tox][toy]== '.'&& !vis[tox][toy]) {
                                        q.push({tox, toy});
                                        vis[tox][toy]= 1;
                                }
                        }
                 }
                for (int i= 0; i< r; i++) {
                        for (int j= 0; j< c; j++) {
                                if (str[i][j]== '.'&& vis[i][j]== 1) {
                                        if (mask& (1<< get(i, j))) {
                                                int an= 0;
                                                for (int ii= 0; ii< 4; ii++) {
                                                        int tox= dx[ii]+ i;
                                                        int toy= dy[ii]+ j;
                                                        if (tox>=0 && tox< r&& toy>= 0&& toy< c) {
                                                                if (vis[tox][toy]&& str[tox][toy]== '.') {
                                                                        cost++;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        }
                }
                return cost;
        }

        int ret= 0;

        if (str[i][j]== 'S'|| str[i][j]== '#') {
                return calc(i, j+ 1, mask);
        }
        ret= max(ret, calc(i, j+ 1, mask));
        if (str[i][j]== '.') {
                ret= max(ret, calc(i, j+ 1, mask| 1<< get(i, j)));
        }
        return ret;
}

void solve() {
        cin >> r>> c;
        str.resize(r);
        for (int i= 0; i< r; i++) cin>> str[i];

        for (int i= 0; i< r; i++) {
                for (int j= 0; j< c; j++) {
                        if (str[i][j]== 'S') {
                                sx= i;
                                sy= j;
                                break;
                        }
                }
        }
        cout << calc(0, 0, 0)<< "\n";
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        cin >> T;
        while ( T-- ) solve();
return 0;
}
