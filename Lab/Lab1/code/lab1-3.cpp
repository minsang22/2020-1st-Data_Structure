#include <iostream>
#include <cstring>

using namespace std;

int mystrcmp(char s1[], char s2[]);
int myconcat(char s1[], char s2[]);

int main(){
    // 1)length 출력 Method1
    char mystring[80];
    cin >> mystring;
    int size = strlen(mystring);
    cout << "mystring length : " << size << endl;

    // 1)length 출력 Method2
    string string1 = "Hello world";
    cout << "string1 length :" << string1.length() << endl;

    //크기비교
    char mystring1[80];
    char mystring2[80];
    cin >> mystring1;
    cin >> mystring2;
    int result = mystrcmp(mystring1, mystring2);
    switch(result){
        case 1:
            cout << '>' << endl;
            break;
        
        case 0:
            cout << '=' << endl;
            break;
        
        case -1:
            cout << '<' << endl;
            break;
    }

    //스트링 합치기
    char imstring1[80];
    char imstring2[80];
    cin >> imstring1;
    cin >> imstring2;
    myconcat(imstring1, imstring2);

    return -1;
}

int mystrcmp(char s1[], char s2[]){
    int i = 0;
    int res;
    while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'){
        i++;
    }
    if (s1[i] > s2[i]){
        res = 1;
    }
    else if(s1[i] < s2[i]){
        res = -1;
    }
    else{
        res = 0;
    }
    return res;
}

int myconcat(char s1[], char s2[]){
    int i = 0;
    int j = 0;
    while(s1[i] != '\0'){
        i++;
    }
    while(s2[j] != '\0'){
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';

    cout << "String Concatenation : " << s1 << endl;
    return -1;
}