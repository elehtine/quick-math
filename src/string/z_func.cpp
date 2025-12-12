std::vector<int> zFunction(std::string_view string) {
  int n = string.size();
  std::vector<int> z(n);
  int left = 0;
  int right = 0;
  for (int index = 1; index < n; ++index) {
    if (index <= right) {
      z[index] = std::min(right - index + 1, z[index - left]);
    }
    while (index + z[index] < n && string[z[index]] == string[index + z[index]]) {
      z[index]++;
    }
    if (index + z[index] > right) {
      left = index, right = index + z[index] - 1;
    }
  }
  return z;
}
