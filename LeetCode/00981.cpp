class TimeMap {
public:
  map<string, map<int, string>> time_kv;
  TimeMap() { time_kv = map<string, map<int, string>>(); }

  void set(string key, string value, int timestamp) {
    if (time_kv.find(key) == time_kv.end()) {
      time_kv[key] = map<int, string>();
    }
    time_kv[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    if (time_kv.find(key) == time_kv.end()) {
      return "";
    }
    auto it = time_kv[key].upper_bound(timestamp);
    if (it == time_kv[key].begin())
      return "";
    it--;
    return it->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
