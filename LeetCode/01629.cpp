class Solution {
public:
  char slowestKey(vector<int> &releaseTimes, string keysPressed) {
    int prev_release = 0;
    int longest_duration = 0;
    char longest_char = keysPressed[0];
    for (int i = 0; i < keysPressed.length(); i++) {
      if (releaseTimes[i] - prev_release > longest_duration ||
          (releaseTimes[i] - prev_release == longest_duration &&
           keysPressed[i] > longest_char)) {
        longest_duration = releaseTimes[i] - prev_release;
        longest_char = keysPressed[i];
      }
      prev_release = releaseTimes[i];
    }
    return longest_char;
  }
};
