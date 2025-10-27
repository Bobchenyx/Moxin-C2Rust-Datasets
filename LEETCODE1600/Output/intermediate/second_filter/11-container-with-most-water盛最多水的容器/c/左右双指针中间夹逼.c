int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int min(int a, int b) {
  if (a > b) {
    return b;
  }
  return a;
}

int maxArea(int *height, int heightSize) {
  int ans = 0;
  int l = 0;              //左边界
  int r = heightSize - 1; //右边界
  while (l < r) {
    ans = max(ans, (r - l) * min(height[l], height[r]));
    height[l] < height[r] ? l++ : r--;
  }
  return ans;
}