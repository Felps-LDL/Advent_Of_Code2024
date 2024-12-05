#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MAXN 50010
#define pii pair<int,int>
#define piii pair<pair<int,int>, int>;
#define ll long long
#define INF 1e9
#define LLINF 4e18
#define ALL(X) X.begin(), X.end()
#define EPS = 1e-9
#define ALL(X) X.begin(), X.end()
#define piv pair<int, vector<vector<int>>>
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define PB push_back
#define pq priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>

// Felipe Lages de Lima

using namespace std;

map<char, char> m;
vector<vector<char>> v(500, vector<char>(500, '.'));
int ans = 0;

void busca(int i, int j);

int main()
{
    m['X'] = 'M';
    m['M'] = 'A';
    m['A'] = 'S';
    int linha = 0;
    string texto;

    while(true)
    {
        getline(cin, texto);
        if(texto == "0 0") break;

        for(int i = 0; i < texto.size(); i++) v[linha][i] = texto[i];
        linha++;
    }

    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            if(v[i][j] == 'A') busca(i, j);
        }
    }

    cout << ans << endl;
    return 0;
}

void busca(int a, int b)
{
    if(a == 0 || a == 500 || b == 0 || b == 500) return;

    if(v[a - 1][b - 1] == 'M' && v[a + 1][b - 1] == 'M' && v[a + 1][b + 1] == 'S' && v[a - 1][b + 1] == 'S') ans++;
    if(v[a - 1][b - 1] == 'M' && v[a + 1][b - 1] == 'S' && v[a + 1][b + 1] == 'S' && v[a - 1][b + 1] == 'M') ans++;
    if(v[a - 1][b - 1] == 'S' && v[a + 1][b - 1] == 'S' && v[a + 1][b + 1] == 'M' && v[a - 1][b + 1] == 'M') ans++;
    if(v[a - 1][b - 1] == 'S' && v[a + 1][b - 1] == 'M' && v[a + 1][b + 1] == 'M' && v[a - 1][b + 1] == 'S') ans++;
    return;
}
