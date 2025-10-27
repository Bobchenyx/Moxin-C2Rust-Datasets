/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize = num_people;
	if (1 == num_people)
		return &candies;
    int *res = (int*)calloc(num_people, sizeof(int)), t = 1;
	while (candies){
		for (int i = 0; i < num_people; i++){
            if (!candies)
				break;
			if (t < candies){
				res[i] += t;
				candies -= t++;
			}
			else{
				res[i] += candies;
				candies = 0;
			}			
		}
	}
	return res;
}