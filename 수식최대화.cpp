#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<long long>value, type;
vector<long long>tmp_value, tmp_type;

void solve(int i)
{
    int idx = 0;
    while (idx < tmp_type.size()) {
        if (tmp_type[idx] == i) {
            long long val1 = tmp_value[idx], val2 = tmp_value[idx + 1], sum = 0;
            if (i == 0)sum = val1 + val2;
            else if (i == 1)sum = val1 - val2;
            else sum = val1 * val2;
            auto pos = tmp_value.erase(tmp_value.begin() + idx, tmp_value.begin() + idx + 2);
            tmp_value.insert(pos, sum);
            tmp_type.erase(tmp_type.begin() + idx);
        }
        else idx++;
    }
}
long long solution(string expression) {
    long long answer = 0;
    int len = expression.length();
    string tmp;
    for (int i = 0; i < len; i++) {
        if (isdigit(expression[i]))tmp += expression[i];
        else {
            value.push_back(stoi(tmp)); tmp = "";
            char c = expression[i]; int val;
            if (c == '+')val = 0; else if (c == '-')val = 1; else val = 2;
            type.push_back(val);
        }
    } value.push_back(stoi(tmp));
    long long max_value = 0;
    vector<int>order; order.push_back(0); order.push_back(1); order.push_back(2);
    do {
        tmp_value = value, tmp_type = type;
        for (int i = 0; i < 3; i++)solve(order[i]);
        for (long long i : tmp_value)max_value = max(max_value, abs(i));
    } while (next_permutation(order.begin(), order.end()));
    answer = max_value;
    return answer;
}

int main() {
    cout<<solution("100-200*200+100");
}