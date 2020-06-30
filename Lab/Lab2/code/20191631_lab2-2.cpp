#include <iostream>
#include <string>
#include <fstream>
#define MAX_FIG 7

using namespace std;

typedef struct {      // 구조체 내 변수들 초기화
   char name[10] = {};
   double width = 0;
   double height = 0;
   double area = 0;
   double round = 0;
}Angle;

int srcName(char *name);

int main() {

   Angle fig[MAX_FIG];   // 구조체 배열 선언

   ifstream infile;
   infile.open("lab2-2.dat", ios::in);

   if (infile.fail()) {  
      cout << "can't open the input file" << endl;
      exit(1);
   }

   cout << fixed;
   cout.precision(2);               //결과 출력 시 소수점 둘째자리까지 출력하도록 설정.

   while (!infile.eof()) {            // while문은 데이터가 끝날때까지 반복
      for (int i = 0; i < MAX_FIG; i++) {
         infile >> fig[i].name;
         switch (srcName(fig[i].name)) {
         case 1:         // name == circle 일 때
            infile >> fig[i].round;
            fig[i].area = (fig[i].round*fig[i].round)*3.14;   
            break;
         case 0:         // name == triangle 일 때
            infile >> fig[i].width >> fig[i].height;
            fig[i].area = (fig[i].width*fig[i].height) / 2;     
            break;
         case -1:      // name == rectangle 일 때
            infile >> fig[i].width >> fig[i].height;
            fig[i].area = fig[i].width*fig[i].height;        
            break;
         }
      }
   }

   infile.close();

   for (int i = 0; i < MAX_FIG; i++) {
      if (!strcmp(fig[i].name, "circle")) {
         cout << fig[i].name << " " << fig[i].round << "\t\t" << fig[i].area << endl;
      }
      else {
         cout << fig[i].name << " " << fig[i].width << " " << fig[i].height << "\t" << fig[i].area << endl;
      }
   }

}

int srcName(char *name) {
   if (!strcmp(name,"circle")) return 1;
   else if (!strcmp(name, "triangle")) return 0;
   else return -1;
}