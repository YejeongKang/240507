//�� �������� �� �Ͻ� �е��� �Ʒ� ��Ҹ� �߰����ּ���(���� �� ���Ͻ� �е��� �����Դϴ�!)
//"������̸� ��й�ȣ" ��İ��� �ٸ��� ���� 1���� �Ǵ� 3�� �̻� �Է��� ��� ���� �޽��� + �ٽ� �Է� �����ϵ���
//��й�ȣ�� 6�ڸ� �̻� ~18�ڸ� �̸����� ������
//���������� �Է� �޾��� ��쿡�� ���Ͽ� ����!

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define MEMBER 3

int main() {
    int cnt = 0;
    string str;
    string pw;
    vector<string> v_name;
    vector<string> v_pw;

    while (cnt < MEMBER) {
        cout << MEMBER - cnt << "���� ȸ���� ���� �̸�, ��й�ȣ�� ���������� �Է��ϼ���.(��й�ȣ�� 6-17�� �̳��� �ۼ�)" << endl;

        cout << cnt + 1 << "��° ȸ�� : ";
        getline(cin, str);

        // �Է� �� Ȯ��
        size_t point = str.find(" ");
        if (point == string::npos) {
            cout << "�Է¿���: �̸��� ��й�ȣ�� �Է��ϼ���." << endl;
            continue; // ���� ȸ�� ���� �Է� �ޱ�
        }

        // �̸��� ��й�ȣ ����
        string name = str.substr(0, point);
        pw = str.substr(point + 1);

        // ��й�ȣ ���� Ȯ��
        if (pw.length() < 6 || pw.length() > 17) {
            cout << "�Է¿���: ��й�ȣ�� 6-17�� �̳��� �ۼ��ϼ���." << endl;
            continue; // ���� ȸ�� ���� �Է� �ޱ�
        }

        // ���Ϳ� ����
        v_name.push_back(name);
        v_pw.push_back(pw);

        cnt++;
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
        return 1;
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
        return 1;
    }

    return 0;
}
