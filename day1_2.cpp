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

ll a, b;
map<int, int> m;
vector<ll> l1;

int main()
{
    ll soma = 0;

    while(true)
    {
        cin >> a >> b;
        if(a == b && b == 0) break;
        l1.push_back(a);
        m[b]++;
    }

    for(int i = 0; i < l1.size(); i++) soma += l1[i] * m[l1[i]];

    cout << soma << endl;
    
    return 0;
}
