/*******************************************************************************************************************************
* Name : 윤민상
* Student ID : 20191631
* Program ID : HW7.cpp
* Description : 
* - Kruskal 알고리즘을 이용해 그래프에서 MST를 얻어내기 위한 ADT들을 구현한 후 테스트해보기 위한 프로그램이다.
* Algorithm :
* - sorted 함수 : mst 배열을 for문을 통해 검사하며 cost 값을 저장해둔 c를 비교해줌으로써 mst 배열을 c순으로 정렬해준다.
* - kruskal 함수 : 최소의 cost를 가진 간선을 선택하고, 선택한 간선을 사용해 MST를 만들 시 사이클이 형성되는지 Union Find 방식을 이용해 
                  판단해주고, 만약 형성되지 않는다면 그 간선을 선택해주는 형식으로 Kruskal 알고리즘을 사용한 MST를 만들어준다.
* Variables :
* - const int edge : data 파일로 넣어줄 그래프의 간선의 갯수를 미리 지정해놓기 위한 int형 상수이다.
* - const int V : data 파일로 넣어줄 그래프의 정점의 갯수를 미리 지정해놓기 위한 int형 상수이다.
* - int TotalC : MST의 최종 cost를 저장해주기 위한 int형 변수이다.
* - char unionf : Union Find 방식을 사용하기 위한 char형 array이다.
* - struct MST : Kruskal 알고리즘을 이용해 MST를 얻기 위한 구조체이다. 간선을 통해 이어지는 양쪽 정점을 의미하는 char형 변수인 x와 y, 그리고
                 각 간선의 cost를 의미하는 int형 변수 c를 멤버 변수로 가지고 있다.
*******************************************************************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

const int edge = 10;
const int V = 6;
int TotalC;
char unionf[V] = { 0, };

/*******************************************************************************************************************************
* struct : MST
* description : MST의 사용목적은 Kruskal 알고리즘을 이용해 MST를 얻어내기 위함이다.
* variables :
* - char x, y : 간선을 통해 이어지는 양쪽 정점을 저장하기 위한 char형 변수들이다.
* - int c : 간선의 cost를 저장하기 위한 int형 변수이다.
*******************************************************************************************************************************/
struct MST {
	char x;
	char y;
	int c;
};

MST mst[10]; //미리 MST를 만들 구조체를 선언해주고 함수를 통해 mst를 이용하도록 하는 방식을 씀.

/*******************************************************************************************************************************
* function : arrinit()
* description : arrinit의 사용목적은 Union Find 방식을 사용하기 위해 unionf 배열을 원하는 값으로 초기화해주기 위함이다.
*******************************************************************************************************************************/
void arrinit() {
	for (int i = 0; i < V; ++i) {
		unionf[i] = i;
	}
}

/*******************************************************************************************************************************
* function : Display()
* description : Display의 사용목적은 mst 배열에 저장되어 있는 현재의 그래프 혹은 MST를 출력해주기 위함이다.
*******************************************************************************************************************************/
void Display() {	
	for (int i = 0; i < edge; ++i) {
		cout << mst[i].x << " " << mst[i].c << " " << mst[i].y << " " << "    ";
        if(i == 4){ //보기 좋게(출력 예시와 맞추도록) 값을 출력하기 위해 넣어준 임의의 if문.
            cout << endl;
        }
	}
	cout << endl;
}

/*******************************************************************************************************************************
* function : sorted()
* description : sorted의 사용목적은 인접 리스트 형태로 받아온 data를 cost순으로 정렬해주기 위함이다.
* variables :
* - temp : data를 정렬하는 과정에서 값들을 잠시 저장해주기 위한 MST 구조체형 변수이다.
*******************************************************************************************************************************/
void sorted(){
   for (int i = 0; i < edge-1; i++) {
      for (int j = 0; j < edge-1; j++) {
         if (mst[j].c > mst[j + 1].c){
            MST temp = mst[j];
            mst[j] = mst[j + 1];
            mst[j + 1] = temp;
         }
      }
   }
}

/*******************************************************************************************************************************
* function : kruskal()
* description : kruskal의 사용목적은 Kruskal 알고리즘을 이용해 MST를 만들고 출력해주는 동시에 MST의 Total Cost까지 구해주기 위함이다.
* variables :
* - TotalC : MST의 Total Cost를 저장해주기 위한 int형 변수이다.
* - int cnt : 출력 형식을 깔끔히 맞춰주기 위해 MST의 Edge 갯수를 저장하는 int형 변수이다.
*******************************************************************************************************************************/
void kruskal() {

	TotalC = 0;
    int cnt = 1;

	for (int i = 0; i < edge; ++i) {
		if (unionf[mst[i].x - 65] < unionf[mst[i].y - 65]) {
			int find = unionf[mst[i].y - 65];
			for (int j = 0; j < V; ++j) {
				if (unionf[j] == find) {	
					unionf[j] = unionf[mst[i].x - 65];
				}
			}
			TotalC += mst[i].c;

			cout << "Edge " << cnt++ << " : " << mst[i].x << " " << mst[i].c << " " << mst[i].y << " " << endl;
		}
		else if (unionf[mst[i].x - 65] > unionf[mst[i].y - 65]) {
			int find = unionf[mst[i].y - 65];
			for (int j = 0; j < V; ++j) {
				if (unionf[j] == find) {	
					unionf[j] = unionf[mst[i].y - 65];
				}
			}
			TotalC += mst[i].c;

			cout << "Edge " << cnt++ << " : " << mst[i].x << " " << mst[i].c << " " << mst[i].y << " " << endl;
		}
	}
}

int main() {

	ifstream infile;
	infile.open("hw7.txt");
	for (int i = 0; i < edge; i++){
		infile >> mst[i].x >> mst[i].c >> mst[i].y;
    }

    cout << "<< HW7 MST by Kruskal's >>" << endl;

	cout << "1. Input Data : " << endl;
	Display();
    cout << endl;

	sorted();
	cout << "2. Sorted Data : " << endl;
	Display();
    cout << endl;

	arrinit();
    cout << "3. Minimum Spanning Tree" << endl;
    cout << endl;
	kruskal();
    
    cout << endl;
    cout << "4. Final cost for Kruskal is " << TotalC << endl;
}
