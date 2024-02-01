struct FlowerEvent {
  int time;
  bool type;
};

struct FlowerSegment {
  int st;
  int num;
};

class Solution {
public:
  vector<FlowerSegment> segments(vector<vector<int>> &flowers) {
    vector<FlowerEvent> events;
    for (auto t : flowers) {
      events.push_back({t[0], true});
      events.push_back({t[1] + 1, false});
    }
    auto comp = [](const FlowerEvent &a, FlowerEvent &b) {
      if (a.time != b.time)
        return a.time < b.time;
      return (!a.type && b.type);
    };
    sort(events.begin(), events.end(), comp);
    int prev_event;
    int prev_flowers;
    prev_event = 0;
    prev_flowers = 0;
    vector<FlowerSegment> ret;
    for (int i = 0; i < events.size(); i++) {
      int cur_event = events[i].time;
      if (prev_event != cur_event) {
        ret.push_back({prev_event, prev_flowers});
      }
      prev_event = cur_event;
      if (events[i].type)
        prev_flowers += 1;
      else
        prev_flowers -= 1;
    }
    ret.push_back({prev_event, 0});
    return ret;
  }
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                               vector<int> &persons) {
    vector<FlowerSegment> ret = segments(flowers);
    vector<int> event_times(ret.size());
    vector<int> flower(ret.size());
    for (int i = 0; i < ret.size(); i++) {
      event_times[i] = ret[i].st;
      flower[i] = ret[i].num;
    }
    vector<int> num_flowers(persons.size());
    for (int i = 0; i < persons.size(); i++) {
      auto up = upper_bound(event_times.begin(), event_times.end(), persons[i]);
      if (up == event_times.end() || up == event_times.begin()) {
        num_flowers[i] = 0;
        continue;
      }
      up--;
      num_flowers[i] = flower[up - event_times.begin()];
    }
    return num_flowers;
  }
};
