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
	string line;
	string pw_check;
	bool isNum;
	vector<string> v_name;
	vector<string> v_pw;

	while(1){
		cout << MEMBER << "���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;

		while (cnt < MEMBER) {
				v_name.reserve(MEMBER);
				v_pw.reserve(MEMBER);

				cout << cnt + 1 << "��° ȸ�� : ";

				getline(cin, str);

				pw_check = str.substr(str.find(" ") + 1);

				for (char ch : pw_check) {
					if (isdigit(ch) == false) {
						cout << "�Է¿���: ��й�ȣ�� ���ڸ� �Է��ϼ���." << endl;
						isNum = false;
						break;
					} else isNum = true;
				}
				if (isNum == true) {
					v_name.push_back(str.substr(0, str.find(" ")));

					v_pw.push_back(str.substr(str.find(" ") + 1));

					cnt++;
				}

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
				cout << "--------- ȸ�� ��� ��� ----------" << endl;
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
