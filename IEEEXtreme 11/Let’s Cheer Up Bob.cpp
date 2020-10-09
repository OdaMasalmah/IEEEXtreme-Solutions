// Link: https://csacademy.com/ieeextreme-practice/task/ca9bc49133da9c3c90df045f4ea8fdd3/
#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()

const int Mx= 3;

struct node{
        bool turn;
        int grid[Mx][Mx];
        vector<pair<int, int>> an;
        node(){
                turn= true;
                memset(grid, 0, sizeof grid);
        }
};

void solve() {
        vector<pair<int, int>> vp;

        for (int i= 0; i< 9; i++) {
                int x, y; cin >> x>> y;
                vp.push_back({x- 1, y- 1});
        }

        auto ck= [&](node nd)->int{
                auto NotBob= [](int nm)->bool {
                        if (nm== 2|| nm== 0) return 1;
                        return 0;
                };

                auto Bob= [](int nm)->bool {
                        if (nm== 1|| nm== 0) return 1;
                        return 0;
                };

                for (int i= 0; i< 3; i++) { // win
                        bool ok= 1;
                        for (int j= 0; j< 3; j++) {
                                if (NotBob(nd.grid[i][j])) ok= 0;
                        }
                        if (ok) return 1;

                        ok= 1;
                        for (int j= 0; j< 3; j++) {
                                if (NotBob(nd.grid[j][i])) ok= 0;
                        }
                        if (ok) return 1;
                }
                bool okd= 1, okdn= 1;
                for (int i= 0; i< 3; i++) {
                        if (NotBob(nd.grid[i][i])) okd= 0;
                        if (NotBob(nd.grid[i][2- i])) okdn= 0;
                }
                if (okd|| okdn) return 1;

                for (int i= 0; i< 3; i++) { // lose
                        bool ok= 1;
                        for (int j= 0; j< 3; j++) {
                                if (Bob(nd.grid[i][j])) ok= 0;
                        }
                        if (ok) return -1;
                        ok= 1;
                        for (int j= 0; j< 3; j++) {
                                if (Bob(nd.grid[j][i])) ok= 0;
                        }
                        if (ok) return -1;
                }

                okd= 1, okdn= 1;
                for (int i= 0; i< 3; i++) {
                        if (Bob(nd.grid[i][i])) okd= 0;
                        if (Bob(nd.grid[i][2- i])) okdn= 0;
                }
                if (okd|| okdn) return -1;

                return 0; // draw
        };

        queue<node> q;
        q.push(node());

        while (q.size()) {
                node nd= q.front();
                q.pop();

                int wh= ck(nd);
                if (wh== -1) {
                        continue;
                } else if (wh== 1) {
                        for (int i= 0; i< nd.an.size(); i++) {
                                cout << nd.an[i].first+ 1<< " "<< nd.an[i].second+ 1<< "\n";
                        }
                        break;
                } else {
                        if (nd.turn) { // bob will play
                                for (int i= 0; i< 9; i++) {
                                        int x= vp[i].first, y= vp[i].second;
                                        if (nd.grid[x][y]== 0) {
                                                nd.grid[x][y]= 1;
                                                nd.turn^= 1;
                                                q.push(nd);
                                                break;
                                        }
                                }

                        } else { // I will play
                                for (int i= 0; i< 3; i++) {
                                        for (int j= 0; j< 3; j++) {
                                                if (nd.grid[i][j]== 0) {
                                                        nd.turn^= 1;
                                                        nd.grid[i][j]= 2;
                                                        nd.an.push_back({i, j});
                                                        q.push(nd);
                                                        nd.turn^= 1;
                                                        nd.grid[i][j]= 0;
                                                        nd.an.pop_back();
                                                }
                                        }
                                }
                        }
                }
        }
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) {
                solve();
        }
return 0;
}
