#include <iostream>
using namespace std;

class Node {
private:
   int data;
   Node* link;
   friend class Htable;

public:
   Node(int value) {
      data = value;
      link = 0;
   }
};

class Htable {
private:
   Node* head;
   int index;
   Node* list[7];

public:
   Htable() {
      for (int i = 0; i < 7; i++) {
         list[i] = 0;
      }
   }
   int hash_function(int key) {
      index = key % 7;
      return index;
   }
   bool find_key(int key) {
      index = hash_function(key);
      Node* p = list[index];
      if (p == 0) {
         return false;
      }
      else {
         while (p != 0 and p->data != key) {
            p = p->link;
         }
         if (p == 0) {
            return false;
         }
         else {
            return true;
         }
      }
   }
   void insert_key(int key) {
      if (find_key(key)) { 
         return;
      }
      else {
         index = hash_function(key);
         if (list[index] == 0) {
            Node* p = new Node(key);
            list[index] = p;
         }
         else {
            Node* p = list[index];
            Node* q = new Node(key);
            while (p->link != 0) {
               p = p->link;
            }
            p->link = q;
         }
      }
   }
   void delete_key(int key) {
      if (!find_key(key)) { 
         cout << "Key not found" << endl;
         return;
      }
      else {
         index = hash_function(key);
         Node* p = list[index];
         if (p->link == 0) { 
            list[index] = 0;
            delete p;
         }
         else if (p->data == key) { 
            Node* q = p->link;
            delete p;
            list[index] = q;
         }
         else {
            Node* q = p;
            while (p->data != key) {
               q = p;
               p = p->link;
            }
            q->link = p->link;
            delete p;
         }
      }
   }
   void print() {
      for (int i = 0; i < 7; i++) {
         cout << "LinkT[" << i << "] : ";
         Node* p = list[i];
         while (p != 0) {
            cout << p->data << " ";
            p = p->link;
         }
         cout << "    ";
      }
      cout << endl;
   }
};

int main() {
   Htable hashing;

   char command;
   int key;
   while(command != 'q'){
       cout << "Enter command (i, f, d, q) : ";
       cin >> command;

       switch(command){
            case 'i' :
                cout << "Enter Key : ";
                cin >> key;
                hashing.insert_key(key);
                hashing.print();
                cout << endl;
                break;
            
            case 'f' :
                cout << "Enter Key : ";
                cin >> key;
                if(hashing.find_key(key)){
                    cout << "Key is found" << endl;
                }

                else{
                    cout << "Key not found" << endl;
                }
                hashing.print();
                cout << endl;
                break;
            
            case 'd' :
                cout << "Enter Key : ";
                cin >> key;
                hashing.delete_key(key);
                hashing.print();
                cout << endl;
                break;
            
            case 'q' :
                hashing.print();
                cout << endl;
                break;
       }
   }
}