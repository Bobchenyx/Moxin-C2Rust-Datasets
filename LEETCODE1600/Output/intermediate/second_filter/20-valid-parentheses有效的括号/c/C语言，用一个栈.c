bool isPair(char a, char b) {
    if ((a == '(' && b == ')') || (a=='{' && b == '}') || (a == '[' && b == ']')) {
        return true;
    }else {
        return false;
    }
}

bool isValid(char * s){
	int length = strlen(s);
	char *stack = (char *)malloc(sizeof(char) * length);
	int top = 0;

	int k = 0;
	while (s[k] != '\0') {
		if (s[k] == ' ') {
			return false;
		}
		if (top == 0) {
			if (s[k] == '}' || s[k] == ')' || s[k] == ']') {
				return false;
			}
			stack[top++] = s[k++];
		} else if (s[k] == '(' || s[k] == '{' || s[k] == '[') {
			stack[top++] = s[k++];
		} else {
			if (isPair(stack[top - 1], s[k])) {
				k++;
				top--;
				continue;
			} else {
				return false;
			}
		}

	}

	if (top != 0) {
		return false;
	}
	return true;
}