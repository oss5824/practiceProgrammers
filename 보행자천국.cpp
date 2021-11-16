#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<limits.h>
#define INF 1e9
using namespace std;

int MOD = 20170805;
int Cache1[501][501];
int Cache2[501][501];

int N, M;
//0 일 때 x축으로 1일 때 y축으로
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    memset(Cache1, 0, sizeof(Cache1)), memset(Cache2, 0, sizeof(Cache2));
    int y = 1;
    Cache1[1][1] = 1; Cache2[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int& ret1 = Cache1[i][j];
            int& ret2 = Cache2[i][j];
            if (city_map[i-1][j-1] == 0) {
                ret1 += (Cache1[i - 1][j] + Cache2[i][j - 1]) % MOD;
                ret2 += (Cache1[i - 1][j] + Cache2[i][j - 1]) % MOD;
            }
            else if (city_map[i-1][j-1] == 2) {
                ret1+= Cache1[i - 1][j];
                ret2 += Cache2[i][j - 1];
            }
            else { ret1 = 0; ret2 = 0; }
        }
    }
    answer = (Cache1[m][n] % MOD);
    return answer;
}

int main()
{
    cout << solution(3, 3, { {0,0,0},{0,0,0},{0,0,0} });
}