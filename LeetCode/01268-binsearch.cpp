static_assert(sizeof(int) == 4);

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& vp, string w) {
    vector<vector<string>> va;
    sort(vp.begin(), vp.end());
    string buf = "";
    vector<string>::iterator it_start = vp.begin();
    vector<string>::iterator it_end = vp.end();
    for (const auto ch : w) {
      buf += ch;
      it_start = lower_bound(it_start, it_end, buf);
      it_end = lower_bound(it_start, it_end, buf + '{');
      // Hacking: buf + '{' is larger than any other string starting from buf
      // only with lowercase characters.
      // Thus, lower_bound(sorted_list.cbegin(), sorted_list.cend(), buf)
      // returns the first word in sorted_list starting with buf,
      // lower_bound(sorted_list.cbegin(), sorted_list.cend(), buf + '{')
      // returns the next element of the last word in sorted_list starting with
      // buf.
      // To optimize this once more, save cit1(it_start) and cit2(it_end) for each iteration and
      // reuse to find lower_bound between them.
      // // 결론: prefix search system이 들어왔을 때, word를 특정 검색빈도
      // 순서가 아닌 단순한 lexicographical order로 반환하는 거라면, trie보다도
      // 아예 whole sort 이후 binary search로 prefix로 시작하는 단어의 시작과
      // prefix로 시작하지 않는 첫 단어의 시작점을 return해버려서 그것들을 써라.
      va.emplace_back(it_start, it_start + min<int>(3, it_end - it_start));
      // 참고: it_end - it_start는 int 타입이 "아니다". 그러나 min<int> 형태로,
      // template으로 불러버림으로서 저것들을 강제로 int로 type casting
      // 가능하다.
      // 다만 static_assert(sizeof(int) == 4)를 해서 주소값(iterator)이 4바이트인 것을 확실하게 해야 함.
      // emplace_back이 push_back보다 성능 상 더 유리하다. emplace_back은 삽입할
      // 객체의 생성자를 위한 인자들을 받아 vector<> 내에서 직접 객체를 생성하여
      // 삽입한다. 위의 경우 vector<string>을 생성할 수 있는 인자만 받으면
      // 되는데, vector<>를 생성할 때 특정 container의 begin, end const
      // iterator를 받으면 바로 되기 때문에 저건 valid한 코드이다.
      // push_back은 삽입할 객체를 직접 만들어서 넣어야 하므로 성능상 불리하다.
      // ex) 만약 vector<int>에 emplace_back하는 거라면 push_back과 완전히 같을
      // 것.
    }

    return va;
  }
};
