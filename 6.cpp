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
	cout << setw(16) << "**" << setw(28) << "���׹���ϵͳ" << "**" << endl;
	cout << setfill('=') << setw(46) << "=" << endl;
	cout << setfill(' ') << setw(13) << "**" << setw(31) << "��ѡ��Ҫִ�еĲ�����" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "A --- ���Ƽ�ͥ" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "B --- ��Ӽ�ͥ��Ա" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "C --- ��ɢ�ֲ���ͥ" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "D --- ���ļ�ͥ��Ա����" << "**" << endl;
	cout << setw(15) << "**" << setw(29) << "E --- �˳�����" << "**" << endl;
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
		cout << node->name << "�ĵ�һ�������ǣ�";
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
		cout << "������Ҫ������ͥ���˵�������";
		cin >> fatherName;
		Node* father = nullptr;
		Search(head, fatherName, father);
		while (father == nullptr) {
			cout << "���˲����ڣ����������룡" << endl;
			cin >> fatherName;
			Search(head, fatherName, father);
		}
		cout << "������" << fatherName << "�Ķ�Ů������";
		int n;
		cin >> n;
		cout << "����������" << fatherName << "�Ķ�Ů��������";
		while (n--) {
			cin >> childName;
			Node* nd = new Node(childName);
			father->AddChild(nd);
		}
		OutChild(father);
	}

	void AddChild() {

		string fatherName, childName;
		cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
		cin >> fatherName;
		Node* father = nullptr;
		Search(head, fatherName, father);
		while (father == nullptr) {
			cout << "���˲����ڣ����������룡" << endl;
			cin >> fatherName;
			Search(head, fatherName, father);
		}
		cout << "������" << father->name << "����ӵĶ��ӣ���Ů������������";
		cin >> childName;
		Node* nd = new Node(childName);
		father->AddChild(nd);
		OutChild(father);
	}

	void RemoveChild() {

		cout << "������Ҫ��ɢ��ͥ���˵�������";
		string fatherName;
		cin >> fatherName;
		Node* father = nullptr;
		Search(head, fatherName, father);
		while (father == nullptr) {
			cout << "���˲����ڣ����������룡" << endl;
			cin >> fatherName;
			Search(head, fatherName, father);
		}
		cout << "Ҫ��ɢ��ͥ�����ǣ�" << fatherName << endl;
		OutChild(father);
		for (Node* nd : father->child) {
			Remove(nd);
		}
		father->child.clear();
	}

	void ChangeName() {

		string afterName, nowName;
		cout << "������Ҫ������������Ŀǰ������";
		cin >> nowName;
		Node* father = nullptr;
		Search(head, nowName, father);
		while (father == nullptr) {
			cout << "���˲����ڣ����������룡" << endl;
			cin >> nowName;
			Search(head, nowName, father);
		}
		cout << "��������ĺ��������";
		cin >> afterName;
		father->name = afterName;
		cout << nowName << "�Ѹ���Ϊ" << afterName << endl;
	}

};

int main() {

	OutUI();
	cout << "���Ƚ���һ�����ף�\n���������ȵ�������";
	string sname;
	cin >> sname;
	cout << "�˼��׵������ǣ�" << sname << endl;
	System sys(sname);
	int flag = 1;
	while (flag) {
		cout << "\n��ѡ��Ҫִ�еĲ�����";
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