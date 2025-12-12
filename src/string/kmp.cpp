std::vector<int> kmp(std::string_view string) {
  int n = string.size();
  std::vector<int> prefix(n);
  for (int index = 1; index < n; ++index) {
    int p = prefix[index - 1];
    while (p > 0 && string[p] != string[index]) p = prefix[p - 1];
    if (string[p] == string[index]) p++;
    prefix[index] = p;
  }
  return prefix;
}
