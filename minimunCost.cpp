// example por LCS

/*
dado dos strings queremos que estos dos sean iguales
sacar un elemento del primer string cuesta $15
sacar un elemento del segundo string cuesta $30
the end of input -> #
*/
#include <bits/stdc++.h>
using namespace std;

string s, t;

const int N = 1000 + 20; // esto tiene una complejidad de n^2
int dp[N][N];

inline int lcs(string s, string t)
{
    for(int i = 0; i <= s.size(); ++i)
    {
        for(int j = 0; j <= t.size(); ++j)
        {
            if( !i || !j) { dp[i][j] = 0;}
            else if( s[i - 1] == t[j - 1]) //esto es pq dp esta pensado desde 1 y no desde cero como los strings s y t
            {
                dp[i][j] = max({dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1]});
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[s.size()][t.size()];
}

inline int find_answer(string s, string t)
{
    //l es el strong final y aqui aplicamos la formula general para este problema
    int l = lcs(s,t);
    return (s.size() - l) * 15 + (t.size() - l) * 30;
}

int main()
{
    while(cin>>s && s != "#")
    {
        cin>>t;

        cout<< find_answer(s,t)<<endl;
    }

    return 0;
}