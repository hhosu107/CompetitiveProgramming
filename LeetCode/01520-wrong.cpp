iclass Solution {
public:
  struct CharFirstLast {
    int left;
    int right;
    char c;
    CharFirstLast() : left(-1), right(-1), c('-') {}
    CharFirstLast(int l, int r, char cc) : left(l), right(r), c(cc) {}
    bool operator<(const CharFirstLast &o) {
      return left < o.left || (left == o.left && right < o.right);
    }
    bool operator==(const CharFirstLast &o) {
      return left == o.left && right == o.right && c == o.c;
    }
  };
  /*
  struct SetCharFirstLast {
      set<CharFirstLast> chunks;
      int maxLeft;
      int maxRight;
      int minLeft;
      int minRight;
      SetCharFirstLast() {
          maxLeft = 1000000;
          maxRight = -1000000;
          minLeft = -1000000;
          minRight = 1000000;
          chunks = set<CharFirstLast>();
      }
      SetCharFirstLast(CharFirstLast chunk) {
          chunks = set<CharFirstLast>();
          chunks.insert(chunk);
          maxLeft = chunk.left;
          maxRight = chunk.right;
          minLeft = chunk.left;
          minRight = chunk.right;
      }
      void insertNewChunk(CharFirstLast newChunk) {
          chunks.insert(newChunk);
          maxLeft = min(maxLeft, newChunk.left);
          maxRight = max(maxRight, newChunk.right);
          minLeft = max(minLeft, newChunk.left);
          minRight = min(minRight, newChunk.right);
      }
  };
  */
  struct charOccurrenceEvent {
    char c;
    int timestamp;
    bool first_occur_last_occur; // true: first_occur, false: last_occur.
    bool operator<(const charOccurrenceEvent &o) {
      return timestamp < o.timestamp ||
             (timestamp == o.timestamp && first_occur_last_occur == false &&
              o.first_occur_last_occur == true);
    }
  };
  struct charChunk {
    int x;
    int y;
    charChunk() : x(-1), y(-1) {}
    charChunk(int x, int y) : x(x), y(y) {}
    bool included(const charChunk &o) { return x > o.x && y < o.y; }
  };
  vector<string> maxNumOfSubstrings(string s) {
    // Sol) Perform the union find on the segment. One exception: if one
    // includes the other one, remove that encapsules one instead of merging.
    // event base. map<set<char>, int> contains the first occurrent of that set.
    // Compute first/last occurrence of each char. If
    map<char, CharFirstLast> segments;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (segments.count(s[i]) == 0) {
        segments[s[i]] = CharFirstLast(i, i, s[i]);
      }
      segments[s[i]].right = i;
    }
    vector<charOccurrenceEvent> events;
    for (const auto &[k, v] : segments) {
      events.push_back({k, v.left, true});
      events.push_back({k, v.right + 1, false});
    }
    sort(events.begin(), events.end());
    map<set<char>, pair<int, int>>
        char_chunk_timestamp; // pair's first: first occurrence of the set;
                              // pair's last: last occurrence of the set.
    /*
    vector<CharFirstLast> segments_list;
    for(const auto& [k, v] : segments) {
        segments_list.push_back(v);
    }
    sort(segments_list.begin(), segments_list.end());
    */
    set<char> curr_chars;
    vector<charChunk> final_chunks;
    char_chunk_timestamp.insert({curr_chars, make_pair(-1, -1)});
    for (charOccurrenceEvent e : events) {
      if (e.first_occur_last_occur) {
        char_chunk_timestamp[curr_chars].second = e.timestamp - 1;
        curr_chars.insert(e.c);
        char_chunk_timestamp.insert(
            {curr_chars, make_pair(e.timestamp, e.timestamp)});
      } else {
        set<char> prev_chars = curr_chars;
        curr_chars.erase(e.c);
        if (char_chunk_timestamp.find(curr_chars) ==
            char_chunk_timestamp.end()) {
          char_chunk_timestamp.insert(
              {curr_chars, make_pair(e.timestamp, e.timestamp)});
        } else {
          int prev_chunk_timestamp = char_chunk_timestamp[curr_chars].second;
          char_chunk_timestamp[curr_chars].second = e.timestamp - 1;
          charChunk curr_chunk{prev_chunk_timestamp + 1, e.timestamp};
          bool including_other_chunk = false;
          for (charChunk other : final_chunks) {
            if (other.included(curr_chunk)) {
              including_other_chunk = true;
              break;
            }
          }
          if (!including_other_chunk) {
            final_chunks.push_back(curr_chunk);
          }
        }
      }
    }
    vector<string> substrings;
    for (charChunk chunk : final_chunks) {
      string x = s.substr(chunk.x, chunk.y - chunk.x);
      substrings.push_back(x);
    }
    return substrings;
  }
};
