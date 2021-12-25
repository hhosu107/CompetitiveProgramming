      vector<int> maxright = vector<int>(n - idx);
      if (maxright.size() > 1) {
        int size = n - idx;
        int maxlen = 0;
        for(int i=0; i<size; i++){
          maxright[i] = values[n-1-i];
          auto pos = upper_bound(maxright.begin(), maxright.begin() + maxlen, maxright[i]);
          *pos = maxright[i];
          if (pos == maxright.begin() + maxlen)
            maxlen++;
        }
        cout << maxlen - 1 << '\n';
      }

