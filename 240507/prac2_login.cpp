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
		// 이름과 비밀번호 입력받기
		cout << "이름을 입력하세요. (종료하려면 q 입력) :";
		cin >> name;
		cout << endl << endl;

		if (name == "q") {
			cout << "프로그램을 종료합니다." << endl;
			break;
		}

		cout << "비밀번호를 입력하세요. (종료하려면 q 입력) :";
		cin >> pw;
		cout << endl << endl;

		if (pw == "q") {
			cout << "프로그램을 종료합니다." << endl;
			break;
		}

		// str 문자열에 합치기
		str = name.append(" ");
		str = str.append(pw);

		cout << str << endl;
		// member 파일의 고객정보를 하나씩 읽어오기

		ifstream read_file("member.txt");

		if (read_file.is_open() == false) {
			cout << "파일을 열 수 없습니다.";
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
				cout << "로그인 성공" << endl << endl;
			}
			else {
				cout << "로그인 실패" << endl << endl;
			}
		}
		read_file.close();
	}
	return 0;
}
