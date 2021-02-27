#include< iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    int len = number.size(), idx = -1;
    for (int i = 0; i < k; i++, len--)
    {
        bool check = false;
        cout << answer << "\n";
        for (int j = 0; j < len - 1; j++)
        {
            if (answer[j] < answer[j + 1]) { check = true; answer.erase(j, 1); break; }
        }
        if (!check) { idx = i; break; }
    }
    if (idx != -1)answer.erase(len - (k - idx), k - idx);
    return answer;
}
int main()
{
    cout << solution("123456789", 4);
}