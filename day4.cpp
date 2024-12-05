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

void busca(char l, int i, int j);

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
            if(v[i][j] == 'X') busca('X', i, j);
        }
    }

    cout << ans << endl;
    return 0;
}

void busca(char l, int a, int b)
{
    char temp = l;
    
    for(int i = b; i < 500; i++)
    {
        if(v[a][i] == temp)
        {
            if(temp == 'S')
            {
                ans++;
                break;
            }

            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = b; i >= 0; i--)
    {
        if(v[a][i] == temp)
        {
            if(temp == 'S')
            {
                ans++;
                break;
            }
            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = a; i < 500; i++)
    {
        if(v[i][b] == temp)
        {   
            if(temp == 'S')
            {
                ans++;
                break;
            }

            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = a; i >= 0; i--)
    {
        if(v[i][b] == temp)
        {   
            if(temp == 'S')
            {
                ans++;
                break;
            }

            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = a, j = b; i < 500 && j < 500; i++, j++)
    {
        if(v[i][j] == temp)
        {   
            if(temp == 'S')
            {
                ans++;
                break;
            }

            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = a, j = b; i < 500 && j >= 0; i++, j--)
    {
        if(v[i][j] == temp)
        {
            if(temp == 'S')
            {
                ans++;
                break;
            }

            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = a, j = b; i >= 0 && j >= 0; i--, j--)
    {
        if(v[i][j] == temp)
        {
            if(temp == 'S')
            {
                ans++;
                break;
            }
            
            temp = m[temp];
        }
        else break;
    }

    temp = l;

    for(int i = a, j = b; i >= 0 && j < 500; i--, j++)
    {
        if(v[i][j] == temp)
        {   
            if(temp == 'S')
            {
                ans++;
                break;
            }

            temp = m[temp];
        }
        else break;
    }

    return;
}
