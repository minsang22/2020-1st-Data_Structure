#include<iostream>
#include<fstream>
using namespace std;

#define MAX 8
int data[8][8] = { 
	{0,1,1,0,0,0,0,0},
	{1,0,0,1,1,0,0,0},
	{1,0,0,0,0,1,1,0},
	{0,1,0,0,0,0,0,1},
	{0,1,0,0,0,0,0,1},
	{0,0,1,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,1,1,1,0}
};

int data1[6][6] = {
    {0,1,1,0,0,0},
    {1,0,1,1,0,0},
    {1,1,0,0,0,1},
    {0,1,0,0,1,1},
    {0,0,0,1,0,1},
    {0,0,1,1,1,0}

};

class Node{
private:
	int data;
	Node* link;
	friend class Graph;
};

class Graph{
private:
	Node* graph[8];	
	Node *front;
	Node *rear;
	int arr[8][8];	
	bool visited[8];
public:
	Graph():front(0), rear(0){
        init();
    }

	void init(){
        for (int a = 0; a < MAX; a++){
		    graph[a] = 0;
		    visited[a] = false;
		for (int b = 0; b < MAX; b++){
			arr[a][b] = 0;
            }
	    }
    }
    
    void insertGraph(int num1, int num2){
	    Node* temp = new Node();
        temp ->data = num2;

	    if (graph[num1] == 0){
            graph[num1] = temp;
            }

	    else{
		    Node* p = graph[num1];
		    Node* q;
		while (p != 0 && p->data < num2)
		{
			q = p;
			p = p->link;
		}
		q->link = temp;
		temp->link = p;
        }
    }

    void enqueue(int num){
	    Node* temp = new Node();
        temp -> data = num;
	    if (front == 0){
		    front = temp;
		    rear = front;
            }

	    else{
		    rear->link = temp;
		    rear = temp;
            }
    }

    int dequeue(){
	    if (front){
		    Node* p = front;
		    int data = p->data;

		    if (front == rear){
			    front = 0;
			    rear = 0;
                }

            else{
			    front = front->link;
		    }
		    delete p;
		    return data;
            }

        else{
            return 0;
        }
    }

    void bfs(int num){
        Node *p;
	    visited[num] = true;
	    enqueue(num);
	    cout << num << " ";
	    while (front){
		    num = dequeue();
            for (p = graph[num]; p; p = p->link){
			    if (!visited[p->data]){
				    enqueue(p->data);
				    visited[p->data] = true;
				    cout << p->data << " ";
                }
		    }
	    }
	    cout << endl;
    }

	void print(){
        cout << "   ";
	    for (int a = 0; a < MAX; a++){
            cout << 'v' << a << " ";
            }

	    cout << endl;

	    for (int b = 0; b < MAX; b++){
		    cout << 'v' << b << "  ";
		    for (int c = 0; c < MAX; c++){
                cout << data[b][c] << "  ";
                }
            cout << endl;
	    }
    }

    void print2(){
	    cout << "   ";
	    for (int a = 0; a < 6; a++){
            cout << 'v' << a << " ";
        }
	    cout << endl;
	    for (int b = 0; b < 6; b++){
		    cout << 'v' << b << "  ";
		    for (int c = 0; c < 6; c++){
			    cout << data1[b][c] << "  ";
		    }
		    cout << endl;
	    }
    }

	void insert(){
	    for (int a = 0; a < MAX; a++)
		    for (int b = 0; b < MAX; b++){
			    if (data[a][b]){
				    insertGraph(a, b);
				    arr[a][b] = data[a][b];
			    }
		    }
    }

	void insert2(){
	    for (int a = 0; a < 6; a++)
		    for (int b = 0; b < 6; b++){
                if (data1[a][b]){
				    insertGraph(a, b);
				    arr[a][b] = data1[a][b];
			    }
		    }
    }
};


int main()
{
	Graph bfs1;
    cout << "** Adjacency Matrix **" << endl;
	bfs1.insert();
    bfs1.print();
    cout << "Breadth First Search -> ";
    bfs1.bfs(0);
    cout << endl;
    cout << endl;

    Graph bfs2;
    cout << "** Adjacency Matrix **" << endl;
    bfs2.insert2();
    bfs2.print2();
    cout << "Breadth First Search -> ";
    bfs2.bfs(0);
	return 0;
}