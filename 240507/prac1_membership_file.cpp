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

		cout << MEMBER << "명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;

		for (int i = 0; i < MEMBER; i++) {

			cout << i + 1 << "번째 회원 : ";

			cin >> mem_name >> mem_pw;

			v_name.push_back(mem_name);
			v_pw.push_back(mem_pw);

		}

		ofstream member_info("member.txt");

		if (member_info.fail() == true) {

			cout << "생성된 파일 없음." << endl;

			break;
		}
		else {
			// 벡터 v(name,pw)에 저장한 문자열을 member_info에 작성
			for (int i = 0; i < MEMBER; i++) {

				member_info << v_name[i] << " " << v_pw[i] << endl;

			}

		ifstream member_print("member.txt");
		
		// output.txt 파일이 잘 열렸다면, 엔터를 기준으로 읽어서 출력
		if (member_print.is_open() == true) {
			cout << "--------- 회원 명부 출력 ----------";
			for (int i = 0; i < MEMBER; i++) {

				getline(member_print, line);

				cout << line << endl;

				}
			}
			else break;

			member_info.close();
			member_print.close();

			// while문 탈출 야호 !
			return 0;

		}
	}
}