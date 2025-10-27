string convert(string s, int numRows) {
    if (s.size() <= numRows || numRows <= 1) {
        return s;
    }

    // V字结构可容纳的最大字符数
    size_t maxCntV = 2 * numRows - 2;
    // 存在的V字结构的数量
    size_t maxV = (size_t)ceil((double)s.size() / maxCntV);

    stringstream ss;
    for (size_t posRow = 0; posRow < numRows; ++posRow) {
        for (size_t posV = 0; posV < maxV; ++posV) {
            size_t idx = maxCntV * posV + posRow;
            if (idx < s.size()) {
                ss << s[idx];
            }

            // 每个V字结构，只有首行和尾行一个字符
            if (posRow != 0 && posRow + 1 != numRows) {
                idx = maxCntV * (posV + 1) - posRow;
                if (idx < s.size()) {
                    ss << s[idx];
                }
            }
        }
    }
    
    return ss.str();
}