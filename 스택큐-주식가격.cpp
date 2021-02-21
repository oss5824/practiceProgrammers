#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer; int len = prices.size(); vector<int>v(len, 0);
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1, count = 1; j < len; j++, count++)
        {
            if (prices[i] > prices[j]) { v[i] = count; break; }
            if (j == len - 1) { v[i] = j - i; }
        }
    answer = v;
    return answer;
}