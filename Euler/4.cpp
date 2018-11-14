#include<iostream>
using namespace std;
/* 4. Maximum palindrom that can be presented by two 3-digit integer */
int main(){
  int prod;
  int temp;
  int rev;
  int palmax=0;
  for(int i=100; i<1000; i++){
    for(int j=i; j<1000; j++){
      prod = i * j;
      rev = 0;
      for(temp = prod; temp > 0; temp /= 10){
        rev = 10 * rev + (temp % 10);
      }
      if(prod == rev){
        if(palmax < rev) palmax = rev;
      }
    }
  }
  cout << palmax << endl;
}
