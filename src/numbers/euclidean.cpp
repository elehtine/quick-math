Pair euclidean(int a, int b) {
  if (b == 0) return { 1, 0 };
  int k = a / b;
  auto [x, y] = euclidean(b, a - (k*b));
  return { y, x - y*k };
}
