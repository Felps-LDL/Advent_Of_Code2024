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

string linha = "";

bool safe();

int main()
{
    int ans = 0;

    while(linha != "0 0")
    {
        getline(cin, linha);
        if(safe()) ans++;
    }

    cout << ans << endl;
    
    return 0;
}

bool safe()
{
    int i = 0, num1 = 0, num2 = 0;
    bool decre = false;

    for(i = 0; linha[i] != ' '; i++) num1 = num1 * 10 + int(linha[i] - '0');

    for(i = i + 1; linha[i] != ' '; i++) num2 = num2 * 10 + int(linha[i] - '0');

    if(num1 == num2) return false;

    if(abs(num1 - num2) < 1 || abs(num1 - num2) > 3) return false;

    if(num1 > num2) decre = true;

    while(i < linha.size())
    {   
        if(linha[i] == ' ')
        {
            if(abs(num1 - num2) < 1 || abs(num1 - num2) > 3) return false;

            if(decre && num2 > num1) return false;
            else if(!decre && num1 > num2) return false;

            num1 = num2;
            num2 = 0;
            i++;
            continue;
        }

        num2 = num2 * 10 + int(linha[i] - '0');
        i++;
    }

    if(abs(num1 - num2) < 1 || abs(num1 - num2) > 3) return false;

    if(decre && num2 > num1) return false;
    else if(!decre && num1 > num2) return false;

    return true;
}
