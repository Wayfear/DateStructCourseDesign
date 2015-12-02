#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class System {

private:

	char **date;
	bool *column, *firVisited, *secVisited;
	int num;
	int cas = 0;

public:

	System(int n):num(n) {

		date = new char*[n];
		for (int i = 0; i < n; i++)
			date[i] = new char[n];
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				date[j][k] = '0';

		column = new bool[n];
		firVisited = new bool[2 * n - 1];
		secVisited = new bool[2 * n - 1];
		memset(column, 0, n);
		memset(firVisited, 0, 2 * n - 1);
		memset(secVisited, 0, 2 * n - 1);
	}

	~System() {
		delete column;
		delete firVisited;
		delete secVisited;
		for (int i = 0; i < num; i++)
			delete date[i];
	}

	void Run(int i = 0) {
		if (i == num) {
			cas++;
			Output();
			return;
		}
		for (int j = 0; j < num; j++) {
			if (!column[j] && !firVisited[j - i + num - 1] && !secVisited[j + i]) {
				column[j] = 1;
				firVisited[j - i + num - 1] = 1;
				secVisited[j + i] = 1;
				date[i][j] = 'X';
				Run(i + 1);
				date[i][j] = '0';
				column[j] = 0;
				firVisited[j - i + num - 1] = 0;
				secVisited[j + i] = 0;
			}
		}
	}

	void Output() {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cout << date[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	int GetCase() {
		return cas;
	}
	
};

int main() {
	cout << "现有N*N的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一斜线上！\n" << endl;
	cout << "请输入皇后的个数：";
	int n; 
	cin >> n;
	cout << "\n皇后摆法：\n" << endl;
	System sys(n);
	sys.Run();
	cout << "共有" << sys.GetCase() << "种解法！" << endl;
	return 0;
}