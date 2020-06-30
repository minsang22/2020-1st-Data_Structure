#include <iostream>
#include <fstream>
#define MAX_SIZE 999

using namespace std;

int BalancedCheck = 0;
int UnbalancedCheck = 0;
int MismatchedCheck = 0;

bool check(char* exp);
bool match(char a,char b);

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
   if (IsFull())
      return;
   else
      stack[++top] = str;
}

char Stack::pop() {
   if (IsEmpty())
      return -1;
   else
      return stack[top--];
}

void Stack::displayStack() {
   int sp;
   if (IsEmpty()) {
      cout << "Stack is empty!" << endl;
   }
   else {
      sp = top;
      while (sp != -1) {
         cout << stack[sp--]<< " ";
      }
      cout << endl;
   }
}

bool check(char* exp) {
    Stack stack(MAX_SIZE);
    for(int i = 0; i < strlen(exp); i++){
        if (exp[i]=='(' || exp[i] == '{' || exp[i] == '['){
            stack.push(exp[i]);
        }
        if (exp[i]==')' || exp[i] == '}' || exp[i] == ']'){
            if(stack.IsEmpty()){
                cout << "The Expression has unbalanced parentheses\n" << endl;
                UnbalancedCheck += 1;
                return false;
            }
            else{
                char temp = stack.pop();
                if (!match(temp, exp[i])){
                    cout << "The Mismatched Parenthes in the Expression are " << temp << " and " << exp[i] << "\n" << endl;
                    MismatchedCheck += 1;
                    return false;
                }
            }
        }
    }

    if(stack.IsEmpty()){
        return true;
    }
    else{
        cout << "The Expression has unbalanced parentheses\n" << endl;
        UnbalancedCheck += 1;
        return false;
    }
}

bool match(char a, char b) {
    switch(a)
    {
    case '(':
        if (b == ')') return true;
        else return false;
        break;
    case '{':
        if (b == '}') return true;
        else return false;
        break;
    case '[':
        if(b == ']') return true;
        else return false;
        break;
    }
    
    return 0;
}

int main() {
   char buffer[80];
   ifstream infile;
   infile.open("Lab4.txt",ios::in);
   while(infile.getline(buffer,80))
   {
       cout<<buffer<<endl;
       bool validity = check(buffer);
       if(validity){
           cout << "The Expression is Valid\n" << endl;
           BalancedCheck += 1;
       }
   } 

   cout << "Total : Balanced : " << BalancedCheck << " Unbalanced : " << UnbalancedCheck << " Mismatched : " << MismatchedCheck << endl;

   return 0;
}