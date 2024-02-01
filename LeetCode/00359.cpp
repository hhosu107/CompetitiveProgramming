class Logger {
public:
  map<string, int> uniq;
  Logger() { uniq = map<string, int>(); }

  bool shouldPrintMessage(int timestamp, string message) {
    if (uniq.find(message) == uniq.end() || uniq[message] + 10 <= timestamp) {
      uniq[message] = timestamp;
      return true;
    } else {
      return false;
    }
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
