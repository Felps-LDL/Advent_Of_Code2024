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

vector<vector<char>> v(500, vector<char>(500, 't'));
vector<vector<bool>> visitados(500, vector<bool>(500, false));

int ans = 0;

void check(int i, int j, string move);

int main()
{
    string texto;
    int linha = 0;

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
            if(v[i][j] == '^') check(i, j, "up");
        }
    }

    for(int i = 0; i < 500; i++)
    {
        for(int j = 0; j < 500; j++)
        {
            if(v[i][j] == 't') break;
            
            if(v[i][j] == '#')
            {
                cout << '#';
                continue;
            }

            if(visitados[i][j]) cout << 'X';
            else cout << '.';
        }

        cout << endl;
        if(v[i][0] == 't') break;
    }

    cout << ans << endl;
    return 0;
}

void check(int i, int j, string move)
{
    if(!visitados[i][j])
    {
        visitados[i][j] = true;
        ans++;
    }

    if(move == "up")
    {
        if(i == 0) return;
        else if(v[i - 1][j] == '#') check(i, j + 1, "r");
        else check(i - 1, j, move);
    }
    else if(move == "r")
    {
        if(v[i][j + 1] == 't') return;
        else if(v[i][j + 1] == '#') check(i + 1, j, "d");
        else check(i, j + 1, move);
    }
    else if(move == "d")
    {
        if(v[i + 1][j] == 't') return;
        else if(v[i + 1][j] == '#') check(i, j - 1, "l");
        else check(i + 1, j, move);
    }
    else
    {
        if(j == 0) return;
        else if(v[i][j - 1] == '#') check(i - 1, j, "up");
        else check(i, j - 1, move);
    }
}
