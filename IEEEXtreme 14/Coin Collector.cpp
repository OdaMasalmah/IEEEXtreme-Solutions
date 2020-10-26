#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const ll inf= 1e12+ 8;

const int N= 1001;
int n, m;

vector<vector<ll>> solveSet(vector<pair<ll, ll>> &vp) {
        // dp[i][j]= min number to reach j element using first i'th element
        int M= vp.size();
        vector<vector<ll>> dp(N+ 1, vector<ll> (M+ 1, inf));

        for (int i= 0; i<= M; i++) {
                dp[0][i]= 0;
        }

        for (int i= 1; i< N; i++) {
                for (int j= 1; j<= M; j++) {
                        dp[i][j]= min({
                                dp[max(0LL, i- vp[j- 1].first)][j- 1]+ vp[j- 1].second,
                                dp[i][j- 1],
                                dp[i][j]
                                              });
                }
        }

        return dp;
}

void solve() {
        cin >> n>> m;
        vector<pair<ll, ll>> s1[3], s2[3], s3[3];

        map<string, int> id, mp;
        id["Zulian"] = 0;
        id["Razzashi"] = 1;
        id["Hakkari"] = 2;
        id["Sandfury"] = 0;
        id["Skullsplitter"] = 1;
        id["Bloodscalp"] = 2;
        id["Gurubashi"] = 0;
        id["Vilebranch"] = 1;
        id["Witherbark"] = 2;

        mp["Zulian"] = 0;
        mp["Razzashi"] = 0;
        mp["Hakkari"] = 0;
        mp["Sandfury"] = 1;
        mp["Skullsplitter"] = 1;
        mp["Bloodscalp"] = 1;
        mp["Gurubashi"] = 2;
        mp["Vilebranch"] = 2;
        mp["Witherbark"] = 2;

        for (int i= 0; i< m; i++) {
                string str; cin>> str;
                int x, y; cin >> x>> y;
                if (mp[str]== 0) {
                        s1[ id[str] ].push_back({x, y});
                }
                if (mp[str]== 1) {
                        s2[id[str]].push_back({x, y});
                }
                if (mp[str]== 2) {
                        s3[id[str]].push_back({x, y});
                }
        }

        vector<vector<ll>> dp[3];

        for (int i= 0; i< 3; i++) {
                dp[i]= solveSet(s1[i]);
        }

        vector<ll> dps1;
        for (int j= 1; j< (int)dp[0].size(); j++) {
                ll an= 0;
                for (int i= 0; i< 3; i++)
                        an+= dp[i][j][dp[i][j].size()- 1];
                if (an< inf) dps1.push_back(an);
        }


        for (int i= 0; i< 3; i++) {
                dp[i]= solveSet(s2[i]);
        }

        vector<ll> dps2;
        for (int j= 1; j< (int)dp[0].size(); j++) {
                ll an= 0;
                for (int i= 0; i< 3; i++)
                        an+= dp[i][j][dp[i][j].size()- 1];
                if (an< inf) dps2.push_back(an);
        }

        for (int i= 0; i< 3; i++) {
                dp[i]= solveSet(s3[i]);
        }

        vector<ll> dps3;
        for (int j= 1; j< (int)dp[0].size(); j++) {
                ll an= 0;
                for (int i= 0; i< 3; i++)
                        an+= dp[i][j][dp[i][j].size()- 1];
                if (an< inf) dps3.push_back(an);
        }

        if ((int)(dps1.size()+ dps2.size()+ dps3.size())< n) {
                cout << "impossible\n";
        } else {
//                for (auto X: dps1) cout << X<< " ";
//                cout << "\n";
//                for (auto X: dps2) cout << X<< " ";
//                cout << "\n";
//                for (auto X: dps3) cout << X<< " ";
//                cout << "\n";

                vector<pair<ll, ll>> vp[3];
                for (int i= 0; i< (int)dps1.size(); i++) {
                        vp[0].push_back({i+ 1, dps1[i]});
                }
                for (int i= 0; i< (int)dps2.size(); i++) {
                        vp[1].push_back({i+ 1, dps2[i]});
                }
                for (int i= 0; i< (int)dps3.size(); i++) {
                        vp[2].push_back({i+ 1, dps3[i]});
                }

                //dpans[i][j]= min cost to get i using any j
                vector<vector<ll>> dpans(n+ 1, vector<ll> (4, inf));
                dpans[0][0]= 0;
                dpans[0][1]= 0;
                dpans[0][2]= 0;
                dpans[0][3]= 0;

                for (int i= 1; i<= n; i++) {
                        for (int j= 1; j<= 3; j++){
                                for (int k= 0; k< (int)vp[j- 1].size(); k++) {
                                        dpans[i][j]= min({
                                                dpans[max(0LL, i- vp[j- 1][k].first)][j- 1] + vp[j- 1][k].second,
                                                dpans[i][j- 1],
                                                dpans[i][j]
                                                        });
                                }
                        }
                }
                cout << min({dpans[n][1], dpans[n][2], dpans[n][3]})<< "\n";
        }
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
