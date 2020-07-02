/*******************************************************************************************************************************
* Name : 윤민상
* Student ID : 20191631
* Program ID : HW5.cpp
* Description :
* - Tree를 Heap으로 변환해주고, Heap을 sort하는 등 다양한 함수를 Heap에 적용해보기 위한 프로그램이다.
* Algorithm :
* - insertHeap 함수 : insert 하기 위해 받은 숫자를 부모 노드(heap[i/2])보다 큰 동시에 i( = loop에서 사용되는 int값)이 1이 아닐 때 까지
                     loop를 돌리며 부모 노드를 i번째 노드로 옮겨주는 동시에 i를 2로 나눠주고, 최종적으로 i번째 노드에 입력 받은 숫자를 삽입해준다.
* - deleteHeap 함수 : child의 값이 index의 값보다 작거나 같다면, 자식 노드들을 비교해 더 큰 자식 노드를 찾은 후 부모 노드와 바꿔준다.
                     그 후 parent를 child로 초기화 해준 후, child에는 2를 곱해주어 다음 자식 노드를 검사해준다. 이를 반복하면
                     root 노드에 있던 값을 delete 해줄 수 있다.
* - makeHeap 함수 : 가장 마지막 노드부터 차례대로 부모 노드와 크기를 비교해서 자식 노드의 값이 더 크다면 둘의 자리를 바꾸는 식으로 이진 트리 형태의 배열을
                   max heap의 형태로 바꿔준다.
* - sortHeap 함수 : root 노드의 값과 마지막 노드의 값을 바꿔준 후, 마지막 노드를 제외한 나머지 노드들을 max heap으로 만들어준다. (makeHeap 함수와
                   같은 알고리즘 사용) 이를 반복하면 작은 값부터 큰 값 순서대로 heap을 sort해줄 수 있다.
* Variables :
* - class Heap : max Heap을 구현하기 위한 클래스이다. int형 변수 max_size와 index, int형 포인터 변수 heap을 멤버 변수로 가지고 있다.
* - menu : main문에서 switch문을 통해 heap에 각각 무슨 ADT를 테스트해줄 것인지를 구분해주기 위한 int형 변수이다.
* - tree[10] : 초기 입력 데이터를 이진 트리 형태로 입력해 주기 위해 만든 int형 배열이다. 
*******************************************************************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

/*******************************************************************************************************************************
* class : Heap
* description : Heap의 사용목적은 max heap을 구현해주기 위함이다. 
* variables :
* - max_size : heap의 크기를 표현해주기 위한 int형 변수이다.
* - index : 현재 heap의 마지막 index를 표현하는 int형 변수이다.
* - heap : heap을 담을 배열을 가리키기 위한 int형 포인터 변수이다.
*******************************************************************************************************************************/
class Heap {
private:
    int max_size;
    int index;
    int* heap;

public:
    Heap(int size) {
        max_size = size;
        index = 0;
        heap = new int[max_size + 1]; //index 0이 아닌 1부터 heap을 채울 것이기 때문에 배열의 크기를 max_size + 1로 해줌.
    }

/*******************************************************************************************************************************
* function : isfull()
* description : isfull()의 사용목적은 현재 heap이 가득 찼는지 확인하기 위함이다.
*******************************************************************************************************************************/
    bool isfull() {
        if (index == 12) {
            return true;
        }
        else {
            return false;
        }
    }

/*******************************************************************************************************************************
* function : isempty()
* description : isempty()의 사용목적은 현재 heap이 비어 있는지 확인하기 위함이다.
*******************************************************************************************************************************/
    bool isempty() {
        if (index == 0) {
            return true;
        }
        else {
            return false;
        }
    }

/*******************************************************************************************************************************
* function : insertHeap(int item)
* description : insertHeap의 사용 목적은 heap에 원하는 item을 값으로 가지는 노드를 추가해주기 위함이다.
* variables :
* - item : insert 해줄 값을 받아올 int형 변수이다.
* - i : index의 값을 저장해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
    void insertHeap(int item) {
        int i;
        if (isfull()) {
            cout << "heap is full" << endl;
            return;
        }
        i = ++index;
        while ((i != 1) && item > heap[i / 2]) {
            heap[i] = heap[i / 2]; //부모 노드보다 작은 값을 가지고 있을 시엔 부모 노드를 현재의 index로 옮겨줌.
            i = i / 2;
        }
        heap[i] = item;
    }

/*******************************************************************************************************************************
* function : deleteHeap()
* description : deleteHeap()의 사용목적은 현재 heap에서 가장 큰 값을 삭제해주기 위함이다.
* variables :
* - parent : 부모 노드의 index를 저장해주기 위한 int형 변수이다.
* - child : 자식 노드의 index를 저장해주기 위한 int형 변수이다.
* - temp : heap의 가장 마지막에 있는 값을 저장해주기 위한 int형 변수이다.
* - item : heap에서 delete될 값을 저장해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
    int deleteHeap() {
        if (isempty()) {
            cout << "heap is empty" << endl;
            return 0;
        }
        int parent, child, temp, item;
        item = heap[1];
        temp = heap[index--];
        parent = 1;
        child = 2;
        while (child <= index) {
            if ((child < index) && heap[child] < heap[child + 1]) {
                child++;
            }
            else if (temp >= heap[child]) {
                break;
            }
            heap[parent] = heap[child];
            parent = child;
            child = child * 2;
        }
        heap[parent] = temp;
        return item;
    }

/*******************************************************************************************************************************
* function : printHeap()
* description : printHeap()의 사용목적은 heap을 root 노드부터 차례대로 출력해주기 위함이다.
*******************************************************************************************************************************/
    void printHeap() {
        cout << "Heap : ";
        for (int i = 1; i < index + 1; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

/*******************************************************************************************************************************
* function : searchHeap(int n)
* description : searchHeap의 사용목적은 현재 heap에 원하는 값이 있는지 검색해주기 위함이다.
* variables :
* - n : search 해줄 값을 매개변수로 받아오기 위한 int형 변수이다.
* - find : heap에서 n 값을 찾았는지 여부를 저장해주기 위한 bool형 변수이다.
*******************************************************************************************************************************/
    void searchHeap(int n){
        bool find = false;
        for (int i = 1; i < index + 1; i++){
            if(heap[i] == n){
                find = true;
            }
            }

        if(find){
            cout << n << " is found" << endl;
        }
        else{
            cout << "Not found" << endl;
        }
    }

/*******************************************************************************************************************************
* function : leveltest()
* description : leveltest()의 사용목적은 현재 heap의 level을 return해주기 위함이다.
*******************************************************************************************************************************/
    int leveltest(){
        return int(log2(index)+1);
    }

/*******************************************************************************************************************************
* function : makeHeap()
* description : makeHeap()의 사용목적은 이진 트리 형태로 된 배열을 max heap형태로 만들어주기 위함이다.
* variables :
* - child : 자식 노드의 index 값을 저장해주기 위한 int형 변수이다.
* - j : 부모 노드의 index 값을 저장해주기 위한 int형 변수이다.
* - temp : 마지막 노드의 부모 노드의 data 값을 저장해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
    void makeHeap() {
        for (int i = index / 2; i > 0; i--) {
            int child, j, temp;
            child = 2 * i;
            temp = heap[i];
            while (index >= child) {
                if (index >= child && heap[child] < heap[child + 1]) {//자식들의 값을 비교하여 자식을 변경
                    child++;
                }
                if (temp >= heap[child]) {
                    break;
                }
                j = child / 2;
                heap[j] = heap[child];
                child = child * 2;
            }
            j = child / 2;
            heap[j] = temp;
        }
        cout << "Heap 변환 :   ";
        printHeap();
    }
    
/*******************************************************************************************************************************
* function : sortHeap()
* description : sortHeap()의 사용 목적은 heap을 작은 값부터 큰 값 순서대로 정렬해주기 위함이다.
* variables :
* - a : root 노드와 마지막 노드를 바꿔주기 위해 만든 int형 변수이다.
* - child : 자식 노드의 index를 저장해주기 위한 int형 변수이다.
* - j : 부모 노드의 index를 저장해주기 위한 int형 변수이다.
* - temp : root 노드의 값을 저장해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
    void sortHeap() {
        for (int i = index - 1; i > 0; i--) {
            int a = heap[1];
            heap[1] = heap[i + 1];
            heap[i + 1] = a;
            int child, j, temp;
            child = 2;
            temp = heap[1];
            while (i >= child) {
                if (i > child && heap[child] < heap[child + 1]) {
                    child++;
                }
                if (temp >= heap[child]) {
                    break;
                }
                j = child / 2;
                heap[j] = heap[child];
                child = child * 2;
            }
            j = child / 2;
            heap[j] = temp;
            printHeap();
        }
        cout << "sort 결과 : ";
        printHeap();
    }

/*******************************************************************************************************************************
* function : InsertTree(int item)
* description : InsertTree의 사용목적은 초기 입력 데이터를 max heap의 순서가 아닌 임의의 순서대로 heap에 데이터를 넣어주기 위함이다.
* variables :
* - item : heap에 넣어줄 값을 매개변수로 받아오기 위한 int형 변수이다.
* - i : index 값을 저장해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
    void InsertTree(int item){
        int i;
        i = ++index;
        heap[i] = item;
    }
};

int main(){
    Heap maxheap(11);
    
    int tree[10] = { 26, 5, 77, 1, 61, 11, 59, 15, 48, 19 };
     for (int i = 0; i < sizeof(tree) / sizeof(int); i++){
      maxheap.InsertTree(tree[i]);
   }
    
    int menu = 0;
    int num;

    while(menu != 8){
        cout << "Enter Command : (1. insert 2. delete 3. search 4. print 5. leveltest 6. heapsort 7. makeheap 8. Quit) : ";
        cin >> menu;

        switch (menu){
            case 1:
                cout << "Enter a number to insert : ";
                cin >> num;
                maxheap.insertHeap(num);
                maxheap.printHeap();
                break;

            case 2:
                if(maxheap.isempty()){
                    cout << "Heap is empty!" << endl;
                    break;
                }
                else{
                    maxheap.deleteHeap();
                    maxheap.printHeap();
                    break;
                }
            
            case 3:
                if(maxheap.isempty()){
                    cout << "Heap is empty!" << endl;
                    break;
                }
                else{
                    cout << "Enter a number to search : ";
                    cin >> num;
                    maxheap.searchHeap(num);
                    break;
                }

            case 4:
                maxheap.printHeap();
                break;

            case 5:
                cout << "Level of Heap is ";
                cout << maxheap.leveltest() << endl;
                break;

            case 6:
                maxheap.sortHeap();
                break;

            case 7:
                maxheap.makeHeap();
                break;

            case 8:
                break;
        }
    }

}