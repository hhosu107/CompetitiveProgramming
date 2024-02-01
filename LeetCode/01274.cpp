/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

/* Sol)
Basically, we divide a square in the interest into 4 pieces:
topRight to (topRight + bottomLeft) / 2, ...
*/
class Solution {
public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    using pii = vector<int>;
    using ppi = pair<pii, pii>;
    queue<ppi> interested_area;
    int int_areas = 0;
    if (sea.hasShips(topRight, bottomLeft)) {
      interested_area.push({topRight, bottomLeft});
      int_areas += 1;
    }
    int shipCount = 0;
    int maxPossibleAreas = 10;
    while (!interested_area.empty()) {
      ppi curr_area = interested_area.front();
      interested_area.pop();
      int_areas -= 1;
      if (curr_area.first[0] == curr_area.second[0] &&
          curr_area.first[1] == curr_area.second[1]) {
        cout << curr_area.first[0] << " " << curr_area.first[1] << " "
             << curr_area.second[0] << " " << curr_area.second[1] << endl;
        shipCount += 1;
        maxPossibleAreas -= 1;
        continue;
      }
      pii vertices_to_put[4][2];
      bool vertical = (curr_area.first[1] == curr_area.second[1]);
      bool horizontal = (curr_area.first[0] == curr_area.second[0]);
      int cands = 4;
      if (vertical) {
        vertices_to_put[0][1] = curr_area.second;
        vertices_to_put[0][0] =
            vector<int>{(curr_area.first[0] + curr_area.second[0]) / 2,
                        (curr_area.first[1] + curr_area.second[1]) / 2};
        vertices_to_put[1][1] =
            vector<int>{vertices_to_put[0][0][0] + 1, curr_area.second[1]};
        vertices_to_put[1][0] = curr_area.first;
        cands = 2;
      } else if (horizontal) {
        vertices_to_put[0][1] = curr_area.second;
        vertices_to_put[0][0] =
            vector<int>{(curr_area.first[0] + curr_area.second[0]) / 2,
                        (curr_area.first[1] + curr_area.second[1]) / 2};
        vertices_to_put[1][1] =
            vector<int>{curr_area.second[0], (vertices_to_put[0][0][1] + 1)};
        vertices_to_put[1][0] = curr_area.first;
        cands = 2;
      } else {
        vertices_to_put[0][1] = curr_area.second;
        vertices_to_put[0][0] =
            vector<int>{(curr_area.first[0] + curr_area.second[0]) / 2,
                        (curr_area.first[1] + curr_area.second[1]) / 2};
        vertices_to_put[1][1] =
            vector<int>{curr_area.second[0], (vertices_to_put[0][0][1] + 1)};
        vertices_to_put[1][0] =
            vector<int>{vertices_to_put[0][0][0], curr_area.first[1]};
        vertices_to_put[2][1] =
            vector<int>{vertices_to_put[0][0][0] + 1, curr_area.second[1]};
        vertices_to_put[2][0] =
            vector<int>{curr_area.first[0], vertices_to_put[0][0][1]};
        vertices_to_put[3][1] = vector<int>{vertices_to_put[0][0][0] + 1,
                                            vertices_to_put[0][0][1] + 1};
        vertices_to_put[3][0] = curr_area.first;
      }
      for (int i = 0; i < cands; i++) {
        if (sea.hasShips(vertices_to_put[i][0], vertices_to_put[i][1])) {
          interested_area.push({vertices_to_put[i][0], vertices_to_put[i][1]});
          int_areas += 1;
          if (int_areas >= maxPossibleAreas) {
            break;
          }
        }
      }
    }
    return shipCount;
  }
};
