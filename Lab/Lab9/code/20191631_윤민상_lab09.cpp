#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
private:
	Node *root;
public:
	Tree();
	bool isEmpty();
	Node* insertTree(Node *ptr,int value);
	void callInsert(int value);
	Node* deleteTree(Node *ptr,int value);
	void callDelete(int value);
	Node* searchTree(Node *ptr,int value);
	void callSearch(int value);
	int leafNode(Node *ptr);
	int callLeafNode();
	void drawTree(Node *ptr,int level);
	void callDrawTree();
	Node* findMax(Node *ptr);
	int nonleaf(Node* p);
    int callNonleaf();
	bool printLevel(Node* p, int level);
    void levelOrder();
};

Tree::Tree()
{
	root = NULL;
}

bool Tree::isEmpty()
{
	if (root == NULL) return true;
	else return false;
}

Node* Tree::insertTree(Node *ptr,int value)
{
	if (ptr == NULL)
	{
		Node *temp = new Node(value);
		ptr = temp;
	}
	else if (value < ptr->data)
		ptr->left = insertTree(ptr->left, value);
	else
		ptr->right = insertTree(ptr->right, value);
	return ptr;
}

void Tree::callInsert(int value)
{
	root = insertTree(root, value);
}

 Node* Tree::deleteTree(Node* ptr, int a) {
        if (ptr == 0) {
            cout << "Not Found" << endl;
        }
        else {
            if (a < ptr->data) {
                ptr->left = deleteTree(ptr->left, a);
            }
            else if (a > ptr->data) {
                ptr->right = deleteTree(ptr->right, a);
            }
            else if ((ptr->left) == 0 && (ptr->right) == 0) {
                ptr = 0;
            }
            else if (ptr->left == 0) {
                Node* p = ptr;
                ptr = ptr->right;
                delete p;
            }
            else if (ptr->right == 0) {
                Node* p = ptr;
                ptr = ptr->left;
                delete p;
            }
            else {
                Node* temp = findMax(ptr->left);
                ptr->data = temp->data;
                ptr->left = deleteTree(ptr->left, ptr->data);
            }
        }
        return ptr;
    }
    void Tree::callDelete(int a) {
        root = deleteTree(root, a);
    }

    Node* Tree::findMax(Node* p) {
        if (p == 0) {
            return 0;
        }
        if (p->right == 0) {
            return p;
        }
        else {
            return findMax(p->right);
        }
    }

Node* Tree::searchTree(Node *ptr, int value)
{
	if (ptr == NULL)
		return NULL;
	else
	{
		if (value == ptr->data) return ptr;
		else if (value < ptr->data)
			ptr = searchTree(ptr->left, value);
		else if (value > ptr->data)
			ptr = searchTree(ptr->right, value);
	}
	return ptr;
}

void Tree::callSearch(int value)
{
	Node *ptr = searchTree(root, value);
	if (ptr)
		cout << value << " is found in the Tree" << endl;
	else
		cout << "Not Found" << endl;
}

int Tree::leafNode(Node *ptr)
{
	int count = 0;
	if (ptr == NULL)
		return count;
	else
	{
		if ((ptr->left == NULL) && (ptr->right == NULL))
			count++;
		else
			count = leafNode(ptr->left) + leafNode(ptr->right);
	}

	return count;
}

int Tree::callLeafNode()
{
	return leafNode(root);
}

void Tree::drawTree(Node* ptr,int level)
{
	if ((ptr != NULL) && level <= 7)
	{
		drawTree(ptr->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
			cout << "    ";
		cout << ptr->data;
		if ((ptr->left != NULL) && (ptr->right != NULL))
			cout << " < " << endl;
		else if (ptr->right != NULL)
			cout << " / " << endl;
		else if (ptr->left != NULL)
			cout << " \\ " << endl;
		else
			cout << endl;
		drawTree(ptr->left, level + 1);
	}
}

void Tree::callDrawTree()
{
	drawTree(root, 1);
}

int Tree::nonleaf(Node* p) {
        int cnt = 0;
        if (p == 0) {
            return cnt;
        }
        else {
            if ((p->left) != 0 or (p->right) != 0) {
                cnt = nonleaf(p->left) + nonleaf(p->right) + 1;
            }
        }
        return cnt;
    }

int Tree::callNonleaf() {
    return nonleaf(root);
}

bool Tree::printLevel(Node* p, int level) {
        if (p == 0) {
            return false;
        }
        if (level == 1) {
            cout << p->data << " ";
            return true;
        }
        else {
            bool left = printLevel(p->left, level - 1);
            bool right = printLevel(p->right, level - 1);
            if (left == false and right == false) {
                return false;
            }
            else {
                return true;
            }
        }
    }

void Tree::levelOrder() {
    int level = 1;
    while (printLevel(root, level)) {
        level++;
    }
	cout << endl;
}

int main() {
    Tree bst;

    int menu = 0;
    int num;

    while(menu != 7){
        cout << "Enter Command : (1. insert 2. delete 3. levelOrder 4. Search 5. Draw 6. NumofNodes 7. Quit) : ";
        cin >> menu;

        switch (menu){
            case 1:
                cout << "Enter a number to insert : ";
                cin >> num;
                bst.callInsert(num);
                break;

            case 2:
                if(bst.isEmpty()){
                    cout << "Tree is empty!" << endl;
                    break;
                }
                else{
                    cout << "Enter a number to delete : ";
                    cin >> num;
                    bst.callDelete(num);
                    break;
                }
            
            case 3:
                if(bst.isEmpty()){
                    cout << "Tree is empty!" << endl;
                    break;
                }
                else{
                    bst.levelOrder();
                    break;
                }

            case 4:
                cout << "Enter a number to search : ";
                cin >> num;
                bst.callSearch(num);
                break;

            case 5:
                bst.callDrawTree();
                break;

            case 6:
                cout << "number of leaves : " << bst.callLeafNode() << "	";
                cout << "number of Nonleaves : " << bst.callNonleaf() << endl;
                break;

            case 7:
                break;
        }
    }

    return -1;
}