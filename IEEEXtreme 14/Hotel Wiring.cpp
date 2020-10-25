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
#define int ll

int32_t main(){
    FAST
    int t; cin >> t;
    while(t--){
        int m, n, k; cin >> m >> n >> k;
        int arr[m];
        for(int i = 0; i < m; i++){
            int a; cin >> a;
            arr[i] = n - a;
        }
        sort(arr, arr + m);
        reverse(arr, arr + m);
        int ans = 0;

        for(int i = 0; i < k; i++){
            ans += arr[i];
        }
        for(int i = k; i < m; i++){
            ans += n - arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}
