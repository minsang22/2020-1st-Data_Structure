/*******************************************************************************************************************************
* Name : 윤민상
* Student ID : 20191631
* Program ID : HW1.cpp
* Description :
* - data 파일로부터 불러온 행렬을 구조체 배열을 이용해 저장한다.
* - 저장한 행렬을 전치시키고, 전치시킨 행렬을 희소행렬로 표현한다.
* - 행 우선 배열로 저장되어 있는 희소 행렬을 두 가지 방법을 통해(한 가지 방법과 그 방법을 속도 면에서 개선한 방법) 열 우선 배열로 바꿔준다.
* Algorithm : 
* - 먼저, 행렬의 행과 열, 값을 각각 담을 수 있는 int형 변수 세개를 가진 구조체 matrix를 만들어준다.
* - data 파일에서 불러온 행렬을 저장하고, 각각의 함수를 통해 행렬을 전치 / 희소 행렬로 변환 시킬 matrix 구조체 배열들을 선언해준다.
* - data 파일에서 받아온 행렬을 A라는 2차원 구조체 배열에 저장해준다. 2차원 배열이기 때문에 2중 for 문을 돌리면서
*   각각의 index에 행, 열, 값을 row, col, value 변수를 통해 저장해준다.
* - TransA에 2중 for 문으로 A에 저장되어있는 row 값을 col에, col 값을 row에, value 값은 그대로 value에 저장해주는 과정을 통해
*   A를 전치시킨 행렬을 만들어준다.
* - 2중 for 문으로 A의 각각의 index들을 검사하며 0이 아닌 값을 가지고 있는 항의 개수를 ValueNum 변수에 저장해준다.
* - A를 희소 행렬로 표현한 것을 저장할 SparseA의 0번째 index의 row , col, value에는 각각 A의 행의 수, 열의 수, 0이 아닌 값을
*   가지고 있는 항의 수인 6, 6, ValueNum을 저장해준다.
* - SparseA의 0번쨰 index에는 이미 값을 채워넣었기 때문에 1번쨰 index 부터 값을 채워나간다.
*   if(A[i][j].value != 0) 라는 if 문을 통해 A에서 0이 아닌 값을 가진 항의 row, col, value 값을 SparseA의 각각의 index에 저장해서
*   A를 희소 행렬로 표현해준다.
* - TransSparseA에는 행 우선 배열로 저장되어 있는 SparseA를 전치 시켜 열 우선 배열로 만들어 저장해준다.
*   Trans_Sparse() 함수에 인자로 matrix 구조체 배열 a, b를 넣어주면 함수 내에서 a를 전치시켜 b에 저장해준다.
*   우선 SparseA의 0번째 index에 저장해 주었던 것처럼 b[0]의 row, col, value에 각각 a[0]의 col, row, value를 저장해준다.
*   그리고 for 문을 통해 a를 열 별로 전치시켜주고, 다음 내부 for 문을 통해 현재의 열로부터 원소를 찾아준다.
*   그 후 if(a[j].col == i) 코드를 통해 현재 열에 있는 값들(원소들)을 b에 첨가해준다.
* - Fast_TransA에는 TransSparseA와 같은 값이 저장되지만, 전치시켜주는 알고리즘이 fast하게 개선되었다.
*   b[0]의 row, col, value에 값을 저장해 주는 것은 Trans_Sparse() 함수와 같다.
*   그 후 a 행렬에서 각 열에 대한 원소의 개수를 구하고, 이는 전치 행렬 b에서의 각 행에 대한 원소의 갯수가 된다.
*   그리고 이를 이용해 a에서 각 열의 시작점을 구하고, 이는 전치 행렬 b에서의 각 행의 시작점(시작 위치)이 된다.
*   이것들을 토대로 a를 b로 더 빠르게 옮겨준다.
* Variables :
* - struct matrix : 행렬을 저장할 구조체 배열이다. row, col, value 세개의 int형 멤버 변수를 가진다.
* - matrix A[6][6] : data 파일에서 6*6 크기의 행렬을 받아오기 위해 만든 2차원 구조체 배열이다.
* - matrix TransA[6][6] : A를 전치시킨 행렬을 저장하기 위해 만든 6*6 크기의 2차원 구조체 배열이다.
* - matrix SparseA[MAX_SIZE] : A를 희소행렬로 표현한 것을 저장하기 위해 만든 1차원 구조체 배열이다.
*  크기는 6*6의 행렬인 A가 가질 수 있는 희소 행렬의 최대 크기인 36으로 선언하였다.
* - matrix TransSparseA[MAX_SIZE] : SparseA를 열 우선 배열로 전치시켜 저장하기 위해 만든 1차원 구조체 배열이다.
*   크기는 SparseA와 같은 이유로 36으로 선언하였다.
* - matrix Fast_TransA[MAX_SIZE] : 개선된 방법으로 SparseA를 열 우선 배열로 전치시켜 저장하기 위해 만든 1차원 구조체 배열이다.
*   크기는 SparseA와 같은 이유로 36으로 선언하였다.
* - void original() : 입력받은 data 파일을 A에 저장해준 후 A를 출력시켜 주는 함수이다.
* - void Transpose() : A를 전치시킨 행렬을 TransA에 저장해준 후 출력시켜 주는 함수이다.
* - void Sparse() : A를 희소 행렬로 표현 하고 SparseA에 저장해준 후 출력시켜 주는 함수이다.
* - void Trans_Sparse(matrix a[], matrix b[]) : 인자로 받은 a[]를 전치시켜 b[]에 저장해준 후, 출력시켜 주는 함수이다.
* - void Fast_Trans(matrix a[], matrix b[]) : Trans_Sparse 함수보다 개선된 방법으로 인자로 받은 a[]를
    전치시켜 b[]에 저장해준 후, 출력시켜 주는 함수이다.
*********************************************************************************************************************************/

