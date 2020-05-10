#include <iostream>
#include <fstream>

using namespace std;

int WordCount(char buffer[]);

int main(){
    ifstream infile;
    char buffer[80];
    int totalwc = 0;

    infile.open("lab1-1.dat", ios::in);

    if(infile.fail()){
        cout << "can't open the input file" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)){    
        cout << buffer << endl;
        cout << "The number of words : " << WordCount(buffer) << endl;
        totalwc += WordCount(buffer);
    }

    cout << "\nTotal Number of Words : " << totalwc << endl;
    return -1;
}

int WordCount(char buffer[]){
    int i = 0;
    bool state = false;
    //stat는 단어가 진행중인지 아닌지에 대한 상태. 단어가 시작시 true, 끝날때 false로 change.
    int wc = 0;

    while (buffer[i] != '\0'){
        if(buffer[i]){
            if (state == false){
                ++wc;
                state = true;
            }
            
            else if(buffer[i] == ' '){
                state = false;
            }
        }
        i++;
    }
    return wc;
}
