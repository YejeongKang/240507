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
		// 로그인 시도 -> name 가져오기(실패 시 공백 가져옴)
		in_name = login_Check();

		// 로그인 성공 시 실행
		if (in_name != " ") {

			ofstream tem("member_tel.txt");
			
			if (tem.is_open() == false) {
				cout << "파일을 열 수 없습니다.";
				return 0;
			}
			else {

				tem << "홍길동 01012345678";

				tem.close();
			}

			ifstream read_file("member_tel.txt");
			
			if (read_file.is_open() == false) {
				cout << "파일을 열 수 없습니다.";
				return 0;
			}
			else {

				while (read_file >> name >> tel) {

					v_name.push_back(name);

					v_pw.push_back(tel);

					// 명부에 있는 이름과 모두 비교해서, 존재하는지 아닌지 확인
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
			// 이미 member_tel에 이름이 존재한다면
			if (flag == true) {
				status = 1;
			}
			// member_tel에 이름이 존재하지 않는다면
			else {
				status = 2;
			}
			read_file.close();

			ofstream add_file("member_tel.txt");

			if (add_file.is_open() == false) {
				cout << "파일을 열 수 없습니다.";
				return 0;
			}
			else {

			switch (status) {

			// 이미 member_tel에 이름이 존재한다면
			case 1:
					cout << "전화번호를 입력하세요. ('-' 없이 입력) : ";

					cin >> tel;

					v_pw[idx] = tel;
									
					break;

			// member_tel에 이름이 존재하지 않는다면
			case 2:
					cout << "전화번호를 입력하세요. ('-' 없이 입력) : ";

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
		// 로그인 실패 시 다시 시도
		else {
			continue;
		}

	}
}
