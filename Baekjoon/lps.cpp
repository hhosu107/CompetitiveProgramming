#include <cstdio> 
#include <cstring> 
#include <string>
#include<iostream>

/* 10942. Is it palindrome?
 * N integers in a row, M queries.
 * Query i : S E (1 <= S <= E <= N) s.t. str(I_S, I_S+1, ..., I_E) is palindrome?
 * Sol)
 * Find longest palindrome for the muted string II where string I = concat(I1, ..., IN) s.t.
 * II = '|'.join(i for i in I) for each position.
 * For each index i in II, save start/end position into II_longest_palindrome
 * For the query S E, we can record the start/end position of this substring.
 * Convert the index to the II's index; sum & divide by 2; find that divided integer from the II_longest_palindrome and compare the start/end position with the saved start/end position. If saved_start <= start < end <= saved_end, mark as 1. O.W., mark as 0.
 */
using namespace std;
char text[100]; 
int min(int a, int b) 
{ 
    int res = a; 
    if(b < a) 
        res = b; 
    return res; 
} 
  
void findLongestPalindromicString() 
{ 
    int N = strlen(text); 
    if(N == 0) 
        return; 
    N = 2*N + 1; //Position count 
    int L[N]; //LPS Length Array. L[i] means the longest palindrome which has a center as (i-1)/2 index, so if we succeed to calculate the start and and position, we can automatically extract all palindromes by incrementing start and decrementing end until they crosses.
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
        printf("LPS of string centered at position %d/2 of %s is :", i-1, text);
        int j;
        for(j=start; j<=end; j++)
          printf("%c", text[j]);
        printf("\n");
      }
    }
    start = (maxLPSCenterPosition - maxLPSLength)/2; 
    end = start + maxLPSLength - 1; 
    printf("LPS of string is %s : ", text); 
    for(i=start; i<=end; i++) 
        printf("%c", text[i]); 
    printf("\n"); 
} 
  
int main(int argc, char *argv[]) 
{ 
    int N;
    string s;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
      // scanf("%[^\n]s", text);
      getline(cin, s);
      strcpy(text, s.c_str());
      findLongestPalindromicString();
    }
    /*
    strcpy(text, "babcbabcbaccba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abaaba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abababa"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abcbabcbabcba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "forgeeksskeegfor"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "caba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abacdfgdcaba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abacdfgdcabba"); 
    findLongestPalindromicString(); 
  
    strcpy(text, "abacdedcaba"); 
    findLongestPalindromicString(); 
    */
    return 0; 
} 
