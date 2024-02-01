class Solution {
public:
  int confusingNumberII(int n) {
    /* Sol) For 5^k digit strings, compute number of non palindromic confusing
     * numbers. */
    /* For each pair of endpoints, there will be non-confusing pairs: (0, 0),
    (1, 1), (8, 8), (6, 9), (9, 6) (heading three are valid when inside, tailing
    two are valid when not in center) len 1 invalid confusion numbers: 3 (0, 1,
    8). len 2 invalid confusion numbers: 4 (11, 88, 69, 96). len 3 invalid
    confusion numbers: 4 * 3. len 4 invalid confusion numbers: 4 * 5., ... inner
    len 1 invalid confusion numbers: 3, inner len 2 invalid confusion
    numbers: 5. inner len 3 invalind confusion numbers: 5 * 3. inner len 4
    invalid confusion numbers: 5 * 5, ... len x invalid confusion numbers: len
    x-2 inner invalid confusion numbers * 4
    */
    // 1-digit exceptions
    if (n < 6)
      return 0;
    if (n < 9)
      return 1;
    if (n == 9)
      return 2;
    // General
    set<int> confusing_digit{0, 1, 6, 8, 9};
    map<int, int> confusing_pair;
    confusing_pair[0] = 0;
    confusing_pair[1] = 1;
    confusing_pair[6] = 9;
    confusing_pair[8] = 8;
    confusing_pair[9] = 6;
    vector<int> count_invalid_numbers(9, 0);
    vector<int> count_invalid_numbers_inner(9, 0);
    vector<int> count_confusing_numbers(9, 0);
    count_confusing_numbers[0] = 5;
    count_confusing_numbers[1] = 20;
    vector<int> count_full_confusion_numbers(9, 0);
    count_full_confusion_numbers[0] = 5;
    count_full_confusion_numbers[1] = 25;
    count_invalid_numbers[0] = count_invalid_numbers_inner[0] = 3;
    count_invalid_numbers[1] = 4;
    count_invalid_numbers_inner[1] = 5;
    for (int i = 2; i < 9; i++) {
      count_invalid_numbers[i] = count_invalid_numbers_inner[i - 2] * 4;
      count_invalid_numbers_inner[i] = count_invalid_numbers_inner[i - 2] * 5;
      count_confusing_numbers[i] = count_confusing_numbers[i - 1] * 5;
      count_full_confusion_numbers[i] = 5 * count_full_confusion_numbers[i - 1];
    }
    vector<int> n_digits;
    int ten_base = 1;
    vector<int> ten_bases;
    int num_digits = 0;
    int k = n;
    while (k > 0) {
      n_digits.push_back(k % 10);
      ten_bases.push_back(ten_base);
      if (num_digits <= 8)
        ten_base *= 10;
      k /= 10;
      num_digits += 1;
    }
    reverse(ten_bases.begin(), ten_bases.end());
    reverse(n_digits.begin(), n_digits.end());
    // Log invalidity whe the first k digits are fixed.
    vector<bool> confusing_until(num_digits, true);
    bool indicator = true;
    for (int i = 0; i < num_digits; i++) {
      if (confusing_digit.find(n_digits[i]) == confusing_digit.end()) {
        indicator = false;
      }
      confusing_until[i] = indicator;
    }
    int valid_confusion_numbers = 0;
    int curr_seen_nums = 0;
    for (int i = 0; i < num_digits; i++) {
      if (i > 0 && !confusing_until[i - 1])
        break;
      for (int j = 0; j < n_digits[i]; j++) {
        if (i == 0 && j == 0) {
          for (int i = 0; i <= num_digits - 2; i++) {
            cout << count_confusing_numbers[i] << " "
                 << count_invalid_numbers[i] << endl;
            valid_confusion_numbers +=
                (count_confusing_numbers[i] - count_invalid_numbers[i]);
          }
        } else if (confusing_digit.find(j) != confusing_digit.end()) {
          // Fix ith highest digit as j, Fix 0-i-1th highest digit as
          // n_digits[k]. Now Fill their corresponding confusing digits from the
          // back. In this condition, compute the number of invalid confusing
          // numbers/
          int num_confusing_numbers =
              (i == num_digits - 1
                   ? 1
                   : count_full_confusion_numbers[num_digits - 2 - i]);
          vector<int> fixed_digits(num_digits, 0);
          int found_invalid_confusion_numbers = 0;
          bool fixed_invalid_confusion_number = true;
          for (int k = 0; k < i; k++) {
            fixed_digits[k] = n_digits[k];
          }
          fixed_digits[i] = j;
          for (int k = 0; k < i; k++) {
            // Find the crossing point.
            if (k >= num_digits - 1 - k) {
              if (fixed_digits[num_digits - 1 - k] !=
                  confusing_pair[n_digits[k]]) {
                fixed_invalid_confusion_number = false;
                break;
              }
            }
          }
          if (i >= num_digits - 1 - i) {
            if (i == num_digits - 1 - i) {
              if (j != confusing_pair[j])
                fixed_invalid_confusion_number = false;
            } else if (fixed_digits[num_digits - 1 - i] != confusing_pair[j]) {
              fixed_invalid_confusion_number = false;
            }
          }
          if (fixed_invalid_confusion_number) {
            if (2 * (i + 1) >= num_digits)
              found_invalid_confusion_numbers = 1;
            else
              found_invalid_confusion_numbers =
                  count_invalid_numbers_inner[num_digits - 2 * (i + 1) - 1];
          }
          num_confusing_numbers -= found_invalid_confusion_numbers;
          cout << found_invalid_confusion_numbers << endl;
          cout << i << " " << j << " " << num_confusing_numbers << endl;
          valid_confusion_numbers += num_confusing_numbers;
        }
      }
      curr_seen_nums += n_digits[i] * ten_bases[i];
    }
    // Finally, check n is valid confusing number or not.
    int last_number_confusing = 1;
    if (!confusing_until[num_digits - 1])
      last_number_confusing = 0;
    else {
      bool invalid_confusing = true;
      for (int i = 0; i < num_digits; i++) {
        if (n_digits[num_digits - 1 - i] != confusing_pair[n_digits[i]]) {
          invalid_confusing = false;
          break;
        }
      }
      if (invalid_confusing)
        last_number_confusing = 0;
    }
    valid_confusion_numbers += last_number_confusing;
    return valid_confusion_numbers;
  }
};
