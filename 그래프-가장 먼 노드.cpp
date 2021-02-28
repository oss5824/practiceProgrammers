#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int>* v;
vector<bool>visit;
vector<int>arr;
void bfs(int num)
{
    queue<int>q; q.push(num); arr[num] = 1;
    while (!q.empty())
    {
        int cur = q.front(); q.pop(); if (visit[cur])continue;
        visit[cur] = true;
        for (int next : v[cur]) { q.push(next); if (arr[next] == 0) { arr[next] = arr[cur] + 1; } }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0; v = new vector<int>[n + 1]; visit.assign(n + 1, false); arr.assign(n + 1, 0);
    for (vector<int> iter : edge) { v[iter[0]].push_back(iter[1]); v[iter[1]].push_back(iter[0]); }
    for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
    bfs(1); sort(arr.begin(), arr.end());
    int vmax = arr[n]; for (int i = n; i >= 1; i--)if (vmax != arr[i])break; else answer++;
    return answer;
}