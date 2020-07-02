/*******************************************************************************************************************************
* Name : 윤민상
* Student ID : 20191631
* Program ID : HW2.cpp
* Description : 
* - data 파일로부터 불러온 중위 표기된 수식을 불러온다.
* - 중위 표기된 수식을 후위 표기(Postfix)로 전환해준다.
* - 후위 표기로 변환한 수식을 후위 연산자를 연산해주는 알고리즘을 통해 결과를 계산해준다.
* Algorithm :
* - 먼저, data 파일에서 불러온 중위 표기 수식을 후위 표기로 전환해줄 때 필요한 char형 data를 담는 Stack 클래스를 구현한다.
* - 그리고, 후위 표기로 전환한 수식의 결과값을 계산할 때 필요한 int형 data를 담는 IntStack 클래스를 구현한다.
* - data 파일에서 불러온 중위 표기 수식을 차례대로 검사하며 숫자는 그대로 출력해주고, 처음으로 나온 연산자는 Stack에 push 해준다.
* - 그 후에도 계속 수식을 검사하며 숫자는 항상 그대로 출력해주고 연산자가 나온다면 Stack의 top 연산자와 우선 순위를 비교해주어 만약 검사중인 연산자의 우선 순위가
*   top 연산자의 우선순위보다 크거나 같을 경우엔 그냥 연산자를 Push 해준다. 만약 그렇지 않다면, top 연산자를 pop 해서 출력 해준 후 검사중이던 연산자를
*   Stack에 Push 해준다. 
* - 만약 좌괄호를 검사한다면 그냥 Push 해주고, 우괄호를 검사하게 된다면 Stack에서 좌괄호를 만날 때까지 계속 pop을 해주며 출력해준다.
*   계속 pop을 해주다 좌괄호를 만나게 된다면 좌괄호는 출력하지 않고 Stack에서 없애준다.
* - 만약 수식이 끝난 것을 확인했다면, Stack에 남아 있던 것들을 모두 pop 하여 출력해서 후위 표기로 전환을 완료해준다.
* - 후위 표기로 전환된 수식은 IntStack을 활용해 계산해준다. 이때의 알고리즘은 아까와 반대로 숫자를 IntStack에 push 해주고, 연산자를 만나면
*   IntStack에 들어있는 2개의 숫자를 pop 해서 꺼내와 연산자에 맞는 연산을 해준 후에 다시 스택에 push 해준다. 이 방식을 반복 실행하여
*   수식이 끝나면 IntStack에 남아있는 숫자를 pop 해서 연산의 결과값을 구한다.
* Variables :
* - char bufferEval[MAX_SIZE] : 후위 표기로 전환된 수식을 저장해놓기 위한 배열이다.
* - class Stack : data 파일에서 불러온 중위 표기 수식을 후위 표기로 전환해줄 때 필요한 char형 data를 담는 Stack 클래스이다.
                  배열을 할당해 주기 위한 char형 포인터변수 *stack, stack의 top을 가르키는 int형 변수 top,
                  stack의 사이즈를 저장해 줄 int형 변수 max_size를 멤버 변수로 가진다.
* - Stack(int size) : stack을 입력받은 크기의 배열로 만들어주는 동시에 top을 -1로 초기화해주는 Stack 클래스의 생성자이다.
* - bool IsFull() : Stack이 가득 찼는지 검사해주고 true 혹은 false로 결과값을 리턴해준다.
* - bool IsEmpty() : Stack이 비었는지 검사해주고 true 혹은 false로 결과값을 리턴해준다.
* - void push(char data) : Stack에 매개변수로 받아온 char형 data를 넣어준다.
* - char pop() : Stack의 top에 들어있는 것을 return 해준 후 top을 1만큼 줄여준다.
* - class IntStack : 후위 표기로 전환된 수식을 계산하는데 필요한 int형 data를 담는 Stack 클래스이다.
                     배열을 할당해 주기 위한 int형 포인터변수 *stack, stack의 top을 가르키는 int형 변수 top,
                     stack의 사이즈를 저장해 줄 int형 변수 max_size를 멤버 변수로 가진다.
* - IntStack(int size) : stack을 입력받은 크기의 배열로 만들어주는 동시에 top을 -1로 초기화해주는 IntStack 클래스의 생성자이다.
* - bool IsFull() : IntStack이 가득 찼는지 검사해주고 true 혹은 false로 결과값을 리턴해준다.
* - bool IsEmpty() : IntStack이 비었는지 검사해주고 true 혹은 false로 결과값을 리턴해준다.
* - void push(int data) : IntStack에 매개변수로 받아온 int형 data를 넣어준다.
* - int pop() : IntStack의 top에 들어있는 것을 return 해준 후 top을 1만큼 줄여준다.
* - int priority(char input) : input(연산자)의 연산 우선순위를 리턴해주는 함수이다.
* - void infixToPostfix(char *buffer) : 입력받은 전위 표기 수식을 후위 표기로 전환해주는 함수이다.
* - int postfixEvaluation(char *buffer) : 후위 표기로 전환된 수식의 결과값을 계산해서 리턴해주는 함수이다.
* - char buffer[MAX_SIZE] : data 파일에서 불러온 중위 표기 수식을 저장해놓기 위한 배열이다.
* - Stack conversion(MAX_SIZE) : 중위 표기 수식을 후위 표기 수식으로 바꿀때 사용하는 Stack이다.
* - IntStack evaluation(MAX_SIZE) : 후위 표기 수식을 계산해줄때 사용하는 IntStack이다. 
*******************************************************************************************************************************/

