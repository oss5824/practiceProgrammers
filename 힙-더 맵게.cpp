#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, t0 = 0;
    priority_queue<int, vector<int>, greater<int>>pq; for (int i : scoville)pq.push(i);
    for (t0 = pq.top(); t0 < K; answer++)
    {
        t0 = pq.top(); pq.pop();
        if (pq.empty() && t0 < K)return -1; else if (pq.empty()) break;
        int t1 = pq.top(), val = t0 + t1 * 2; pq.pop();
        pq.push(val); t0 = pq.top();
    }
    return answer;
}
int main()
{
    cout << solution({ 1,2,3,9,10,12 }, 7);
}