#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/* 1790: 1234567891011121314151617181920212223.....
 * Given k'th most significant digit, tell what digit is it.
 * Sol) For integers having length l,
 * there are 10^l - 10^{l-1} integers of that = 9 * 10^{l-1},
 * and thus it takes 9l * 10^{l-1} digits.
 * Thus we first measure what k belongs to what length of the integers,
 * and then measure what number it contains.
 */

int main(){
  long long int N, K;
  cin >> N >> K;
  long long int lengthi = 1;
  long long int lengthC = 0;
  long long int lengthN = 0;
  long long int count = 9;
  for(int i=1; i <= N; i*=10, lengthi++){
    if(10 * i - 1 >= N){
      lengthN += (N - i + 1) * lengthi;
    }
    else lengthN += 9 * i * lengthi;
    if(lengthN >= K){
      // (K - lengthC-1)/lengthi means the index of the number that contains Kth digit
      long long int index = (K-lengthC-1)/lengthi;
      long long int number = i + index;
      // Find the exact index that the current digit belongs
      long long int loc = (lengthi - 1) - (K - lengthC - 1) % lengthi;
      while(loc > 0){
        number /= 10;
        loc--;
      }
      cout << number % 10 << endl;
      break;
    }
    lengthC = lengthN;
  }
  if(lengthN < K) printf("-1\n");
  return 0;
}
