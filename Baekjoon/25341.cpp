#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> input_tensor(n);
  vector<int> neuron_input_size(m);
  vector<vector<pair<int, int>>> neuron_input(m);
  vector<int> bias(m);
  vector<int> output_weight(m);
  int output_bias;
  for(int i=0; i<m; i++) {
    cin >> neuron_input_size[i];
    neuron_input[i] = vector<pair<int, int>>(neuron_input_size[i]);
    for(int j=0; j<neuron_input_size[i]; j++) {
      cin >> neuron_input[i][j].first;
      neuron_input[i][j].first--;
    }
    for(int j=0; j<neuron_input_size[i]; j++) {
      cin >> neuron_input[i][j].second;
    }
    cin >> bias[i];
  }
  for(int i=0; i<m; i++) {
    cin >> output_weight[i];
  }
  cin >> output_bias;
  for(int i=0; i<q; i++) {
    int output = 0;
    for(int j=0; j<n; j++) {
      cin >> input_tensor[j];
    }
    vector<int> neurons_output(m);
    for(int j=0; j<m; j++) {
      int sum = 0;
      for(int k=0; k<neuron_input_size[j]; k++) {
        sum += input_tensor[neuron_input[j][k].first] * neuron_input[j][k].second;
      }
      neurons_output[j] = sum + bias[j];
    }
    for(int j=0; j<m; j++) {
      output += neurons_output[j] * output_weight[j];
    }
    output += output_bias;
    cout << output << '\n';
  }
  return 0;
}
