#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <string>

using namespace std;

struct Node {

	Node *left, *right;
	char c;
	bool isBracket = false;
	Node(){}
	Node(char ch) {
		c = ch;
		left = nullptr;
		right = nullptr;
	}

};

class Tree {

private:

	Node* head;

public:

	Tree(){}

	Tree(string s) {
		head = CreateTree(s);
	}

	~Tree() {
		Remove(head);
	}

	void Remove(Node* node) {
		if (node == nullptr)return;
		Remove(node->left);
		Remove(node->right);
		delete node;
	}

	void CreateBunch(char ch, stack<char> &signStack,stack<Node*> &nodeStack) {
		Node* father = new Node(ch);
		father->right = nodeStack.top();
		nodeStack.pop();
		father->left = nodeStack.top();
		nodeStack.pop();
		nodeStack.push(father);
	}

	Node* CreateTree(string s) {
		stack<char> signStack;
		stack<Node*> nodeStack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0'&&s[i] <= '9') {				
				nodeStack.push(new Node(s[i]));
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!signStack.empty()) {
					CreateBunch(signStack.top(), signStack, nodeStack);
					signStack.pop();
				}
				signStack.push(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/') {
				if (signStack.empty())
					signStack.push(s[i]);
				else if (signStack.top() == '+' || signStack.top() == '-')
					signStack.push(s[i]);
				else {
					CreateBunch(signStack.top(), signStack, nodeStack);
					signStack.pop();
				}
			}
			else if (s[i] == '(') {
				int flag = 1,start = i;
				while (flag) {
					i++;
					if (s[i] == ')')flag--;
					if (s[i] == '(')flag++;
				}
				Node* result = CreateTree(s.substr(start + 1, i - start - 1));
				result->isBracket = true;
 				nodeStack.push(result);
			}
			
		}
		while (!signStack.empty()) {
			CreateBunch(signStack.top(), signStack, nodeStack);
			signStack.pop();
		}
		return nodeStack.top();
	}

	void Front(Node* node) {
		if (node == nullptr)return;
		cout << node->c;
		Front(node->left);
		Front(node->right);
	}

	void Middle(Node* node) {
		if (node == nullptr)return;
		if (node->isBracket)cout << "(";
		Middle(node->left);
		cout << node->c;
		Middle(node->right);
		if (node->isBracket)cout << ")";
	}

	void Back(Node* node) {
		if (node == nullptr)return;
		Back(node->left);
		Back(node->right);
		cout << node->c;
	}

	Node* GetHead() {
		return head;
	}
};

int main() {

	cout << left;
	cout << setw(16) << "请输入表达式：";
	string s;
	cin >> s;
	Tree tree(s);
	cout << endl;
	cout << setw(16) << "波兰表达式：";
	tree.Front(tree.GetHead());
	cout << "\n" << endl;
	cout << setw(16) << "中缀表达式：";
	tree.Middle(tree.GetHead());
	cout << "\n" << endl;
	cout << setw(16) << "逆波兰表达式：";
	tree.Back(tree.GetHead());
	cout << "\n" << endl;
	return 0;

}