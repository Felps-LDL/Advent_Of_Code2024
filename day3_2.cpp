#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MAXN 50010
#define pii pair<int,int>
#define piii pair<pair<int,int>, int>;
#define ll long long
#define INF 1e9
#define LLINF 4e18
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

bool ok = true;

int soma(string texto);
int check(string texto, int a);
void doit(string texto, int i);

int main()
{
    string texto;
    int total = 0;

    while(getline(cin, texto))
    {
        total += soma(texto);
    }

    cout << total << endl;
    
    return 0;
}

int soma(string texto)
{
    int total = 0;

    for(int i = 0; i < texto.size(); i++)
    {
        if(texto[i] == 'm') total += check(texto, i);
        if(texto[i] == 'd') doit(texto, i);
    }

    return total;
}

int check(string texto, int a)
{
    if(!ok) return 0;

    string temp = "";
    int i, num1 = 0, num2 = 0;

    for(i = a; i < a + 4; i++) temp += texto[i];

    if(temp != "mul(") return 0;

    for(i = a + 4; texto[i] != ','; i++)
    {
        if(texto[i] < '0' || texto[i] > '9') return 0;

        num1 = num1 * 10 + int(texto[i] - '0');
    }

    for(i = i + 1; texto[i] != ')'; i++)
    {
        if(texto[i] < '0' || texto[i] > '9') return 0;

        num2 = num2 * 10 + int(texto[i] - '0');
    }

    return num1 * num2;
}

void doit(string texto, int a)
{
    string temp = "";
    int i;

    for(i = a; i < a + 4; i++) temp += texto[i];

    if(temp == "do()")
    {
        ok = true;
        return;
    }

    for(i = a + 4; i < a + 7; i++) temp += texto[i];

    if(temp == "don't()")
    {
        ok = false;
        return;
    }
}
