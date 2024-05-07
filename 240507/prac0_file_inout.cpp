#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// while(getline(read_file1,line) // EOF(End of File)
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
		
		read_file1.close();

		// 'hello.txt�� ���ڿ��� �Ųٷ� �Է��� ����'�� ���� ���� ����
		ofstream write_file("output.txt");

		// write_file�� ���� �����Ǿ����� Ȯ���ϰ�, �������� �ʾ����� ���� �޼��� ���
		if (write_file.fail() == true) {
		
			cout << "������ ���� ����." << endl;
			
			break;
		}
		else {
			// ���� v�� ������ ���ڿ��� write_file�� �ۼ�
			for (int i = 0; i < 3; i++) {

				write_file << v.back();
				v.pop_back();

			}
		}

		write_file.close();

		// output.txt ������ ���� ���� ����
		ifstream read_file2("output.txt");
		
		// output.txt ������ �� ���ȴٸ�, ���͸� �������� �о ���
		if (read_file2.is_open() == true) {
			for (int i = 0; i < 3; i++) {

				getline(read_file2, line2);

				cout << line2 << endl;

			}
		}
		else break;

		read_file2.close();

		// while�� Ż�� ��ȣ !
		return 0;
	}
}

