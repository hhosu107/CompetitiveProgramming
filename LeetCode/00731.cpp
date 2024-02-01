using pii = pair<int, int>;
class MyCalendarTwo {
public:
  map<int, int> books; // key: time. +1 when start, -1 when end. When iterate,
                       // it iterates from the smallest key to the largest key.
  // Originally, this idea should be applied to partial sum on segment, but
  // since min/max for segment is too large, we just control endpoints with
  // hashmap.
  MyCalendarTwo() { books = map<int, int>(); }

  bool book(int start, int end) {
    books[start] += 1;
    books[end] -= 1;
    int booked = 0;
    for (auto it = books.begin(); it != books.end(); it++) {
      booked += it->second;
      if (booked == 3) {
        books[start] -= 1;
        books[end] += 1;
        return false;
      }
    }
    return true;
  }
};