#include <iostream>
#include <fstream>
#define MAX_SIZE 50 //수식이 어느 정도 길이로 들어올 지는 모르기 때문에 임의적으로 최대 크기를 50으로 설정해주었다.

char bufferEval[MAX_SIZE]; //후위 표기로 바꾼 수식을 저장해 놓을 배열이다.

using namespace std;

class Stack {
public:
	char *stack;
    int top;
	int max_size;

	Stack(int size);
	bool IsFull();
	bool IsEmpty();
	void push(char data);
	char pop();
};

Stack::Stack(int size){
		top = -1;
		stack = new char[size];
		max_size = size;
	}

bool Stack::IsFull() {
	if (top + 1 == max_size) { // top + 1이 max_size와 같으면 Stack이 가득 찬 것이다.
        return true;
    }

	else {
        return false;
    }
}

bool Stack::IsEmpty() {
	if (top == -1){ // top이 -1이라면 Stack이 비어있는 것이다.
        return true;
    }

	else {
        return false;
    }
}

void Stack::push(char data) {
	if (IsFull()) {
        cout << "Stack is Full" << endl;
    }

	else {
		top++;	// top의 크기를 먼저 1만큼 늘려준 후
		stack[top] = data;	// 그 다음 index에 data를 삽입해준다.
	}
}

char Stack::pop() {
	if (IsEmpty()) {	
		cout << "Stack is empty" << endl;
		return 0;
	}

	else {
        return stack[top--]; //stack[top]에 있는 것을 리턴해준 후 top의 크기를 1만큼 줄였다.
    }
}

class IntStack {
public:
    int* stack;
	int top;
	int max_size;

	IntStack(int size);
	bool IsFull();
	bool IsEmpty();
	void push(int data);
	int pop();
};

IntStack::IntStack(int size) {
    top = -1;
    stack = new int[size];
    max_size = size;
}

bool IntStack::IsFull() {
	if (top + 1 == max_size){  // top + 1이 max_size와 같으면 Stack이 가득 찬 것이다.
        return true;
    } 

	else {
        return false;
    }
}

bool IntStack::IsEmpty() {
	if (top == -1) {  // top이 -1이라면 Stack이 비어있는 것이다.
        return true;
    }
    	
	else {
        return false;
    }
}

void IntStack::push(int data) {
	if (IsFull()) {
        cout << "Stack is Full" << endl;
    }

	else {
		top++;	// top의 크기를 먼저 1만큼 늘려준 후
		stack[top] = data;	// 그다음 index에 data를 삽입해준다.
	}
}

int IntStack::pop() {
	if (IsEmpty()) {
		cout << "Stack is empty" << endl;
		return 0;
	}

	else {
        return stack[top--]; // stack[top]에 있는 것을 리턴해준 후 top의 크기를 1만큼 줄였다.
    }
}

int priority(char input); 
void infixToPostfix(char *buffer);
int postfixEvaluation(char *buffer);

int main() {

	char buffer[MAX_SIZE]; // data 파일에서 읽어온 전위 표기 수식을 저장해 주기 위한 배열이다.

	ifstream infile("hw2.txt");
	
	while (infile.getline(buffer, MAX_SIZE)) {	// data 파일을 읽어온다.

		cout << "1) Echo data (infix form) : " << buffer << endl;

		cout << "2) Conversion (postfix form) : ";

		infixToPostfix(buffer);

		cout << endl;

		cout << "3) Result : " << postfixEvaluation(bufferEval) << endl;

        cout << endl;
	}
}

/*******************************************************************************************************************************
* function : priority
* description : priority의 사용 목적은 인자로 받은 좌괄호, 우괄호, 사칙연산자, 그리고 공백과 숫자에 대해서 각각의 우선순위(혹은 switch문에서
                case로 처리하기 위한 임의의 숫자)를 리턴해 주기 위함이다.
*******************************************************************************************************************************/
int priority(char input) {
	// 각각의 return값은 연산자 별 연산 우선순위를 의미한다.
	if (input == ')'){
        return 4;
    }

	else if (input == '*' || input == '/') {
        return 3;
    }

	else if (input == '+' || input == '-') {
        return 2;
    }

	else if (input == '(') {
        return 1;
    }

	else if (input == ' ') {
        return -1; // data 파일에 공백이 있으면 -1을 반환하게 한 후 무시하도록 함
    }

	else{
        return 0;
    }
}

