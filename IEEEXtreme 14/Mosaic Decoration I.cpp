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
    int n, c, p;
    cin >> n >> c >> p;
    int ans = 0;
    int suma = 0;
    int sumb = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        suma += a;
        sumb += b;
    }
    ans = (suma + 9)/10 * c;
    ans += (sumb + 9)/10 * p;
    cout << ans << endl;
    return 0;
}
