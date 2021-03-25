#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> v : commands)
    {
        int i = v[0] - 1, j = v[1] - 1, k = v[2] - 1;
        vector<int> res;
        for (int idx = i; idx <= j; idx++)res.push_back(array[idx]);
        sort(res.begin(), res.end());
        answer.push_back(res[k]);
    }
    return answer;
}