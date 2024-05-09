//현 시점에서 다 하신 분들은 아래 요소를 추가해주세요(아직 다 못하신 분들은 예외입니다!)
//"사용자이름 비밀번호" 양식과는 다르게 값을 1개만 또는 3개 이상 입력할 경우 오류 메시지 + 다시 입력 가능하도록
//비밀번호는 6자리 이상 ~18자리 미만으로 적도록
//정상적으로 입력 받았을 경우에만 파일에 쓰기!

#include "membership.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace inputData;

#define MEMBER 3

int main() {
    int cnt = 0;
    string str, name, pw;
    vector<string> v_name, v_pw;
    size_t point, re_point;

    // MEMBER 명의 회원 정보가 양식에 맞게 입력되었으면, 벡터에 저장
    while (cnt < MEMBER) {
        cout << MEMBER - cnt << "명의 회원에 대한 이름, 비밀번호를 순차적으로 입력하세요.(비밀번호는 6-17자 이내로 작성)" << endl;

        cout << cnt + 1 << "번째 회원 : ";

        getline(cin, str);

        if (join_check(str) == true) {

            // 벡터에 저장
            v_name.push_back(name);
            v_pw.push_back(pw);

            cnt++;
        }
        else {
            continue;
        }
    }

    // 파일에 회원 정보 저장
    ofstream member_info("member.txt");

    if (member_info.is_open()) {

        for (int i = 0; i < MEMBER; i++) {

            member_info << v_name[i] << " " << v_pw[i] << endl;

        }
        member_info.close();
    }
    else {
        cout << "파일을 열 수 없습니다." << endl;

        return 0;
    }

    // 파일에서 회원 정보 출력
    ifstream member_print("member.txt");

    if (member_print.is_open()) {

        cout << "--------- 회원 명부 출력 ----------" << endl;

        while (getline(member_print, str)) {

            cout << str << endl;
        }
        member_print.close();
    }
    else {

        cout << "파일을 열 수 없습니다." << endl;

        return 0;
    }

    return 0;
}
