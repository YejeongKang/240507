#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define MEMBER 3

int main() {
	string mem_name;
	string line;
	int mem_pw;
	vector<string> v_name;
	vector<int> v_pw;

	while (1) {
		v_name.reserve(MEMBER);
		v_pw.reserve(MEMBER);

		cout << MEMBER << "���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;

		for (int i = 0; i < MEMBER; i++) {

			cout << i + 1 << "��° ȸ�� : ";

			cin >> mem_name >> mem_pw;

			v_name.push_back(mem_name);
			v_pw.push_back(mem_pw);

		}

		ofstream member_info("member.txt");

		if (member_info.fail() == true) {

			cout << "������ ���� ����." << endl;

			break;
		}
		else {
			// ���� v(name,pw)�� ������ ���ڿ��� member_info�� �ۼ�
			for (int i = 0; i < MEMBER; i++) {

				member_info << v_name[i] << " " << v_pw[i] << endl;

			}

		ifstream member_print("member.txt");
		
		// output.txt ������ �� ���ȴٸ�, ���͸� �������� �о ���
		if (member_print.is_open() == true) {
			cout << "--------- ȸ�� ��� ��� ----------";
			for (int i = 0; i < MEMBER; i++) {

				getline(member_print, line);

				cout << line << endl;

				}
			}
			else break;

			member_info.close();
			member_print.close();

			// while�� Ż�� ��ȣ !
			return 0;

		}
	}
}