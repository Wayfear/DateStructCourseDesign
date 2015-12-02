#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

inline bool IsChar(char c) {
	if ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z'))
		return true;
	return false;
}

inline void LowerStr(string& s ,int n) {
	if (n) {
		if (s[0] >= 'A'&&s[0] <= 'Z')
			s[0] = s[0] - ('A' - 'a');
	}
	else {
		if (s[0] >= 'a'&&s[0] <= 'z')
			s[0] = s[0] + ('A' - 'a');
	}
}

int main() {
	cout << "�ؼ��ּ���ϵͳ\n�������ļ�����";
	string fname;
	cin >> fname;
	cout << "\n������һ��Ӣ�ģ�\n";
	ofstream out(fname);
	string date, key;
	getchar();
	getline(cin,date);
	out << date;
	out.close();
	cout << "�����ı��ѱ������ı��ļ�\"" << fname << "\"�С�\n\n";
	cout << "������Ҫ�����Ĺؼ��֣�  ";
	cin >> key;
	LowerStr(key, 1);
	ifstream in(fname);
	string word;
	cout << "��ʾԴ�ļ�\" " << fname << "\"��\n\n";
	cout << date;
	int n = 0;
	while (in >> word) {
		int num = word.size();
		while (!IsChar(word[num-1])) {
			word = word.substr(0, --num);
		}
		LowerStr(word, 1);
		if (word == key)
			n++;
	}
	LowerStr(key, 0);
	cout << "\n\n��Դ�ļ��й��������� " << n << " ���ؼ���\" " << key << " \"" << endl;
	return 0;
}