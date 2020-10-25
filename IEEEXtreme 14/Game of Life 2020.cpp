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
    string s; cin >> s;
    int n, m; cin >> n >> m;
    string mat[n];
    for(int i = 0; i < n; i++){
        cin >> mat[i];
    }
    string live = "";
    string die = "";
    for(int i = 0; i < 5; i++){
        live += s[i];
    }
    for(int i = 6; i < s.size(); i++){
        die += s[i];
    }
    while(m--){
        string newmat[n];
        for(int i = 0; i < n; i++){
            newmat[i] = mat[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int neighbours = 0;
                if(mat[(i - 1 + n)%n][j] == '1')neighbours++;
                if(mat[i][(j - 1 + n)%n] == '1')neighbours++;
                if(mat[i][(j + 1)%n] == '1')neighbours++;
                if(mat[(i + 1)%n][j] == '1')neighbours++;
                if(mat[i][j] == '0'){
                    if(live[neighbours] == '1')newmat[i][j] = '1';
                }
                if(mat[i][j] == '1'){
                    if(die[neighbours] == '0')newmat[i][j] = '0';
                }

            }
        }
        for(int i = 0; i < n; i++){
            mat[i] = newmat[i];
        }
    }
    for(int i = 0; i < n; i++){
        cout << mat[i] << endl;
    }
    return 0;
}
