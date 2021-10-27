#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    //1
    int len = new_id.length();
    for (int i = 0; i < len; i++) if (isupper(new_id[i]))new_id[i] = tolower(new_id[i]);
    //2
    string tmp = new_id; new_id = "";
    for (int i = 0; i < len; i++) {
        if (!isalpha(tmp[i]) && !isdigit(tmp[i])) {
            if (tmp[i] == '-' || tmp[i] == '_' || tmp[i] == '.') {}
            else continue;
        }
        new_id.push_back(tmp[i]);
    }
    //3
    tmp = new_id; new_id = "";
    len = tmp.length(); bool dot = false;
    for (int i = 0; i < len; i++) {
        if (dot == false && tmp[i] == '.') dot = true;
        else if (dot == true && tmp[i] == '.')continue;
        else dot = false;
        new_id.push_back(tmp[i]);
    }
    //4
    len = new_id.length();
    if (new_id[len - 1] == '.')new_id.pop_back();
    if (new_id[0] == '.')new_id.erase(0, 1);
    //5
    len = new_id.length();
    if (len == 0)new_id = "a";
    //6
    if (len >= 16) {
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.')new_id.pop_back();
    }
    //7
    len = new_id.length();
    if (len <= 2) {
        while (new_id.length() != 3) { new_id.push_back(new_id.back()); }
    }
    answer = new_id;
    return answer;
}
int main()
{
    cout << solution("...!@BaT#*..y.abcdefghijklm");
}
//아이디는 3글자이상15글자이하
//소문자,빼기,밑줄,마침표문자만 가능
//마침표는 처음과 끝 또는 연속적 사용불가


//단계
//1.대문자를 소문자로 치환
//2.특수문자 제거
//3.점이 둘 이상이면 제거
//4.점이 마지막과 끝이면 제거
//5.빈문자열이면 a
//6.16글자 이상이면첫 15개제외한 나머지 모두 제거(제거후 마지막 문자가.이면 이것도 제거)
//7.new_id값이 2자이하라면 마지막문자를 길이가 3될때까지 반복