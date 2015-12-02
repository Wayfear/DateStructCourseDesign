#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

void OutUI() {

	cout << left;
	cout << setw(16) << "**" << setw(28) << "�������ģ��ϵͳ" << "**" << endl;
	cout << setfill('=') << setw(46) << "=" << endl;
	cout << setfill(' ') << setw(15) << "**" << setw(29) << "A --- ������������" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "B --- ��ӵ����ı�" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "C --- ������С������" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "D --- ��ʾ��С������" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "E --- �˳�   ����" << "**" << endl;
	cout << setfill('=') << setw(46) << "=" << endl;

}



struct Road {

	char start;
	char end;
	int len;

	Road() {}
	Road(char s, char e, int l) :start(s), end(e), len(l){}

	void operator = (Road t) {
		start = t.start;
		end = t.end;
		len = t.len;
	}
};

bool compare(Road& r1, Road& r2) {
	return r1.len > r2.len ? 1 : 0;
}

/*class MaxHeap{

private:
	vector<Road> date;
	int size = 0;

public:
	MaxHeap(){}

	MaxHeap(vector<Road> r) {
		for (Road a : r) {
			Insert(a);
		}
	}

	~MaxHeap() {
		date.clear();
	}

	void FixUp(int n) {
		int m = (n - 1) / 2;
		while (m >= 0&&n > 0) {
			if (date[m].len < date[n].len) {
				Road temp = date[m];
				date[m] = date[n];
				date[n] = temp;
			}
			else
				break;
			n = m;
			m = (m - 1) / 2;
		}
	}

	void Insert(Road& num) {
		date.push_back(num);
		size++;
		FixUp(size-1);
	}
};*/

class MinTree {

private:
	map<char, int> point;
	int n;
	vector<Road> roads[30];
	vector<Road> result;

public:
	
	void GetPoint() {
		cout << "�����붥��ĸ�����";
		cin >> n;
		cout << "�������������������ƣ�" << endl;
		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			point.insert(make_pair(c, i));
		}
	}

	void GetRoad(){
		while (1) {
			cout << "�������������㼰�ߣ�";
			int l;
			char s, e;
			cin >> s >> e >> l;
			if (s == '?'&&e == '?'&&l == 0)
				break;
			Road r1(s, e, l), r2(e, s, l);
			roads[point[s]].push_back(r1);
			roads[point[e]].push_back(r2);
		}
	}

	void BuildTree() {
		cout << "��������ʼ���㣺";
		char s;
		cin >> s;
		vector<Road> recoder;
		bool recopoint[31];
		memset(recopoint, 0, sizeof(recopoint));
		n--;
		while (n--){
			recopoint[point[s]] = 1;
			for (Road i : roads[point[s]]) {
				recoder.push_back(i);
			}
			sort(recoder.begin(), recoder.end(), compare);
			while (1) {
				if (recopoint[point[recoder.back().end]]) {
					recoder.pop_back();
				}
				else {
					s = recoder.back().end;
					result.push_back(recoder.back());
					break;
				}
			}
		}
		cout << "������С��������" << endl;
	}

	void Print() {
		for (Road i : result) {
			cout << i.start << "-<" << i.len << ">->" << i.end << "\t";
		}
		cout << endl;
	}
};

int main() {
	OutUI();
	MinTree minTree;
	int flag = 1;
	while (flag) {
		cout << "\n��ѡ�������";
		char key;
		cin >> key;
		switch (key) {
		case 'A':
			minTree.GetPoint();
			break;
		case 'B':
			minTree.GetRoad();
			break;
		case 'C':
			minTree.BuildTree();
			break;
		case 'D':
			minTree.Print();
			break;
		case 'E':
			flag = 0;
			break;
		default:
			continue;
		}
	}
	return 0;
}