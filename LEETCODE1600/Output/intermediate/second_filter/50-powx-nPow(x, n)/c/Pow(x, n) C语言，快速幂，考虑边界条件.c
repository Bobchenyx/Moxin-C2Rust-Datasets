double myPow(double x, int n) {
  // 如果底为 0 则直接返回 0
  if (x == 0)
    return 0.0;

  // 返回值
  double ret = 1;
  // 补偿因子
  double hack = 0;

  if (n == INT_MIN) {
    // 如果 n == INT_MIN，则让 n = INT_MAX，并让 x 作为补偿因子
    hack = x;
    n = INT_MAX;
  } else if (n < 0) {
    // 如果 n < 0，则让 1 作为补偿因子，并且让 n = -n
    hack = 1;
    n = -n;
  }

  // 快速幂
  for (; n != 0; n >>= 1) {
    if (n & 1) {
      ret *= x;
    }
    x *= x;
  }

  // 如果补偿因子不为 0，结果除去补偿因子
  if (hack)
    ret = 1 / ret / hack;

  return ret;
}