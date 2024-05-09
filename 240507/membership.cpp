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

        // 입력 값 (공백 하나 이상 두고 입력했는지) 확인
        point = str.find(" ");

        if (point == string::npos) {

            cout << "입력오류: 이름과 비밀번호를 공백을 두고 입력하세요." << endl;

            return false;
        }

        // 입력 값 (공백 하나만 두고 입력했는지) 확인
        else
        {
            re_point = str.find(" ", point + 1);

            if (re_point != string::npos) {

                cout << "입력오류: 이름과 비밀번호 외의 정보는 입력할 수 없습니다." << endl;

                return false;
            }
            else {
                // 이름과 비밀번호 추출
                name = str.substr(0, point);
                pw = str.substr(point + 1);

                // 공백 하나를 두고 입력했다면 비밀번호 자릿수 확인
                if (pw.length() < 6 || pw.length() > 17) {

                    cout << "입력오류: 비밀번호는 6-17자 이내로 작성하세요." << endl;

                    return false;
                }
                // 공백 하나, 비밀번호 자릿수 조건을 모두 충족했을 때, true
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
			temp = name;
			str = temp.append(" ");
			str = str.append(pw);

			// member 파일의 고객정보를 한 줄씩 읽어오기
			ifstream read_file("member.txt");

			if (read_file.is_open() == false) {
				cout << "파일을 열 수 없습니다.";
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
					cout << "로그인 성공" << endl << endl;
					return name;
					break;
				}
				else {
					cout << "로그인 실패" << endl << endl;
					return " ";
				}
			}
		}
	}
}