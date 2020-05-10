#include <iostream>
#include <fstream>

using namespace std;

int findMin(int data[], int n);
int findMax(int data[], int n);
int findMinPos(int data[], int n);
int findMaxPos(int data[], int n);

int main(){
    int number = 0;
    int count = 0;

    ifstream infile;
    int data[8];
    infile.open("lab1-2.dat", ios::in);
    if(infile.fail()){
        cout << "can't open the input file" << endl;
        exit(1);
    }
    
    while(infile >> number){
        data[count++] = number;
    }

    int min = findMin(data, sizeof(data)/sizeof(int));
    int minpos = findMinPos(data, sizeof(data)/sizeof(int));
    int max = findMax(data, sizeof(data)/sizeof(int));
    int maxpos = findMaxPos(data, sizeof(data)/sizeof(int));

    cout << "Minimum number is " << min << " at position " << minpos << endl;
    cout << "Maximum number is " << max << " at position " << maxpos << endl;

    return -1;
}

int findMin(int data[], int n){
    int min = data[0];
    for (int i = 1; i<n; i++){
        if(data[i] < min){
            min = data[i];
        }
    }
    return min;
}

int findMax(int data[], int n){
    int max = data[0];
    for (int i = 1; i<n; i++){
        if(data[i] > max){
            max = data[i];
        }
    }
    return max;
}

int findMinPos(int data[], int n){
    int min = data[0];
    int pos = 1;
    for (int i = 1; i<n; i++){
        if(data[i] < min){
            min = data[i];
            pos = i+1;
        }
    }
    return pos;
}

int findMaxPos(int data[], int n){
    int max = data[0];
    int pos = 1;
    for (int i = 1; i<n; i++){
        if(data[i] > max){
            max = data[i];
            pos = i+1;
        }
    }
    return pos;
}