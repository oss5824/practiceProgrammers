#include <string>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
map<string, int>m;
int solution(vector<vector<string>> clothes) {
    int len = clothes.size();
    int answer = 1;
    for (int i = 0; i < len; i++) { string s = clothes[i][1]; m[s]++; }
    len = m.size();
    for (auto i : m)answer *= (i.second + 1);
    answer -= 1;
    return answer;
}