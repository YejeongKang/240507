#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "membership.h"

using namespace std;

namespace inputData {

    bool join_check(string str) {
        string name, pw;
        size_t point, re_point;

        // �Է� �� (���� �ϳ� �̻� �ΰ� �Է��ߴ���) Ȯ��
        point = str.find(" ");

        if (point == string::npos) {

            cout << "�Է¿���: �̸��� ��й�ȣ�� ������ �ΰ� �Է��ϼ���." << endl;

            return false;
        }

        // �Է� �� (���� �ϳ��� �ΰ� �Է��ߴ���) Ȯ��
        else
        {
            re_point = str.find(" ", point + 1);

            if (re_point != string::npos) {

                cout << "�Է¿���: �̸��� ��й�ȣ ���� ������ �Է��� �� �����ϴ�." << endl;

                return false;
            }
            else {
                // �̸��� ��й�ȣ ����
                name = str.substr(0, point);
                pw = str.substr(point + 1);

                // ���� �ϳ��� �ΰ� �Է��ߴٸ� ��й�ȣ �ڸ��� Ȯ��
                if (pw.length() < 6 || pw.length() > 17) {

                    cout << "�Է¿���: ��й�ȣ�� 6-17�� �̳��� �ۼ��ϼ���." << endl;

                    return false;
                }
                // ���� �ϳ�, ��й�ȣ �ڸ��� ������ ��� �������� ��, true
                else {
                    return true;
                }
            }
        }
    }


	string login_Check() {
		string name, pw, temp, line, str;
		bool login_check;

		while (1) {
			// �̸��� ��й�ȣ �Է¹ޱ�
			cout << "�̸��� �Է��ϼ���. (�����Ϸ��� q �Է�) :";
			cin >> name;
			cout << endl << endl;

			if (name == "q") {
				cout << "���α׷��� �����մϴ�." << endl;
				break;
			}

			cout << "��й�ȣ�� �Է��ϼ���. (�����Ϸ��� q �Է�) :";
			cin >> pw;
			cout << endl << endl;

			if (pw == "q") {
				cout << "���α׷��� �����մϴ�." << endl;
				break;
			}

			// str ���ڿ��� ��ġ��
			temp = name;
			str = temp.append(" ");
			str = str.append(pw);

			// member ������ �������� �� �پ� �о����
			ifstream read_file("member.txt");

			if (read_file.is_open() == false) {
				cout << "������ �� �� �����ϴ�.";
				break;
			}
			else {
				while (getline(read_file, line)) {
					if (line == str) {
						login_check = true;
						break;
					}
					else {
						login_check = false;
					}
				}

				read_file.close();

				if (login_check == true) {
					cout << "�α��� ����" << endl << endl;
					return name;
					break;
				}
				else {
					cout << "�α��� ����" << endl << endl;
					return " ";
				}
			}
		}
	}
}