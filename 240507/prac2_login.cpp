#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	string name;
	string pw;
	string line;
	string str;
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
		str = name.append(" ");
		str = str.append(pw);

		cout << str << endl;
		// member ������ �������� �ϳ��� �о����

		ifstream read_file("member.txt");

		if (read_file.is_open() == false) {
			cout << "������ �� �� �����ϴ�.";
			return 0;
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
			if (login_check == true) {
				cout << "�α��� ����" << endl << endl;
			}
			else {
				cout << "�α��� ����" << endl << endl;
			}
		}
		read_file.close();
	}
	return 0;
}
