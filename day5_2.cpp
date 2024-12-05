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

vector<set<int>> v(100);

int check(string texto, bool ver);

int main()
{
    string texto = "xxx";
    int ans = 0;

    while(true)
    {
        getline(cin, texto);

        if(texto == "0 0") break;

        int num1 = (texto[0] - '0') * 10 + texto[1] - '0', num2 = (texto[3] - '0') * 10 + texto[4] - '0';
        v[num1].insert(num2);
    }

    while(true)
    {
        getline(cin, texto);
        if(texto == "0 0") break;
        ans += check(texto, false);
    }

    cout << ans << endl;
    
    return 0;
}

int check(string texto, bool ver)
{
    vector<bool> visitados(100, false);
    vector<int> nums(100, -1);

    for(int i = 0; i < texto.size(); i += 3)
    {
        int num = (texto[i] - '0') * 10 + texto[i + 1] - '0';
        visitados[num] = true;

        for(auto x : v[num])
        {
            if(visitados[x])
            {
                texto[i] = x / 10 + '0';
                texto[i + 1] = x % 10 + '0';
                texto[nums[x]] = num / 10 + '0';
                texto[nums[x] + 1] = num % 10 + '0';
                return check(texto, true);
            }
        }

        if(nums[num] == -1) nums[num] = i;
    }

    if(ver)
    {
        for(int i = 0; i < 100; i++)
        {
            if(nums[i] == texto.size() / 2 - 1 || nums[i] == texto.size() / 2) return i;
        }
    }
    
    return 0;
}
