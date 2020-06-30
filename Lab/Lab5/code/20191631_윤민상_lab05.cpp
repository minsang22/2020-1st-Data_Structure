#include <iostream>

using namespace std;

class Stack {
public:
   char *stack;
   int top;
   int size;

   Stack(int value);
   int IsFull();
   int IsEmpty();
   void push(char str);
   char pop();
   void displayStack();
};

Stack::Stack(int value) {
   top = -1;
   size = value;
   stack = new char[size];
}

int Stack::IsFull() {
   if (top == size - 1) {
      return 1;
   }
   else {
      return 0;
   }
}

int Stack::IsEmpty() {
   if (top == -1) {
      return 1;
   }
   else {
      return 0;
   }
}

void Stack::push(char str) {
   if (IsFull()){
       cout<< "Stack is Full ! "<<endl;
       return;
   }
      
   else
      stack[++top] = str;
}

char Stack::pop() {
   if (IsEmpty())
   {
       cout<< "Stack is Empty ! "<<endl;
       return -1;
   }
   else
      return stack[top--];
}

void Stack::displayStack() {
   int sp;
   if (IsEmpty()) {
      cout << "Stack is empty ! " << endl;
   }
   else {
      sp = top;
      cout << "Print Stack" << endl;
      while (sp != -1) {
         cout << stack[sp--]<< " ";
      }
      cout << endl;
   }
}

class Queue {
    private:
        int rear;
        int front;
        int size;
        char* queue;
    
    public:
        Queue(int size);
        bool isEmpty();
        bool isFull();
        void enQueue(char value);
        char deQueue();
        void printQueue();
};

Queue::Queue(int size){
    front = -1;
    rear = -1;
    this->size = size;
    queue = new char[size];
}

bool Queue::isEmpty(){
    if(front == rear){
        return true;
    }
    else{
        return false;
    }
}

bool Queue::isFull(){
    if(rear == (size - 1)){
        return true;
    }
    else{
        return false;
    }
}

void Queue::enQueue(char value){
    if(isFull()){
        cout << "Queue is full ! " << endl;
        return;
    }
    else{
        queue[++rear] = value;
    }
}

char Queue::deQueue(){
    if(isEmpty()){
        cout << "Queue is empty ! " << endl;
        return -1;
    }
    else{
        return queue[++front];
    }
}

void Queue::printQueue(){
    if(isEmpty()){
        cout << "Queue is empty ! " << endl;
    }
    else{
        cout << "Print Queue " << endl;
        for(int i = front + 1; i<=rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

class CQueue{
private:
    int front;
    int rear;
    int size;
    char* cqueue;
    int flag;

public:
    CQueue(int size);
    void enqueue(char value);
    char dequeue();
    void printCQueue();
};

CQueue::CQueue(int size){
    front = rear = 0;
    this->size = size;
    cqueue= new char[size];
    flag = 0;
}


void CQueue::enqueue(char value){
    if((front == rear) && (flag == 1)){
        cout << "CQueue is Full ! " << endl;
    }
    else{
        cqueue[rear] = value;
        rear = (rear + 1) % size;
        flag = 1;
    }

}

char CQueue::dequeue(){
    char item;
    if((front == rear) && ( flag == 0 )){
        cout << "CQueue is empty ! " << endl;
        return -1;
    }
    else{
        item = cqueue[front];
        front = (front + 1) % size;
        flag = 0;
        return item;
    }
}

void CQueue::printCQueue(){
    if((front == rear) && (flag == 0)){
        cout << "CQueue is empty ! " << endl;
    }
    else{
        cout << "Print CQueue ";
		int i = front;
		while (i != rear)
		{
			cout << cqueue[i] << " ";
            i = (i + 1) % size;
		}
		cout << endl;
	}
}


int main(){
    Stack s1(2);
    Queue s2(3);
    CQueue s3(3);

    s1.push('a');
    s2.enQueue('b');
    s2.enQueue('c');
    s2.enQueue('d');
    s1.push('e');

    s1.push('F');
    s2.enQueue('G');

    s1.displayStack();

    s2.printQueue();


    cout<< "Output : ";
    cout<< s1.pop() << " ";
    cout<<s2.deQueue()<< " ";
    cout<<s2.deQueue()<< " ";
    cout<<s2.deQueue()<< " ";
    cout<< s1.pop() << endl;

    s1.pop();
    s2.deQueue();

    s3.enqueue('A');
    s3.enqueue('B');
    s3.enqueue('C');
    s3.dequeue();
    s3.enqueue('D');

    s3.printCQueue();

     cout << s3.dequeue()<< " ";
     cout << s3.dequeue()<< " ";
     cout << s3.dequeue()<< " ";

     cout << endl;

     cout << s3.dequeue()<< " ";

return 0;
}




