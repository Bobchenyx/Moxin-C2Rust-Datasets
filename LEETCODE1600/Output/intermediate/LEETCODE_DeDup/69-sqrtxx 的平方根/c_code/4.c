int mySqrt(int x){
    if(x == 0)
    {
        return 0;
    }


    int left_num = 0, right_num = 0;
	int size_two = 0;
	int i = 0;
	int results = 0;
	uint64_t tmp = x;

	while (tmp > 1)
	{
		size_two++;
		tmp = tmp >> 1;
	}

	size_two /= 2;

	left_num = 1 << size_two;
	right_num = 1 << (size_two + 1);

	for (i = left_num; i < right_num; i++)
	{
		tmp = (uint64_t)(i + 1) * (i + 1);

		if (((i * i) <= x) && (tmp > (uint64_t)x))
		{
			return i;
		}
	}

	return i;
}