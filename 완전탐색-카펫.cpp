#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10000000];
bool exist(string num, string numbers)
{
    int len1 = num.size(), len2 = numbers.size();
    for (int i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
        {
            if (num[i] == numbers[j]) { numbers[j] = 'x'; break; }
            if (j == len2 - 1)return false;
        }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    int val = atoi(numbers.c_str());
    for (int i = 0; i <= val; i++)arr[i] = i;
    for (int i = 2; i <= val; i++)
    {
        if (arr[i] == 0)continue;
        for (int j = 2 * i; j <= val; j += i)arr[j] = 0;
    }
    for (int i = 2; i <= val; i++)
    {
        if (exist(to_string(i), numbers)) if (arr[i] != 0)answer++;
    }
    return answer;
}