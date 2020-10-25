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

int main(){
    FAST
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int q; cin >> q;
    int ans = 0;
    vector<pair<pair<int, int>, int> > vec;
    while(q--){
        int l, r, v;
        cin >> l >> r >> v;
        l--; r--;
        int has = 0;
        for(int i = l; i <= r; i++){
            has += arr[i];
            arr[i] = 0;
        }
        vec.pb({{l, r}, has});
        for(int i = 0; i < vec.size(); i++){
            bool deleted = 0;
            for(int j = i + 1; j < vec.size(); j++){
                int l1 = vec[i].first.first; int l2 = vec[j].first.first;
                int r1 = vec[i].first.second; int r2 = vec[j].first.second;
                if(l1 > r2 || l2 > r1)continue;
                vec[i].first.first = min(l1, l2);
                vec[i].first.second = max(r1, r2);
                vec.erase(vec.begin() + j);
                j = i;
                deleted = 1;
            }
            if(deleted)i--;
        }
        for(int i = 0; i < vec.size(); i++){
            if(l > vec[i].first.second || vec[i].first.first > r)continue;
            ans += min(v, vec[i].second);
            vec[i].second -= min(v, vec[i].second);
        }
    }
    cout << ans << endl;
    return 0;
}
