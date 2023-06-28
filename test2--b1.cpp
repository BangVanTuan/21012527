#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getWinner ( string a, string b){
    if (a.size() != b.size()){
        cout << " error \n" << endl;
        return ;
    }
    int n= a.size();
    int score = 0;
    for (int i=0; i< n; i++){
         if (a[i] != 'B' && a[i] != 'K' && a[i] != 'G' ||
          b[i] != 'B' &&  b[i] != 'K' && b[i] != 'G'){
            cout << "error \n";
            return ;
        }
         if (a[i]== 'B' && b[i]== 'K'){
            score +=1;
         }
         else if (a[i]== 'B' && b[i]== 'G'){
            score -=1;
         }
         else if (a[i]== 'G' && b[i]== 'B'){
            score +=1;
         }
         else if (a[i]== 'G' && b[i]== 'K'){
            score -=1;
         }
         else if (a[i]== 'K' && b[i]== 'G'){
            score +=1;
         }
         else if (a[i]== 'K' && b[i]== 'B'){
            score -=1;
         }}
         if (score > 0){
            cout << "A\n" ;}
        if (score ==0 ){
                cout << "hoa\n";    
            }
        if (score <0){
         cout << "B\n";
        }
         
    
};
int main(){
   string a = "BBK";
   string b = "GBB";
   getWinner(a, b);
   return 0;

}
