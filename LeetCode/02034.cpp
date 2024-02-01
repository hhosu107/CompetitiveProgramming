class StockPrice {
public:
  unordered_map<int, int> time_price;
  map<int, int> price_occurrence;
  int latest_timestamp;
  StockPrice() {
    time_price = unordered_map<int, int>();
    price_occurrence = map<int, int>();
    latest_timestamp = 0;
  }

  void update(int timestamp, int price) {
    price_occurrence[price] += 1;
    if (time_price.find(timestamp) != time_price.end()) {
      price_occurrence[time_price[timestamp]] -= 1;
      if (price_occurrence[time_price[timestamp]] == 0) {
        price_occurrence.erase(time_price[timestamp]);
      }
    }
    time_price[timestamp] = price;
    latest_timestamp = max(latest_timestamp, timestamp);
  }

  int current() { return time_price[latest_timestamp]; }

  int maximum() {
    auto it = price_occurrence.end();
    --it;
    return it->first;
  }

  int minimum() {
    auto it = price_occurrence.begin();
    return it->first;
  }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
