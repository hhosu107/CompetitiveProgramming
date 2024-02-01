class Solution {
private:
  map<string, int> wordCount;
  int n;
  int wordLength;
  int substringSize;
  int k;

public:
  void slidingWindow(int left, string s, vector<int> &answer) {
    map<string, int> wordsFound; // Contains number of words in the substring
    int wordsUsed = 0;           // Counts number of words in the substring
    bool wordExceeded = false;   // If a word in the substring occurs more than
                                 // expected, turn it as true.

    for (int right = left; right <= n - wordLength; right += wordLength) {
      string sub = s.substr(right, wordLength);
      if (wordCount.find(sub) == wordCount.end()) {
        wordsFound = map<string, int>();
        wordsUsed = 0;
        wordExceeded = false;
        left = right + wordLength;
      } else {
        while (right - left == substringSize || wordExceeded) {
          string leftMostWord = s.substr(left, wordLength);
          left += wordLength;
          wordsFound[leftMostWord] -= 1;
          if (wordsFound[leftMostWord] >=
              wordCount[leftMostWord]) { // Even after decreasing, wordsFound is
                                         // larger than or equal to wordCount.
            wordExceeded = false;
          } else {
            wordsUsed -= 1;
          }
        }
        if (wordsFound.find(sub) == wordsFound.end()) {
          wordsFound[sub] = 1;
        } else {
          wordsFound[sub] += 1;
        }
        if (wordsFound[sub] <= wordCount[sub]) {
          wordsUsed += 1;
        } else {
          wordExceeded = true;
        }
        if (wordsUsed == k && !wordExceeded) {
          answer.push_back(left);
        }
      }
    }
  }

  vector<int> findSubstring(string s, vector<string> &words) {
    n = s.length();
    k = words.size();
    wordLength = words[0].length();
    substringSize = wordLength * k;
    for (string w : words) {
      if (wordCount.find(w) == wordCount.end()) {
        wordCount[w] = 1;
      } else {
        wordCount[w] += 1;
      }
    }
    // With sliding window, we try to catch every substring that starts at
    // wordLength * k + rem. Thus loop on 0<=rem<=wordLeng-1.
    vector<int> answer(0);
    for (int i = 0; i < wordLength; i++) {
      slidingWindow(i, s, answer);
    }
    return answer;
  }
};
