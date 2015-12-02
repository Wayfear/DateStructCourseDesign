#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Node {

	Node *left = nullptr, *right = nullptr;
	int num;

	Node(int n) :num(n){}
	Node(){}
};

struct System {

private:

	Node *start;
	int allNum;

public:

	System(int n) :allNum(n) {
		if (!n)return;

		start = new Node(1);
		if (n == 1) {
			start->left = start;
			start->right = start;
			return;
		}

		Node* lNode = start, *rNode;
		for (int i = 2; i <= n; i++) {
			rNode = new Node(i);
			lNode->right = rNode;
			rNode->left = lNode;
			lNode = rNode;
		}
		rNode->right = start;
		start->left = rNode;
	}

	System(){}

	~System() {
		for (int i = 0; i < allNum; i++) {
			Node* temp = start->right;
			delete start;
			start = temp;
		}
	}
	
	int Remove(Node *&node) {
		Node* temp = node->right;
		node->left->right = node->right;
		node->right->left = node->left;
		int n = node->num;
		delete node;
		node = temp;
		return n;
	}

	void Run(int startPos, int killedNum ,int key) {
		Node* nowPos = start;
		for (int i = 0; i < startPos - 1; i++)
			nowPos = nowPos->right;
		for (int j = 1; j <= killedNum; j++) {
			for (int k = 0; k < key - 1; k++) {
				nowPos = nowPos->right;
			}
			cout << "��" << j << "�����ߵ�λ���ǣ�\t" << Remove(nowPos) << endl;
			allNum--;
		}
	}

	void Output() {
		cout << "���ʣ�£�\t" << allNum << "��" << endl;
		Node *temp = start;
		cout << "ʣ�������λ�ã�";
		for (int i = 0; i < allNum; i++) {
			cout << "\t" << temp->num;
			temp = temp->right;
		}
	}
};

int main() {
	cout << "����N��Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ\n" << endl;

	int n, s, k, m;
	cout<<left;
	cout << "������������Ϸ��������N��";
	cin >> n;
	cout << setw(24) << "��������Ϸ��ʼ��λ��S��";
	cin >> s;
	cout << setw(24) << "��������������M��";
	cin >> m;
	cout << setw(24) << "������ʣ����������K��";
	cin >> k;
	cout << endl;

	System sys(n);
	sys.Run(s, n - k, m);
	cout << endl;
	sys.Output();
	cout << endl;
	return 0;
}