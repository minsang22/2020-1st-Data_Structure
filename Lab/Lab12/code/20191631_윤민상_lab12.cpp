#include <iostream>

using namespace std;

int main() {
    int weightgraph[6][6] = {
    {100, 6, 1, 5 ,100, 100},
    {6, 100, 4, 100, 3, 100},
    {1, 4, 100, 5, 6, 5},
    {5, 100, 5, 100, 100, 2},
    {100, 3, 6, 100, 100, 6},
    {100, 100, 5, 2, 6, 100} };

   int cnt = 0;
   int index = 0;
   int cost = 0;
   int vert = 0;
   int vert_temp;
   int temp;
   int list1[6] = { 0, 0, 0, 0, 0, 0};
   char list2[6];
   bool visited[6] = { false, false, false, false, false, false};

   visited[0] = true;
   while (cnt < 5) {
      temp = 100;
      for (int i = 0; i < 6; i++) {

         if (weightgraph[vert][i] != 0 && weightgraph[vert][i] < temp && visited[i] == false) {
            temp = weightgraph[vert][i];
            vert_temp = i;
         }
      }

      if (temp == 100) {
         cout << "No Spanning Tree" << endl;
         break;
      }

      else {
         visited[vert_temp] = true;
         list1[++index] = vert_temp;
         vert = vert_temp;
         cost += temp;
      }
      cnt++;
   }

   for (int i = 0; i < 6; i++) {
      if (list1[i] == 0) {
         list2[i] = '1';
      }
      else if (list1[i] == 1) {
         list2[i] = '2';
      }
      else if (list1[i] == 2) {
         list2[i] = '3';
      }
      else if (list1[i] == 3) {
         list2[i] = '4';
      }
      else if (list1[i] == 4) {
         list2[i] = '5';
      }
      else if (list1[i] == 5) {
         list2[i] = '6';
      }
   }

   cout << "*******   Weighted Graph   *******" << endl;
   cout << endl;
   cout << "         v1     v2     v3     v4     v5     v6" << endl;
   cout << endl;
   for(int i = 0; i < 6; i++){
       cout << "v" << i+1 << "      ";
       for(int j = 0; j < 6; j++){
           if(weightgraph[i][j] > 99){
               cout << weightgraph[i][j] << "    ";
           }
           else if(weightgraph[i][j] > 9){
               cout << " " << weightgraph[i][j] << "    ";
           }
           else{
               cout << "  " << weightgraph[i][j] << "    ";
           }
       }
       cout << endl;
   }
   cout << endl;

   cout << "*****   Minimal Spanning Tree test1   *****" << endl;
   cout << endl;

   for (int i = 0; i < 5; i++) {
      cout << "V" << list2[i] << " , " << "V" << list2[i + 1] << endl;
   }
   cout << "Total = " << cost << endl;
}