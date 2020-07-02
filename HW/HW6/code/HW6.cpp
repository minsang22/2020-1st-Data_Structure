/*******************************************************************************************************************************
* Name : 윤민상
* Student ID : 20191631
* Program ID : HW6.cpp
* Description :
* - input 파일을 인접 리스트 형태로 만들어주고, 그래프의 기본 연산인 DFS(깊이 우선탐색)를 구현 후 테스트해보기 위한 프로그램이다.
* Algorithm :
* - BuildGraph 함수 : 우선 인수인 data1과 data2로 받은 순서의 인접 리스트가 비어있다면, 값을 할당해준다. 그리고 각각 data1과 data2의
                     Linked List의 마지막까지 while 반복문을 사용해 이동한 후 data1의 인접 리스트의 마지막엔 data2를, data2의 인접 리스트의
                     마지막엔 data1을 link 시켜준다.
* - PrintGrpah 함수 : Graph의 첫 번째 vertices 부터 차례대로 반복문을 돌며 인접 리스트를 출력해준다.
* - DFS 함수 : 우선 인수로 받은 v번째 vertices는 이미 체크 했다는 의미로 visited 배열의 v번째 index를 true로 바꿔준다. 그 후 v번쨰 vertices의
              인접 리스트를 for 반복문으로 순회하며, 만약 visited 배열이 false인 경우엔 아직 방문하지 않은 vertices인 것이므로 그 vertices에 대한
              DFS 함수를 호출해준다.
* Variables :
* - class Node : Graph를 구현하기 위한 클래스이다. int형 변수 data와 Node 포인터 link를 멤버 변수로 가지고 있다.
* - class Graph : Graph를 구현하는 클래스이다. Node 포인터를 원소로 갖는 graph 배열과 bool형 변수를 원소로 갖는 visited 배열,
                  그리고 다양한 ADT들을 멤버 변수로 가지고 있다.
*******************************************************************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

const int maxsize = 10;

/*******************************************************************************************************************************
* class : Node
* description : Node 클래스의 사용 목적은 Graph의 vertices들을 저장하고 인접 리스트에서 Linked List를 구현해주기 위함이다.
* variables :
* - int data : data (vertices)를 저장해주기 위한 int형 변수이다.
* - Node* link : 인접 리스트에서 link를 해주어 Linked List를 만들기 위한 Node의 포인터이다.
*******************************************************************************************************************************/
class Node {
    private:
        int data;
        Node* link;

    public:
        Node(int val){
            data = val;
            link = NULL;
        } 
        friend class Graph;
};

/*******************************************************************************************************************************
* class : Grpah
* description : Graph 클래스의 사용 목적은 DFS를 적용할 그래프를 구현해주기 위함이다.
* variables :
* - Node* graph[maxsize] : Node 포인터를 원소로 갖는 그래프를 인접 리스트로 구현해주기 위한 배열이다.
* - bool visited[maxsize] : bool형 변수를 원소로 갖는 각각의 vertices에 방문했는지의 여부를 체크해주기 위한 배열이다.
*******************************************************************************************************************************/
class Graph {
    private:
        Node* graph[maxsize];
        bool visited[maxsize];

    public:

/*******************************************************************************************************************************
* function : Graph()
* description : Graph()의 사용 목적은 생성자로서 graph 배열과 visited 배열을 초기화해주기 위함이다.
*******************************************************************************************************************************/
        Graph(){
            for (int i = 0; i < maxsize; i++){
                graph[i] = NULL;
                visited[i] = false;
            }
        }

/*******************************************************************************************************************************
* function : BuildGraph
* description : BuildGraph의 사용 목적은 input 파일을 받아와 인접 리스트 형태로 그래프를 구현해주기 위함이다.
* variables :
* - int data1, data2 : input 파일에서 인접 리스트를 만들 데이터를 인자로 받아오기 위한 int형 변수들이다.
* - Node* temp, temp2 : 만약 data1, data2로 받아온 vertices에 대한 인접 리스트가 아직 설정되지 않았다면 할당해 주기 위한 Node형 포인터이다.
* - Node* p, q, r : 인접 리스트의 Linked List에서 마지막 원소 뒤에 link를 해 주기 위해 사용하는 Node형 포인터이다.
*******************************************************************************************************************************/
        void BuildGraph(int data1, int data2){
            if (graph[data1] == NULL){ 
                Node* temp = new Node(data1);
                graph[data1] = temp;
            }
            
            if (graph[data2] == NULL){
                Node* temp2 = new Node(data2);
                graph[data2] = temp2;
            }

            Node* p = graph[data1];
            Node* q = new Node(data2);

            while (p -> link != NULL){ 
                p = p -> link; 
            }

            p -> link = q;
            p = graph[data2];

            Node* r = new Node(data1);

            while (p -> link != NULL) {
                p = p -> link;
            }
            
            p -> link = r;
        }

/*******************************************************************************************************************************
* function : PrintGraph
* description : PrintGraph의 사용 목적은 그래프를 인접 리스트 형태로 출력해주기 위함이다.
* variables :
* - Node* p : 그래프를 인접 리스트 형태로 출력해줄 수 있도록 각 Linked List의 헤드 노드를 할당해주기 위한 Node형 포인터이다.
*******************************************************************************************************************************/
        void PrintGraph(){
            for (int i = 0; i < maxsize; i++) {
                Node* p = graph[i];
                if (p != NULL) { 
                    cout << "Graph[" << i << "]" << " -> ";
                    p = p -> link;
                    while (p != NULL){
                        cout << p -> data << " "; 
                        p = p -> link; 
                    }
                    cout << endl;
                }
            }
        }

/*******************************************************************************************************************************
* class : DFS
* description : DFS의 사용 목적은 그래프를 깊이 우선탐색 방식으로 탐색한 후 출력해주기 위함이다.
* variables :
* - Node* p : 그래프를 깊이 우선탐색 방식으로 순회할 때 노드를 할당해주기 위한 Node형 포인터이다.
*******************************************************************************************************************************/
        void DFS(int v){
            Node* p;
            visited[v] = true; 
            cout << v << " -> "; 
            for (p = graph[v]; p != NULL; p = p -> link) {
                if (!visited[p -> data]) {
                    DFS(p -> data);
                }   
            }
        }

};

int main(){

   Graph graph1;

   ifstream infile; 
   infile.open("hw6.txt");

   int dat1, dat2;
   for (int i = 0; i < 10; i++){
      infile >> dat1 >> dat2;
      graph1.BuildGraph(dat1, dat2);
   }

   cout << "<<    Graph data 1    >>" << endl;
   cout << endl;
   graph1.PrintGraph(); 
   cout << endl;
   cout << "    Depth First Search Result : " << endl;
   graph1.DFS(0); 
   cout << endl;

   Graph graph2;

   for (int i = 0; i < 8; i++) {
      infile >> dat1 >> dat2; 
      graph2.BuildGraph(dat1, dat2);
   }

   cout << endl;
   cout << "<<    Graph data 2    >>" << endl;
   cout << endl;
   graph2.PrintGraph();
   cout << endl;
   cout << "    Depth First Search Result : " << endl;
   graph2.DFS(0);
   cout << endl;

   infile.close();
   return 0;
}