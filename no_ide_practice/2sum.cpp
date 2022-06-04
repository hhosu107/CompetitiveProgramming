#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main () {
	int n, target;
	cin >> n >> target;
	vector<int> ints(n);
	unordered_map<int, vector<int>> int_idx;
	for (int i=0; i<n; i++) {
		cin >> ints[i];
		if (int_idx.find(ints[i]) == int_idx.end()) {
			int_idx[ints[i]] = vector<int>(i, 1);
		}
		else {
			int_idx[ints[i]].push_back(i);
		}
	}
	bool find = false;
	for (int i=0; i<n; i++) {
		if (int_idx.find(target - ints[i]) != int_idx.end()) {
			vector<int> indices = int_idx[target - ints[i]];
			for(auto j: indices) {
				if (i != j) {
					find = true;
					break;
				}
			}
		}
		if (find)
			break;
	}
	cout << (find ? "YES" : "NO") << endl;
	return 0;
}

