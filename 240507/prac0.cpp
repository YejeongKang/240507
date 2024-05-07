#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	while (1) {

		vector<string> v;

		ifstream read_file1("hello.txt");

		string line;
		string print_txt;

		if (read_file1.is_open() == true) {

			for (int i = 0; i < 3; i++) {

				getline(read_file1, line);

				v.push_back(line);

			}
		}
		else {
				break;
			}

		ofstream write_file("output.txt");

		if (write_file.fail() == true) {
		
			cout << "积己等 颇老 绝澜." << endl;
			
			break;
		}
		else {

			write_file << v[2] << endl << v[1] << endl << v[0] << endl;
		}

		ifstream read_file2("output.txt");

		for (int i = 0; i < 3; i++) {

			getline(read_file2, print_txt);

			cout << print_txt << endl ;

		}

		read_file1.close();
		read_file2.close();
		write_file.close();

		return 0;
	}
}

