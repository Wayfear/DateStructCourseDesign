#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Node {

	string name;
	vector<Node*> child;

	Node(string s):name(s) { }
	Node() {}

	void AddChild(Node* node) {
		child.push_back(node);
	}
};


void OutUI() {

	cout << left;
	cout << setw(16) << "**" << setw(28) << "家谱管理系统" << "**" << endl;
	cout << setfill('=') << setw(46) << "=" << endl;
	cout << setfill(' ') << setw(13) << "**" << setw(31) << "请选择要执行的操作：" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "A --- 完善家庭" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "B --- 添加家庭成员" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "C --- 解散局部家庭" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "D --- 更改家庭成员姓名" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "E --- 退出程序" << "**" << endl;
	cout << setfill('=') << setw(46) << "=" << endl;

}

class System {

private:

	Node *head;

public:

	System(string s) {
		head = new Node(s);
	}

	~System(){
		Remove(head);
	}

	void Remove(Node* node) {
		for (Node* nd : node->child) {
			Remove(nd);
		}
		delete node;
	}

	void OutChild(Node* node) {
		cout << node->name << "的第一代子孙是：";
		for (Node* a : node->child) {
			cout << a->name << '\t';
		}
		cout << endl;
	}

	void Search(Node* node, string name, Node* &result) {
		if (node->name == name) {
			result = node;
			return;
		}
		for (Node* a : node->child) {
			Search(a, name, result);
		}
	}

	void Finish() {

		string fatherName, childName;
		cout << "请输入要建立家庭的人的姓名：";
		cin >> fatherName;
		Node* father = nullptr;
		Search(head, fatherName, father);
		while (father == nullptr) {
			cout << "此人不存在，请重新输入！" << endl;
			cin >> fatherName;
			Search(head, fatherName, father);
		}
		cout << "请输入" << fatherName << "的儿女人数：";
		int n;
		cin >> n;
		cout << "请依次输入" << fatherName << "的儿女的姓名：";
		while (n--) {
			cin >> childName;
			Node* nd = new Node(childName);
			father->AddChild(nd);
		}
		OutChild(father);
	}

	void AddChild() {

		string fatherName, childName;
		cout << "请输入要添加儿子（或女儿）的人的姓名：";
		cin >> fatherName;
		Node* father = nullptr;
		Search(head, fatherName, father);
		while (father == nullptr) {
			cout << "此人不存在，请重新输入！" << endl;
			cin >> fatherName;
			Search(head, fatherName, father);
		}
		cout << "请输入" << father->name << "新添加的儿子（或女儿）的姓名：";
		cin >> childName;
		Node* nd = new Node(childName);
		father->AddChild(nd);
		OutChild(father);
	}

	void RemoveChild() {

		cout << "请输入要解散家庭的人的姓名：";
		string fatherName;
		cin >> fatherName;
		Node* father = nullptr;
		Search(head, fatherName, father);
		while (father == nullptr) {
			cout << "此人不存在，请重新输入！" << endl;
			cin >> fatherName;
			Search(head, fatherName, father);
		}
		cout << "要解散家庭的人是：" << fatherName << endl;
		OutChild(father);
		for (Node* nd : father->child) {
			Remove(nd);
		}
		father->child.clear();
	}

	void ChangeName() {

		string afterName, nowName;
		cout << "请输入要更改姓名的人目前姓名：";
		cin >> nowName;
		Node* father = nullptr;
		Search(head, nowName, father);
		while (father == nullptr) {
			cout << "此人不存在，请重新输入！" << endl;
			cin >> nowName;
			Search(head, nowName, father);
		}
		cout << "请输入更改后的姓名：";
		cin >> afterName;
		father->name = afterName;
		cout << nowName << "已更名为" << afterName << endl;
	}

};

int main() {

	OutUI();
	cout << "首先建立一个家谱！\n请输入祖先的姓名：";
	string sname;
	cin >> sname;
	cout << "此家谱的祖先是：" << sname << endl;
	System sys(sname);
	int flag = 1;
	while (flag) {
		cout << "\n请选择要执行的操作：";
		char key;
		cin >> key;
		switch (key) {
		case 'A':
			sys.Finish();
			break;
		case 'B':
			sys.AddChild();
			break;
		case 'C':
			sys.RemoveChild();
			break;
		case 'D':
			sys.ChangeName();
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