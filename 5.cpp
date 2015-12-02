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
	cout << "关键字检索系统\n请输入文件名：";
	string fname;
	cin >> fname;
	cout << "\n请输入一段英文：\n";
	ofstream out(fname);
	string date, key;
	getchar();
	getline(cin,date);
	out << date;
	out.close();
	cout << "本段文本已保存在文本文件\"" << fname << "\"中。\n\n";
	cout << "请输入要检索的关键字：  ";
	cin >> key;
	LowerStr(key, 1);
	ifstream in(fname);
	string word;
	cout << "显示源文件\" " << fname << "\"：\n\n";
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
	cout << "\n\n在源文件中共检索到： " << n << " 个关键字\" " << key << " \"" << endl;
	return 0;
}