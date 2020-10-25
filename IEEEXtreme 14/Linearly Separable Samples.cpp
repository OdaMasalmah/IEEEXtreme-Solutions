#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define ld long double

ld PI = atan(1)*4;
int main(){
    FAST
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<pair<ld, ld>, ld> > points;
        for(int i = 0; i < n; i++){
            ld x, y, z; cin >> x >> y >> z;
            points.pb({{x, y}, z});
        }
        bool can = 0;
        for(ld i = 0; i <= 180; i += 1){
            ld x2 = points[i].first.first;
            ld y2 = points[i].first.second;
            ld slope = tan(i*PI/180.0);
            bool yes = 1;
            vector<ld> g1;
            vector<ld> g2;
            for(int j = 0; j < n; j++){
                ld yy = slope * points[j].first.first;
                if(yy > points[j].first.second){
                    g1.pb(points[j].second);
                }
                else if(yy < points[j].first.second){
                    g2.pb(points[j].second);
                }
            }
            for(int z = 0; z < g1.size(); z++)
                if(g1[z] != g1[0])
                    yes = false;

            for(int z = 0; z < g2.size(); z++)
                if(g2[z] != g2[0])
                    yes = false;
            if(!g1.empty() && !g2.empty()){
                if(g1[0] == g2[0])
                    yes = false;
            }
            if(yes){
                can = 1;
                break;
            }
        }
        vector<ld> gg1;
        vector<ld> gg2;
        for(int i = 0; i < n; i++){
            if(points[i].first.first > 0){
                gg1.pb(points[i].second);
            }
            else if(points[i].first.first < 0){
                gg2.pb(points[i].second);
            }
        }
        bool yes = true;
        for(int z = 0; z < gg1.size(); z++)
            if(gg1[z] != gg1[0])
                yes = false;

        for(int z = 0; z < gg2.size(); z++)
            if(gg2[z] != gg2[0])
                yes = false;
        if(!gg1.empty() && !gg2.empty()){
            if(gg1[0] == gg2[0])
                yes = false;
        }
        if(yes)can = 1;
        if(can){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
