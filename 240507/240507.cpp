#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 10 18 12
		int my_list[3] = { 10, 18, 12 };

		// hello.txt와 output.txt의 문자열을 받아올 변수 선언
		string line1;

		// hello.txt 파일을 담을 변수 선언
		ifstream read_file1("hello.txt");

		// hello.txt 파일이 잘 열렸다면, 엔터를 기준으로 읽어오기 => 벡터 v에 저장
		if (read_file1.is_open() == true) {

			for (int i = 0; i < sizeof(my_list); i++) {
				cout << endl;
				for (int j = 0; j < my_list[i]; j++) {
					read_file1.seekg(j, ios::cur);
					cout << (char)read_file1.get();
				}
			}
		}
	
		// 파일 닫기
		read_file1.close();
		
	}


