#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    int cnt = 0;
    for (int i = 0; i < 6; i++)if (lottos[i] == 0)cnt++;
    int min_res = 0;
    for (int i = 0; i < 6; i++)for (int j = 0; j < 6; j++)if (lottos[i] == win_nums[j])min_res++;
    if (min_res < 2)answer[1] = 6; else answer[1] = 7 - min_res;
    int max_res = min_res + cnt;
    if (max_res < 2)answer[0] = 6; else answer[0] = 7 - max_res;
    return answer;
}