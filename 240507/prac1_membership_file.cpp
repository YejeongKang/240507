//�� �������� �� �Ͻ� �е��� �Ʒ� ��Ҹ� �߰����ּ���(���� �� ���Ͻ� �е��� �����Դϴ�!)
//"������̸� ��й�ȣ" ��İ��� �ٸ��� ���� 1���� �Ǵ� 3�� �̻� �Է��� ��� ���� �޽��� + �ٽ� �Է� �����ϵ���
//��й�ȣ�� 6�ڸ� �̻� ~18�ڸ� �̸����� ������
//���������� �Է� �޾��� ��쿡�� ���Ͽ� ����!

#include "membership.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace inputData;

#define MEMBER 3

int main() {
    int cnt = 0;
    string str, name, pw;
    vector<string> v_name, v_pw;
    size_t point, re_point;

    // MEMBER ���� ȸ�� ������ ��Ŀ� �°� �ԷµǾ�����, ���Ϳ� ����
    while (cnt < MEMBER) {
        cout << MEMBER - cnt << "���� ȸ���� ���� �̸�, ��й�ȣ�� ���������� �Է��ϼ���.(��й�ȣ�� 6-17�� �̳��� �ۼ�)" << endl;

        cout << cnt + 1 << "��° ȸ�� : ";

        getline(cin, str);

        if (join_check(str) == true) {

            // ���Ϳ� ����
            v_name.push_back(name);
            v_pw.push_back(pw);

            cnt++;
        }
        else {
            continue;
        }
    }

    // ���Ͽ� ȸ�� ���� ����
    ofstream member_info("member.txt");

    if (member_info.is_open()) {

        for (int i = 0; i < MEMBER; i++) {

            member_info << v_name[i] << " " << v_pw[i] << endl;

        }
        member_info.close();
    }
    else {
        cout << "������ �� �� �����ϴ�." << endl;

        return 0;
    }

    // ���Ͽ��� ȸ�� ���� ���
    ifstream member_print("member.txt");

    if (member_print.is_open()) {

        cout << "--------- ȸ�� ��� ��� ----------" << endl;

        while (getline(member_print, str)) {

            cout << str << endl;
        }
        member_print.close();
    }
    else {

        cout << "������ �� �� �����ϴ�." << endl;

        return 0;
    }

    return 0;
}
