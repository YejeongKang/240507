#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "membership.h"

using namespace std;
using namespace inputData;

int main() {
	string name, tel, in_name, line;
	int status, pos, idx, cnt = 0;
	bool flag = false;
	vector<string> v_name, v_pw;

	while (1) {
		// �α��� �õ� -> name ��������(���� �� ���� ������)
		in_name = login_Check();

		// �α��� ���� �� ����
		if (in_name != " ") {

			ofstream tem("member_tel.txt");
			
			if (tem.is_open() == false) {
				cout << "������ �� �� �����ϴ�.";
				return 0;
			}
			else {

				tem << "ȫ�浿 01012345678";

				tem.close();
			}

			ifstream read_file("member_tel.txt");
			
			if (read_file.is_open() == false) {
				cout << "������ �� �� �����ϴ�.";
				return 0;
			}
			else {

				while (read_file >> name >> tel) {

					v_name.push_back(name);

					v_pw.push_back(tel);

					// ��ο� �ִ� �̸��� ��� ���ؼ�, �����ϴ��� �ƴ��� Ȯ��
					if (in_name == name) {
						flag = true;
						idx = cnt;

					}
					else {
						continue;
					}
					cnt++;
				}
			}
			// �̹� member_tel�� �̸��� �����Ѵٸ�
			if (flag == true) {
				status = 1;
			}
			// member_tel�� �̸��� �������� �ʴ´ٸ�
			else {
				status = 2;
			}
			read_file.close();

			ofstream add_file("member_tel.txt");

			if (add_file.is_open() == false) {
				cout << "������ �� �� �����ϴ�.";
				return 0;
			}
			else {

			switch (status) {

			// �̹� member_tel�� �̸��� �����Ѵٸ�
			case 1:
					cout << "��ȭ��ȣ�� �Է��ϼ���. ('-' ���� �Է�) : ";

					cin >> tel;

					v_pw[idx] = tel;
									
					break;

			// member_tel�� �̸��� �������� �ʴ´ٸ�
			case 2:
					cout << "��ȭ��ȣ�� �Է��ϼ���. ('-' ���� �Է�) : ";

					cin >> tel;

					v_name.push_back(in_name);

					v_pw.push_back(tel); 

					break;

				default:
					break;
				}
			}
			
			for (int i = 0; i < v_name.size(); i++) {

				cout << v_name[i] << " " << v_pw[i] << endl;
				add_file << v_name[i] << " " << v_pw[i] << endl;

			}

			add_file.close();
			return 0;
		}
		// �α��� ���� �� �ٽ� �õ�
		else {
			continue;
		}

	}
}