#include <iostream>
#include <fstream>
#define MAX_SIZE 36 //입력 파일이 6*6의 행렬이기 때문에 희소 행렬을 array로 표현할때의 최대 크기는 36이다.

using namespace std;

struct matrix{ //행렬을 저장 할 구조체 matrix를 만들어 준다.
    int row;
    int col;
    int value;
};

void original();
void Transpose();
void Sparse();
void Trans_Sparse(matrix a[], matrix b[]);
void Fast_Trans(matrix a[], matrix b[]);

matrix A[6][6]; 
matrix TransA[6][6];
matrix SparseA[MAX_SIZE];
matrix TransSparseA[MAX_SIZE];
matrix Fast_TransA[MAX_SIZE];


int main(){

    original();
    cout << endl;

    Transpose();
    cout << endl;

    Sparse();
    cout << endl;

    Trans_Sparse(SparseA, TransSparseA);
    cout << endl;

    Fast_Trans(SparseA, Fast_TransA);
    cout << endl;

    return -1;
}

/*******************************************************************************************************************************
* function : original
* description : original의 사용 목적은 data 파일에서 불러온 행렬을 저장해준 후, 출력하는 것이다.
*******************************************************************************************************************************/
void original(){

    ifstream infile;

    infile.open("hw1.txt", ios::in);
    
    if(infile.fail()){ //파일이 열리지 않을 시에 코멘트 출력
        cout << "can't open the input file" << endl;
        exit(1);
    }

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            infile >> A[i][j].value;
            A[i][j].col = i;
            A[i][j].row = j;
            //입력 파일이 6*6의 행렬이므로 2중포문으로 구조체 배열에 행, 열, 값을 각각 저장해준다.
        }
    }

    infile.close(); //hw1.txt 파일을 닫음

    cout << "1) Original Matrix : A " << endl;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cout << A[i][j].value << " ";
        }
        cout << endl;
    }
    
    cout << endl;

}

/*******************************************************************************************************************************
* function : Transpose
* description : Transpose의 사용 목적은 6*6의 행렬을 전치시켜 저장해준 뒤, 출력하는 것이다.
*******************************************************************************************************************************/
void Transpose(){

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            TransA[j][i].value = A[i][j].value;
            TransA[j][i].col =  A[i][j].col;
            TransA[j][i].row = A[i][j].row;
            //A 행렬의 행의 값을 열로, 열의 값을 행으로 넣어서 저장해준다. (전치)
        }
    }

    cout << "2) Transopse of Original matrix A " << endl;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cout << TransA[i][j].value << " ";
        }
        cout << endl;
    }

    cout << endl;

}

