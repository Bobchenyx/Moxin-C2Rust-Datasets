public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        while (n != 1) {
            n = toSumOfSquares(n);
            if (set.contains(n)) {
                return false;
            } else {
                set.add(n);
            }
        }
        return true;
    }

    private int toSumOfSquares(int n) {
        int sum = 0;
        do {
            int num = n % 10;
            sum += num * num;
            n = n / 10;
        } while (n > 0);

        return sum;
    }