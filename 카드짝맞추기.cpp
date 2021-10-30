#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
bool live[7];
pair<pair<int, int>, pair<int, int>>posCard[7];
vector<int>order, v;

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int Board[4][4];
int Map[4][4];

bool range(int x, int y)
{
    if (x < 0 || x >= 4 || y < 0 || y >= 4)return false;
    return true;
}
int cal(int num, pair<int, int>start, pair<int, int>fin)
{
    for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++)Map[i][j] = 1e9;
    queue<pair<int, int>>q; q.push({ start });
    Map[start.second][start.first] = 0;

    while (!q.empty()) {
        int curX = q.front().first, curY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = curX, nextY = curY, step = 1;
            while (range(nextX + dx[i], nextY + dy[i])) {
                nextX += dx[i], nextY += dy[i];
                if (Board[nextY][nextX] != 0)break;
                if (Map[nextY][nextX] > Map[curY][curX] + step) {
                    Map[nextY][nextX] = Map[curY][curX] + step;
                    q.push({ nextX,nextY });
                }
                step++;
            }
            if (Map[nextY][nextX] > Map[curY][curX] + 1) {
                Map[nextY][nextX] = Map[curY][curX] + 1;
                q.push({ nextX,nextY });
            }
        }
    }
    return Map[fin.second][fin.first];
}

int solve(int num, int x, int y)
{
    if (num == v.size())return 0;
    int x1 = posCard[v[num]].first.first, y1 = posCard[v[num]].first.second;
    int x2 = posCard[v[num]].second.first, y2 = posCard[v[num]].second.second;
    int d1 = cal(v[num], { x,y }, { x1,y1 }) + cal(v[num], { x1,y1 }, { x2,y2 }) + 2;
    int d2 = cal(v[num], { x,y }, { x2,y2 }) + cal(v[num], { x2,y2 }, { x1,y1 }) + 2;

    int res = 1e9;
    Board[y1][x1] = 0; Board[y2][x2] = 0;
    res = min(res, min(d1 + solve(num + 1, x2, y2), d2 + solve(num + 1, x1, y1)));
    Board[y1][x1] = v[num]; Board[y2][x2] = v[num];
    return res;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    for (int i = 1; i <= 6; i++)posCard[i] = { {-1,-1},{-1,-1} };
    memset(live, false, sizeof(live));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            int num = board[i][j];
            Board[i][j] = num;
            if (num == 0)continue;
            if (posCard[num].first.first == -1)posCard[num].first = { j,i };
            else posCard[num].second = { j,i };
            if (!live[num])order.push_back(num);
            live[num] = true;
        }
    sort(order.begin(), order.end());
    int min_value = 1e9;
    do {
        v = order; min_value = min(solve(0, c, r), min_value);
    } while (next_permutation(order.begin(), order.end()));
    cout << min_value;
    return answer;
}

int main()
{
    solution({ {3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3} }, 0, 1);
    //solution({ {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} }, 1, 0);
}

//solution({ {3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3} }, 0, 1);