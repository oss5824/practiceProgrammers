#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, len = truck_weights.size(), all = 0, s = 0;
    vector<int>before_time(len, 0);
    for (int i = 0;;)
    {
        answer++;
        if (i != len && all + truck_weights[i] <= weight) { all += truck_weights[i]; i++; }
        for (int j = 0; j < i; j++)before_time[j]++;
        if (before_time[s] == bridge_length) { all -= truck_weights[s]; s++; if (s == len)break; }
    }
    return answer + 1;
}
