#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	while (1) {

		// hello.txt�� �ִ� ���ڿ��� ������ ���� ����
		vector<string> v;

		// hello.txt�� output.txt�� ���ڿ��� �޾ƿ� ���� ����
		string line1;
		string line2;

		// hello.txt ������ ���� ���� ����
		ifstream read_file1("hello.txt");

		// hello.txt ������ �� ���ȴٸ�, ���͸� �������� �о���� => ���� v�� ����
		if (read_file1.is_open() == true) {

			for (int i = 0; i < 3; i++) {

				getline(read_file1, line1);

				v.push_back(line1);

			}
		}	
		else break;

		// 'hello.txt�� ���ڿ��� �Ųٷ� �Է��� ����'�� ���� ���� ����
		ofstream write_file("output.txt");

		// write_file�� ���� �����Ǿ����� Ȯ���ϰ�, �������� �ʾ����� ���� �޼��� ���
		if (write_file.fail() == true) {
		
			cout << "������ ���� ����." << endl;
			
			break;
		}
		else {
			// ���� v�� ������ ���ڿ��� write_file�� �ۼ�
			write_file << v[2] << endl << v[1] << endl << v[0] << endl;
		}

		// output.txt ������ ���� ���� ����
		ifstream read_file2("output.txt");
		
		// output.txt ������ �� ���ȴٸ�, ���͸� �������� �о ���
		if (read_file1.is_open() == true) {
			for (int i = 0; i < 3; i++) {

				getline(read_file2, line2);

				cout << line2 << endl;

			}
		}
		else break;

		// ���� �ݱ�
		read_file1.close();
		read_file2.close();
		write_file.close();

		// while�� Ż�� ��ȣ !
		return 0;
	}
}

