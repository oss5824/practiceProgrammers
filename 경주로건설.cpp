#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

int Map[25][25][4];
int N, M;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };//¼­ ºÏ µ¿ ³²
int solution(vector<vector<int>> board) {
    int answer = 1e9;
    N = board.size(), M = board[0].size();
    for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)for (int k = 0; k < 4; k++)Map[i][j][k] = 1e9;
    
    queue<pair<pair<int, int>, int>>q;
    q.push({ { 0,0 }, 2 }); q.push({ { 0,0 }, 3 });
    Map[0][0][0] = 0; Map[0][0][1] = 0; Map[0][0][2] = 0; Map[0][0][3] = 0;
    while (!q.empty()) {
        int curX = q.front().first.first, curY = q.front().first.second;
        int curD = q.front().second;; q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i], nextY = curY + dy[i];
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N ||
                board[nextY][nextX] == 1)continue;
            int cost = 0;
            if (i == curD)cost = Map[curY][curX][curD] + 100;
            else cost = Map[curY][curX][curD] + 600;
            if (cost < Map[nextY][nextX][i]) {
                Map[nextY][nextX][i] = cost; q.push({ {nextX,nextY},i });
            }
        }
    }
    for (int i = 0; i < 4; i++)answer = min(answer, Map[N - 1][M - 1][i]);
    return answer;
}
int main()
{
    cout << solution({ {0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 0},{0, 1, 0, 0, 0, 1, 0, 0},{1, 0, 0, 0, 0, 0, 0, 0} });
}