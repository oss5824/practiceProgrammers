#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
pair<int, int>pos[10] = { {3,1}, {0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftX = 0, leftY = 3;
    int rightX = 2, rightY = 3;
    for (int i : numbers) {
        int posX = pos[i].second, posY = pos[i].first;
        if (i == 1 || i == 4 || i == 7) { leftX = posX, leftY = posY; answer += "L"; }
        else if (i == 3 || i == 6 || i == 9) { rightX = posX, rightY = posY; answer += "R"; }
        else {
            int distLeft = abs(leftX - posX) + abs(leftY - posY);
            int distRight = abs(rightX - posX) + abs(rightY - posY);
            if (distLeft > distRight || (distLeft == distRight && hand == "right")) {
                rightX = posX, rightY = posY; answer += "R";
            }
            else { leftX = posX, leftY = posY; answer += "L"; }
        }
    }
    return answer;
}
int main()
{
    solution({ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 }, "right");
}

/*
int bfs(int x, int y,char c)
{
    queue<pair<int, pair<int, int>>>q; q.push({ 0,{ x,y } }); visit[y][x] = true;
    while (!q.empty()) {
        int curX = q.front().second.first, curY = q.front().second.second; q.pop();
        int curD = q.front().first;
        if (Map[curY][curX] == c)return curD;
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i], nextY = curY + dy[i];
            if (nextX < 0 || nextX >= 3 || nextY < 0 || nextY >= 4 || visit[nextY][nextX])continue;
            q.push({ curD + 1,{ nextX,nextY } }); visit[nextY][nextX] = true;
        }
    }
}
*/