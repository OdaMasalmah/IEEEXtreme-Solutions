#include<bits/stdc++.h>
using namespace std;


#define lp3(i,s,n) for(int i = s;i < int(n); ++i)
#define lp(i, n) lp3(i,0,n)
#define pb push_back
#define debug(x) cout<<"[" << #x << " is: " << x << "] "<<endl;

#define file freopen("input.in","r",stdin);
#define fastIO std::ios::sync_with_stdio(false); cin.tie(0);
map<string, int> id;

const int inf = 1e9;

vector<vector<pair<int, int>>> v(9);

int calc(int indx, int c, vector<pair<int, int>> &vec, vector<vector<int>> &dp){
    if(c <= 0)
        return 0;

    if(indx == vec.size())
        return inf;

    if(dp[indx][c] != -1)
        return dp[indx][c];
    return dp[indx][c] = min(calc(indx+1, c-vec[indx].first, vec, dp) + vec[indx].second, calc(indx+1, c, vec, dp));
}

int getBest(int type, int c){
    int total = 0;
    for(int k = type*3; k < type*3 + 3; k++){
        int sum = 0;
        for(int j = 0; j < v[k].size(); j++){
            sum += v[k][j].first;
        }
        if(sum < c)
            return inf;

        vector<vector<int>> dp(v[k].size(), vector<int>(c+1, -1));
        total += calc(0, c, v[k], dp);
    }
    return total;
}

void solve(){
    int n, m;
    cin>>n>>m;

    lp(i, m){
        string s;
        int a, b;
        cin>>s>>a>>b;

        v[id[s]].push_back({a, b});
    }

    lp(i, 9){
        sort(v[i].begin(), v[i].end(), [](auto a, auto b){
            return a.second < b.second;
        });
    }

    long long ans = inf;

    lp(i, n+1){
        lp(j, n+1){
            if(i+j > n)
                break;
            ans = min(ans, 0ll + getBest(0, i) + getBest(1, j) + getBest(2, n - i - j));
        }
    }
    if(ans >= inf)\
        cout<<"impossible"<<endl;
    else
        cout<<ans<<endl;
    
}

int32_t main() {  fastIO

    id["Zulian"] = 0;
    id["Razzashi"] = 1;
    id["Hakkari"] = 2;
    id["Sandfury"] = 3;
    id["Skullsplitter"] = 4;
    id["Bloodscalp"] = 5;
    id["Gurubashi"] = 6;
    id["Vilebranch"] = 7;
    id["Witherbark"] = 8;

    solve();
    
    return 0;
}
