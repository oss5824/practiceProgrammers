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
//���̵�� 3�����̻�15��������
//�ҹ���,����,����,��ħǥ���ڸ� ����
//��ħǥ�� ó���� �� �Ǵ� ������ ���Ұ�


//�ܰ�
//1.�빮�ڸ� �ҹ��ڷ� ġȯ
//2.Ư������ ����
//3.���� �� �̻��̸� ����
//4.���� �������� ���̸� ����
//5.���ڿ��̸� a
//6.16���� �̻��̸�ù 15�������� ������ ��� ����(������ ������ ���ڰ�.�̸� �̰͵� ����)
//7.new_id���� 2�����϶�� ���������ڸ� ���̰� 3�ɶ����� �ݺ