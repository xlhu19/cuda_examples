

int str2Int(char* str) {
	int value = 0;
	int sign = 1;
	if (*str == '-') {
		sign = -1;
		str++;
	}

	while (*str) {
		value = value * 10 + *str - '0';
		str++;
	}

	return sign*value;
}

