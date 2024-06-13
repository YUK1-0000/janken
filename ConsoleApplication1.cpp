#include <stdio.h>
#include <random>


bool search_num(int *num_array, int num)
{
	bool result = false;

	for (int i = 0; i < (sizeof(*num_array) / sizeof(int)) + 1; i++)
	{
		if (num == num_array[i])
		{
			result = true;
			break;
		}
	}

	return result;
}


int janken(void)
{
	int allowed_nums[] = { 1, 2, 3 };
	const char* hands[] = { "ぐー", "ちょき", "ぱー" };
	int cpu_ind, player_ind;

	do
	{
		printf("\n1:ぐー, 2:ちょき, 3:ぱー\n");
		scanf_s("%d", &player_ind);
	}
	while (!search_num(allowed_nums, player_ind));

	player_ind -= 1;
	cpu_ind = rand() % 3;

	printf("\n自分: %s, 乱数: %s\n", hands[player_ind], hands[cpu_ind]);

	if (player_ind == cpu_ind)
	{
		printf("引き分け");
	}
	else if (player_ind + 1 % 3 == cpu_ind)
	{
		printf("勝ち");
	}
	else
	{
		printf("負け");
	}
	printf("\n\n");

	return 0;
}


int main(void)
{
	int allowed_nums[] = { 1, 2 };
	int num;

	do
	{
		janken();

		do
		{
			printf("1:続ける, 2:やめる\n");
			scanf_s("%d", &num);
		}
		while (!search_num(allowed_nums, num));

		if (num == 2)
		{
			break;
		}
	}
	while (num != 2);

	return 0;
}

