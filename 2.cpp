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
			cout << "第" << j << "个死者的位置是：\t" << Remove(nowPos) << endl;
			allNum--;
		}
	}

	void Output() {
		cout << "最后剩下：\t" << allNum << "人" << endl;
		Node *temp = start;
		cout << "剩余的生者位置：";
		for (int i = 0; i < allNum; i++) {
			cout << "\t" << temp->num;
			temp = temp->right;
		}
	}
};

int main() {
	cout << "现有N人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一个人开始报数，如此循环，直到剩下K个人为止\n" << endl;

	int n, s, k, m;
	cout<<left;
	cout << "请输入生死游戏的总人数N：";
	cin >> n;
	cout << setw(24) << "请输入游戏开始的位置S：";
	cin >> s;
	cout << setw(24) << "请输入死亡数字M：";
	cin >> m;
	cout << setw(24) << "请输入剩余生者人数K：";
	cin >> k;
	cout << endl;

	System sys(n);
	sys.Run(s, n - k, m);
	cout << endl;
	sys.Output();
	cout << endl;
	return 0;
}