/*******************************************************************************************************************************
* function : Sparse
* description : Sparse의 사용 목적은 6*6의 행렬을 희소 행렬로 표현해 저장해준 뒤, 출력하는 것이다.
* variablse :
* - ValueNume : 행렬에서 0이 아닌 값의 개수를 저장하기 위한 int형 변수이다.
* - location : for 문을 돌릴 때 희소 행렬을 저장할 배열의 index 값을 설정해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
void Sparse(){

    int ValueNum = 0;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (A[i][j].value != 0){
                ValueNum += 1;
            }
        }
    }
   
    SparseA[0].row = 6; //A의 행의 수인 6을 저장
    SparseA[0].col = 6; //A의 열의 수인 6을 저장
    SparseA[0].value = ValueNum; //A의 0이 아닌 value의 개수를 저장

    int location = 1; //이미 바로 위에서 SparseA의 0번째 칸에는 값을 저장시켜 놓았기 때문에, 1번째 index부터 배열을 채워나가기 위해 1로 지정해준다.

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (A[i][j].value != 0){
                SparseA[location].row = i;
                SparseA[location].col = j;
                SparseA[location].value = A[i][j].value;
                location += 1;
            }
        }
    }

    cout << "3) Sparse matrix of A - row major " << endl;

    for (int i = 1; i < ValueNum+1; i++){ //0번쨰 칸에는 행렬의 값이 아닌 행의 수, 열의 수, 0이 아닌 값의 수를 저장시켜 놓았기 때문에 for문은 1부터 시작.
        cout << SparseA[i].row << " " << SparseA[i].col << " " << SparseA[i].value << endl;
    }

}

/*******************************************************************************************************************************
* function : Trans_Sparse
* description : Trans_Sparse의 사용 목적은 인자로 받은 a[] 배열을 전치시켜 b[] 배열에 저장해준 후 출력하는 것이다.
* variables :
* - currentb : for 문을 돌릴 때 희소 행렬을 저장할 배열의 index 값을 설정해주기 위한 int형 변수이다.
*******************************************************************************************************************************/
void Trans_Sparse(matrix a[], matrix b[]){ //강의 pdf의 희소 행렬의 전치 수도코드 부분을 참고하고 작성한 코드
    
    int i, j, currentb;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    if (a[0].value > 0) {
        currentb = 1; //위에서 b의 0번째 index에는 이미 값을 저장해 주었기 때문에, 1번째 index부터 배열을 채워나가기 위해 1로 지정해준다.
        for (int i = 0; i < a[0].col; i++){ //a에서 열별로 전치함
            for (int j = 0; j <= a[0].value; j++){ //현재의 열에서부터 값을 찾음
                if (a[j].col == i){ //현재 열에 있는 값을 b에 첨가해줌
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb += 1;
                }
            }
        }
    }

    cout << "4) Transpose of Sparse matrix A - column major " << endl;

    for (int i = 1; i < currentb; i++){
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }

}

/*******************************************************************************************************************************
* function : Fast_Trans
* description : Fast_Trans의 사용 목적은 Trans_Sparse 함수보다 개선된 방법으로 인자로 받은 a[] 배열을 더 빠르게 전치시켜
                b[] 배열에 저장해준 후 출력하는 것이다.
* variablse :
* - row_terms[MAX_SIZE] : 각 index 별로 열의 개수를 저장하기 위한 int형 배열이다.
* - starting_pos[MAX_SIZE] : 각 index 별로 열이 시작되는 위치를 저장하기 위한 int형 배열이다.
* - num_cols : 총 열의 개수를 저장하기 위한 int형 변수이다.
* - num_terms : 총 값의 개수(0이 아닌)를 저장하기 위한 int형 변수이다.
*******************************************************************************************************************************/
void Fast_Trans(matrix a[], matrix b[]){

    int row_terms[MAX_SIZE], starting_pos[MAX_SIZE];
    int i, j, num_cols = a[0].col, num_terms = a[0].value;

    b[0].row = num_cols; //6
    b[0].col = a[0].row; //6
    b[0].value = num_terms; //8

    if (num_terms > 0){
        for (int i = 0; i <num_cols; i++){
            row_terms[i] = 0; //row_terms를 0으로 초기화 시켜준다.
        }

        for (int i = 1; i <= num_terms; i++){
            row_terms[a[i].col]++; // 각 열에 대한 원소의 개수를 저장해준다.
        }

        starting_pos[0] = 1; //각 row terms의 시작점을 구한다.

        for (int i = 1; i < num_cols; i++){ // 특정 열의 값을 가진 개수를 전치 행렬의 행의 개수로 하고, 그만큼 staring_pos의 값 증가.
            starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
        }

        for (int i = 1; i <= num_terms; i++){ //a를 b로 옮긴다.
            j = starting_pos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }

    cout << "5) Fast transpose of Sparse matrix A " << endl;

    for (int i = 1; i < num_terms + 1; i++){
        cout << b[i].row << " " << b[i].col << " " << b[i].value << endl;
    }
    
}