/*******************************************************************************************************************************
* function : infixToPostfix
* description : infixToPostfix의 사용 목적은 전위 표기로 되어있는 수식을 후위 표기로 전환해주기 위함이다.
* variavles :
* - i : buffer의 index로 접근 하기 위한 int형 변수이다.
* - j : bufferEval의 index로 접근 하기 위한 int형 변수이다.
*******************************************************************************************************************************/
void infixToPostfix(char *buffer) {

	Stack conversion(MAX_SIZE);
	
	int i = 0, j = 0;

	while (buffer[i] != '\0') {
		switch (priority(buffer[i])) { // 연산 우선순위(priority) 별로 실행되도록 하였다.
		case 0: // 숫자일 경우는 바로 숫자를 출력해준다.
			bufferEval[j++] = buffer[i]; // 숫자는 bufferEval에 저장해 준다.
			cout << buffer[i] << " ";
			break;

		case 4: // 우괄호의 경우 Stack의 top에 좌괄호가 나올때까지 pop을 해주었다.
			while (conversion.stack[conversion.top] != '(') {
				bufferEval[j] = conversion.pop();
				cout << bufferEval[j++] << " ";
			}
			break;

		case 3: // 연산자가 *, /일 경우와 +, -의 처리 방법 자체는 동일하므로 case 2 와 똑같이 처리되도록 하였다.
		case 2:
			if (priority(buffer[i]) >= priority(conversion.stack[conversion.top])){
                // 새로 들어온 연산자가 기존 스택에 있는 연산자보다 우선순위가 크거나 같으면 Stack에 push 해준다.
                conversion.push(buffer[i]);
            }

			else{ 
				bufferEval[j] = conversion.pop();	// 우선순위가 낮을시 pop을 해준후 새로 들어온 연산자를 Stack에 push 해준다.
				cout << bufferEval[j++] << " ";
				conversion.push(buffer[i]);
			}
			break;

		case 1: // 좌괄호의 경우 바로 Stack에 push 해준다.
			conversion.push(buffer[i]);
			break;
			
		default: // buffer의 내용이 공백일경우 무시하고 지나갈 수 있도록 하였다.
			break; 
		}
		i++;
	}

	while (conversion.top != -1) { // 수식을 끝까지 검사한 후에는 Stack에 남아있는 모든 걸 출력해준다.
		if (conversion.stack[conversion.top] == '(') { // 좌괄호는 출력되지 않도록 하였다.
			conversion.pop();
			continue;
		}
        
		else {
			bufferEval[j] = conversion.pop();
			cout << bufferEval[j++] << " ";
		}
	}

	bufferEval[j] = '\0'; // bufferEval의 마지막에 Null문자를 적용해준다.
}

/*******************************************************************************************************************************
* function : postfixEvaluation
* description : postfixEvaluation의 사용 목적은 후위 표기로 전환한 수식의 결과값을 계산해주기 위함이다.
* variables :
* - i : buffer의 index로 접근하기 위한 int형 변수이다.
* - op1, op2 : IntStack에서 계산을 해주기 위해 pop해온 숫자를 각각 저장하는 int형 변수들이다.
*******************************************************************************************************************************/
int postfixEvaluation(char *buffer) {

	IntStack evaluation(MAX_SIZE);

	int i = 0;
	int op1, op2;

	while (buffer[i] != '\0') { // 똑같이 연산자의 우선순위를 검사하지만 괄호가 없으므로 사칙연산자만 검사해준다.
		switch (priority(buffer[i])) { // char형 정수 -48(='0')을 해주어서 int형 정수로 변환해 주었다.
		case 0:	// 숫자일 때는 IntStack에 push를 해준다.
			evaluation.push(buffer[i]-'0');
			break;

		case 3: // 사칙연산자일 경우엔 각각의 연산자를 확인해서 맞는 방법으로 계산을 해주었다.
		case 2:
			op2 = evaluation.pop();
			op1 = evaluation.pop();

			switch (buffer[i]) { // 각 연산자 별로 연산한 값을 다시 IntStack에 push 해주었다.
			case '+':
				evaluation.push(op1 + op2);
				break;

			case '-':
				evaluation.push(op1 - op2);
				break;

			case '*':
				evaluation.push(op1 * op2);
				break;

			case '/':
				evaluation.push(op1 / op2);
				break;
			}
			break;
		default: // 사칙 연산자가 아니거나 공백일 경우 무시해준다.
			break;
		}
		i++;
	} 
	return evaluation.pop(); // 마지막에 stack에 남아있는 값이 최종적인 연산의 결과값이다.
}