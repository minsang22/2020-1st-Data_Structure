#include <iostream>

using namespace std;

struct Node{
   char data;
   Node *next;
   Node(char value) {
      data = value;
      next = 0;
   }
};

class linkedStack {
private:
	Node *head;

public:
	linkedStack() { head = 0; }
	~linkedStack() {};
	void createStack();
	void push(char);
	char pop();
	int isEmpty();
	void displayStack();
};

void linkedStack::createStack() {
	head = 0;
}

void linkedStack::push(char data) {
	Node *temp = new Node(data);

	if (head == 0)
		head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}

char linkedStack::pop() {
	Node *p;
    char popdata;

	popdata = head->data;
	p = head;
	head = head->next;
	delete p;
	return popdata;
}

int linkedStack::isEmpty() {
	if (head == 0)
		return 1;
	else
		return 0;
}

void linkedStack::displayStack() {
	Node *p;

	if (!isEmpty()) {
		p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Stack is empty" << endl;
}


class linkedQueue {
private :
	Node *front;
	Node *rear;

public:
	linkedQueue() { front = 0; rear = 0; }
	~linkedQueue() {};
	void createQueue();
	void enqueue(char data);
	char dequeue();
	int isEmpty();
	void displayQueue();
};

int linkedQueue::isEmpty() {
	if (front == 0)
		return 1;
	else
		return 0;
}

void linkedQueue::createQueue() {
	front = 0;
	rear = 0;
}

void linkedQueue::enqueue(char data) {
	Node *temp = new Node(data);

	if (front == 0) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}

char linkedQueue::dequeue() {
	Node *p;
	char dequeuedata;

	dequeuedata = front->data;
	p = front;

	if (front == rear) {
		front = 0;
		rear = 0;
	}
	else
		front = front->next;

	delete p;
	return dequeuedata;
}

void linkedQueue::displayQueue() {
	Node *p;

	if (!isEmpty()) {
		p = front;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Queue is empty" << endl;
}


class List {
private:
   Node *head;

public:
   List() { head = NULL; }
   bool isEmpty();
   void InsertNode(char data);
   void displayList();
   void Merge(linkedStack &a, linkedQueue &b);
   void invert();
};

bool List::isEmpty() {
   if (head == NULL){
       return true;
   }

   else {
       return false;
   }
}

void List::InsertNode(char data) {
   Node *temp = new Node(data);
   Node *p, *q;
   p = q = NULL;

   if (head == NULL) {
      temp->data = data;
      head = temp;
   }

   else if (temp->data < head->data) {
      temp->next = head;
      head = temp;
   }

   else {
      p = head;
      while (p != NULL && temp->data > p->data) {
         q = p;
         p = p->next;
      }

      if (p != NULL) {
         temp->next = p;
         q->next = temp;
      }

      else {
         q->next = temp;
      }
   }

}
void List::Merge(linkedStack &a, linkedQueue &b) {
  
   while (!a.isEmpty())
   {
      InsertNode(a.pop());
   }

   while (!b.isEmpty())
   {
      InsertNode(b.dequeue());
   }

}

void List::invert() {
   Node *p = head, *q = 0, *r;

   while (p) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
   }

   head = q;
}

void List::displayList() {
   Node *p;

   if (!isEmpty()) {
      p = head;
      while (p) {
         cout << p->data << " ";
         p = p->next;
      }
      cout << endl;

   }
   else
      cout << "List is empty!\n";
}

int main() {
   linkedStack List1;
   linkedQueue List2;
   List List3;
   
   int menu  = 0;
   char m;

   while(menu != 10){
       cout << "MENU : (1. push, 2.pop, 3.printST, 4. enqueue, 5. dequeue, 6. printQ, 7. Merge, 8. Invert, 9. PrintList, 10. Quit) : ";
       cin >> menu;

       switch (menu){
            case 1:
                cout << "Enter a char to push = > ";
                cin >> m;
                List1.push(m);
                break;

            case 2:
                cout << List1.pop() << " ==> is popped !" << endl;
                break;

            case 3:
                cout << "Stack : ";
                List1.displayStack();
                break;

            case 4:
                cout << "Enter a char to enqueue = > ";
                cin >> m;
                List2.enqueue(m);
                break;

            case 5:
                cout << List2.dequeue() << " ==> is dequed !" << endl;
                break;

            case 6:
                cout << "Queue : ";
                List2.displayQueue();
                break;

            case 7 :
                cout << "List : ";
                List3.Merge(List1, List2);
                List3.displayList();
                break;

            case 8 :
                cout << "List : ";
                List3.invert();
                List3.displayList();
                break;

            case 9 :
                cout << "List : ";
                List3.displayList();
                break;

            case 10 :
                break;
       }
   }

   return -1;
}