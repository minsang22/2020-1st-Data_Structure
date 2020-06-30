#include <iostream>
#include <cmath>

using namespace std;
class Heap {
private:
    int max_size;
    int index;
    int* heap;

public:
    Heap(int size) {
        max_size = size;
        index = 0;
        heap = new int[max_size + 1];
    }
    bool isfull() {
        if (index == max_size) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isempty() {
        if (index == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void insert_maxheap(int item) {
        int i;
        if (isfull()) {
            cout << "heap is full" << endl;
            return;
        }
        i = ++index;
        while ((i != 1) && item > heap[i / 2]) {
            heap[i] = heap[i / 2];
            i = i / 2;
        }
        heap[i] = item;
    }
    int delete_maxheap() {
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

    void print() {
        cout << "Heap : ";
        for (int i = 1; i < index + 1; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void search(int n){
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

    int levletest(){
        return int(log2(index)+1);
    }
    
};

int main(){
    Heap maxheap(8);

    int arr[] = { 8, 6, 4, 2, 5, 3 };
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++){
      maxheap.insert_maxheap(arr[i]);
   }


    int menu = 0;
    int num;

    while(menu != 8){
        cout << "Enter Command : (1. insert 2. delete 3. Search 4. print 5. Heap_empty 6. Heap_full 7. leveltest 8. Quit) : ";
        cin >> menu;

        switch (menu){
            case 1:
                cout << "Enter a number to insert : ";
                cin >> num;
                maxheap.insert_maxheap(num);
                maxheap.print();
                break;

            case 2:
                if(maxheap.isempty()){
                    cout << "Heap is empty!" << endl;
                    break;
                }
                else{
                    maxheap.delete_maxheap();
                    maxheap.print();
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
                    maxheap.search(num);
                    break;
                }

            case 4:
                maxheap.print();
                break;

            case 5:
                if(maxheap.isempty()){
                    cout << "Heap is Empty" << endl;
                }
                else{
                    cout << "Heap is not Empty" << endl;
                }
                break;

            case 6:
                if(maxheap.isfull()){
                    cout << "Heap is Full" << endl;
                }
                else{
                    cout << "Heap is not Full" << endl;
                }
                break;

            case 7:
                cout << "Level of Heap is ";
                cout << maxheap.levletest() << endl;
                break;

            case 8:
                break;
        }
    }

}