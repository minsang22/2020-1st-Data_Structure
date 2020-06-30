#include <iostream>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int value) {
		data = value;
		next = NULL;
	}
};

class List {
	private:
		Node *head;
	public:
		List();
		void insert(int data);
		void Delete(int num);
		void Print();
		void search(int num);
		void PrintLast();
		void PrintNth(int num);
		void quit();
};

List::List(){
	head = NULL;
}

void List::insert(int data) {
	Node *temp = new Node(data);
	Node *p = head;
	Node *q = 0;

	if (head == 0) {
		head = temp;
	}

	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}

	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			temp->next = p;
			q->next = temp;
		}
		else {
			q->next = temp;
		}
	}
}

void List::Delete(int num) {
	Node *p = head;
	Node *q = 0;

	if (head == 0)
		cout << "List is Empty" << endl;

	else if (head->data == num) {
		head = head->next;
		delete p;
	}

	else {
		while (p != 0 && p->data != num) {
			q = p;
			p = p->next;
		}

		if (p != 0) {
			q->next = p->next;
			delete p;
		}

		else {
			cout << num << " is not in the list" << endl;
		}
	}
}

void List::Print() {
	Node *p;
	if (head != 0) {
		p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List is empty!" << endl;
	}
}

void List::search(int num) {
	Node *p;

	if (head != 0) {
		p = head;
		while (p != 0 && p->data != num) {
			p = p->next;
		}
		if (p != 0) {
			cout << p->data << " is found." << endl;
		}
		else {
			cout << num << " is not in the list." << endl;
		}
	}
	else {
		cout << "List is empty" << endl;
	}
}

void List::PrintLast() {
	Node *p;
	Node *q = 0;

	if (head == 0)
		cout << "List is Empty" << endl;

	else {
		p = head;
		while (p != 0) {
			q = p;
			p = p->next;
		}
		cout << "Last node : " << q->data << endl;
	}
}

void List::PrintNth(int num) {
	Node *p = head;
	
	if (head == 0)
		cout << "List is Empty" << endl;
	else {
		p = head;
		for (int i = 0; i < num - 1; i++) {
			p = p->next;
		}
		if (p != 0)
			cout << num << " 번째 노드 " << p->data << endl;
		else
			cout << "Not found" << endl;
	}
}

void List::quit() {
	Node *p;
	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

List sll;

void Test(){
	int a, b;
	
	cout << "Command : 1) insert, 2) delete, 3) search, 4) printlist, 5) printLast, 6) printNth, 7) quit => " ;
	cin >> a;

	switch(a){
		case 1:
			cout << "Input a number => ";
			cin >> b;

			sll.insert(b);
			break;
		
		case 2:
			cout << "Input a number => ";
			cin >> b;

			sll.Delete(b);
			break;
		
		case 3:
			cout << "Enter a number => ";
			cin >> b;

			sll.search(b);
			break;

		case 4:
			sll.Print();
			break;

		case 5:
			sll.PrintLast();
			break;
		
		case 6:
			cout << "Enter Nth => ";
			cin >> b;
			
			sll.PrintNth(b);
			break;

		case 7:
			sll.quit();
			break;
	}

}

int main() {
	for(int i = 0; i < 14; i++){
		Test();
	}
	return -1;
}