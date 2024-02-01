class Solution {
  // function to Compare the Words, and
  // maintain the counter of occurance of matches
private:
  int checkString(string &word1, string &word2) {
    int counter = 0;

    for (int i = 0; i < 6; i++) {
      if (word1[i] == word2[i]) {
        counter++;
      }
    }
    return counter;
  }

public:
  void findSecretWord(vector<string> &wordlist, Master &master) {
    for (int i = 0; i < 10; i++) {
      string &guessWord = wordlist[rand() % wordlist.size()];
      int guessMatch = master.guess(guessWord);
      vector<string> newList;

      for (string &word : wordlist) {
        if (guessMatch == checkString(word, guessWord)) {
          newList.push_back(word);
        }
      }
      wordlist = newList;
    }
  }
};
