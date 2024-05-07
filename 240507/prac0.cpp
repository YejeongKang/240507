#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	while (1) {

		// hello.txt에 있는 문자열을 저장할 벡터 선언
		vector<string> v;

		// hello.txt와 output.txt의 문자열을 받아올 변수 선언
		string line1;
		string line2;

		// hello.txt 파일을 담을 변수 선언
		ifstream read_file1("hello.txt");

		// hello.txt 파일이 잘 열렸다면, 엔터를 기준으로 읽어오기 => 벡터 v에 저장
		if (read_file1.is_open() == true) {

			for (int i = 0; i < 3; i++) {

				getline(read_file1, line1);

				v.push_back(line1);

			}
		}	
		else break;

		// 'hello.txt의 문자열을 거꾸로 입력할 파일'을 담을 변수 선언
		ofstream write_file("output.txt");

		// write_file이 새로 생성되었는지 확인하고, 생성되지 않았으면 오류 메세지 출력
		if (write_file.fail() == true) {
		
			cout << "생성된 파일 없음." << endl;
			
			break;
		}
		else {
			// 벡터 v에 저장한 문자열을 write_file에 작성
			write_file << v[2] << endl << v[1] << endl << v[0] << endl;
		}

		// output.txt 파일을 담을 변수 선언
		ifstream read_file2("output.txt");
		
		// output.txt 파일이 잘 열렸다면, 엔터를 기준으로 읽어서 출력
		if (read_file1.is_open() == true) {
			for (int i = 0; i < 3; i++) {

				getline(read_file2, line2);

				cout << line2 << endl;

			}
		}
		else break;

		// 파일 닫기
		read_file1.close();
		read_file2.close();
		write_file.close();

		// while문 탈출 야호 !
		return 0;
	}
}

