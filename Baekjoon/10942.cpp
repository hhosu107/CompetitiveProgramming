#include <cstring> 
#include <string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string text; 
int min(int a, int b) 
{ 
    int res = a; 
    if(b < a) 
        res = b; 
    return res; 
}
vector<int> L;
  
vector<int> findLongestPalindromicString() 
{ 
    int N = text.length(); 
    int arr[1] = {0};
    if(N == 0){
        L = vector<int>(1);
        return L;
    }
    N = 2*N + 1; //Position count 
    L = vector<int>(N); //LPS Length Array. L[i] means the longest palindrome which has a center as (i-1)/2 index, so if we succeed to calculate the start and and position, we can automatically extract all palindromes by incrementing start and decrementing end until they crosses.
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
    int diff = -1; 
      
    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 2; i < N; i++)  
    { 
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        //If currentRightPosition i is within centerRightPosition R 
        if(diff > 0) 
            L[i] = min(L[iMirror], diff); // Because, if a current center is C and if it has a longest palindrom reaching to R, we can assert that finding palindrome from i has the length at least the min(L[iMirror], diff) ( ..[. (2C-i) .].. C ..[. (i) .]... R. if L[2C-i] < diff, it means that C coveres the left side more than covered by 2C-i position. otherwise, it means C cannot cover the left side that 2C-i position covers. We can extend it from that. )
  
        //Attempt to expand palindrome centered at currentRightPosition i 
        //Here for odd positions, we compare characters and  
        //if match then increment LPS Length by ONE 
        //If even position, we just increment LPS by ONE without  
        //any character comparison 
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
        { 
            L[i]++; 
        } 
  
        if(L[i] > maxLPSLength)  // Track maxLPSLength 
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        //If palindrome centered at currentRightPosition i  
        //expand beyond centerRightPosition R, 
        //adjust centerPosition C based on expanded palindrome. 
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
        //Uncomment it to print LPS Length array 
        //printf("%d ", L[i]); 
    } 
    //printf("\n"); 
    // To print out all subpalindromes from each index:
    for(i=1; i<=N-2; i++){
      start = (i - L[i])/2;
      end = start + L[i] - 1;
      if(start <= end){
        // Uncomment to print LPS at position (i-1)/2 of text.
        /* printf("LPS of string centered at position %d/2 of %s is :", i-1, text.c_str());
        int j;
        for(j=start; j<=end; j++)
          printf("%c", text[j]);
        printf("\n");
        */
      }
    }
    /*
    start = (maxLPSCenterPosition - maxLPSLength)/2; 
    end = start + maxLPSLength - 1; 
    printf("LPS of string is %s : ", text.c_str()); 
    for(i=start; i<=end; i++) 
        printf("%c", text[i]); 
    printf("\n");
    */
    return L;
} 
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int N;
    string s;
    cin >> N;
    vector<int> int_lens = vector<int>(N);
    vector<int> cum_lens = vector<int>(N+1);
    int x;
    for(int i=0; i<N; i++){
      cin >> x;
      s = to_string(x);
      int_lens[i] = s.length();
      cum_lens[i+1] = cum_lens[i] + int_lens[i];
      text += s;
    }
    /* Find palindrome length for each index i of the string tt
     * where tt = '|'.join(chr for chr in text).
     */
    vector<int> palindrome_length_from_center = findLongestPalindromicString();
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
      int l, r;
      cin >> l >> r;
      int right_char_loc = cum_lens[r] - 1;
      int left_char_loc = cum_lens[l - 1];
      int converted_center = right_char_loc + left_char_loc + 1;
      int start = (converted_center - palindrome_length_from_center[converted_center])/2;
      int end = start + palindrome_length_from_center[converted_center] - 1;
      if (start <= left_char_loc && right_char_loc <= end){
        cout << "1\n";
      } else cout << "0\n";
    }
    return 0; 
} 
