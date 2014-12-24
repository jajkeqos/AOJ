#include <iostream>
using namespace std;

int N;
int keikaDate;

int main(){

 cin >> N;

 while(N--){
   keikaDate = 0;
   int y, m, d;
   cin >> y >> m >> d;
   for(int i = m; i <= 10; i++){ //最初の年
     //最初の月
     if(i == m){
       if(y % 3 == 0 || i % 2 == 1) keikaDate += 20 - d + 1; //3で割れる年か奇数月は20日
       else keikaDate += 19 - d + 1; //それ以外は19日
     }else{ //それ以外の月
       if(y % 3 == 0 || i % 2 == 1) keikaDate += 20; //3で割れる年か奇数月は20日
       else keikaDate += 19; //それ以外は19日
     }
   }

   for(int i = y + 1; i < 1000; i++){ //最初の年は処理したので次の年から
     if(i % 3 == 0) keikaDate += 20 * 10; //3で割れる年はすべて大の月
     else keikaDate += 20 * 5 + 19 * 5;
   }

   cout << keikaDate << endl;
 }

  return 0;
}
