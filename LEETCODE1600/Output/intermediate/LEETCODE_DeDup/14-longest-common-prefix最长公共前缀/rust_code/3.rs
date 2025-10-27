func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 { return "" }
	str, char, ptr := &strings.Builder{}, byte(0), 0
	for {
		for i := range strs {
			if ptr > len(strs[i]) - 1 {
				return str.String()
			} else if i == 0 {
				char = strs[i][ptr]
			} else if strs[i][ptr] != char {
				return str.String()
			}
		}
		str.WriteByte(strs[0][ptr])
		ptr += 1
	}
}