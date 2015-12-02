#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

class System {

private:
	int n, m;
	char **maze;
	bool **visited;
	int x1, y1;
	vector<pair<int, int>> result;

public:

	System(int a, int b){
		n = a;
		m = b;
		cout << "\n请输入迷宫地图：" << endl;
		maze = new char*[n];
		visited = new bool*[n];
		for (int i = 0; i < n; i++) {
			maze[i] = new char[m];
			visited[i] = new bool[m];
		}
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				cin >> maze[j][k];
				visited[j][k] = 0;
				if (j == 0 || j == n - 1 || k == 0 || k == m - 1) {
					visited[j][k] = 1;
				}
			}
	}

	~System() {
		for (int i = 0; i < n; i++) {
			delete maze[i];
			delete visited[i];
		}
	}

	void Start() {
		int  x2, y2;
		cout << "请输入起点：";
		cin >> x1 >> y1;
		cout << "请输入终点：";
		cin >> x2 >> y2;
		maze[x1][y1] = 'x';
		maze[x2][y2] = 'x';
		result.push_back(make_pair(x2, y2));
	}

	bool DFS(int x1, int y1) {
		visited[x1][y1] = 1;
		int dx[4] = { 1, -1, 0, 0 };
		int dy[4] = { 0, 0, 1, -1 };
		for (int i = 0; i < 4; i++) {
			int x = x1 + dx[i];
			int y = y1 + dy[i];
			if (!visited[x][y] && x > 0 && x < m&&y > 0 && y < n) {
				if (maze[x][y] == '0') {
					visited[x][y] = 1;
					if (DFS(x, y)) {
						maze[x][y] = 'x';
						result.push_back(make_pair(x, y));
					}
				}
				if (maze[x][y] == 'x') {
					return true;
				}
			}
		}
		return false;
	}

	void Run() {
		DFS(x1, y1);
		result.push_back(make_pair(x1, y1));
	}

	void Output() {
		cout << endl;
		cout << "迷宫地图\n" << endl;
		cout << left;
		cout << setw(8) << " ";
		for (int i = 0; i < m; i++)
			cout << i << "列     ";
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << i << "行     ";
			for (int j = 0; j < m; j++) {
				cout << setw(8) << maze[i][j];
			}
			cout << "\n" << endl;
		}
		cout << "\n" << endl;
		cout << "迷宫路径：";
		cout << "\n" << endl;
		for (int k = result.size() - 1; k >= 0; k--) {
			cout << "<" << result[k].first << "," << result[k].second << ">";
			if (k)cout << " --> ";
		}
		cout << "\n" << endl;
	}
};
			

int main() {
	int n, m;
	cout << "请输入迷宫的行数：";
	cin >> n;
	cout << "\n请输入迷宫的列数：";
	cin >> m;
	System sys(n, m);
	sys.Start();
	sys.Run();
	sys.Output();
	return 0;
}