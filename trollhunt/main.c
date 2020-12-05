#include <stdio.h>

int main(int argc, char* argv[])
{
	int b, k, g;
	scanf("%d", &b);
	scanf("%d", &k);
	scanf("%d", &g);

	if (b<2 || b>1000 || k<1 || k>100 || g<1 || g>k)
	{
		printf("Invalid data %d %d %d\n", b, k, g);
		return 1;
	}	

	int groups = k/g;
	int result;
	b--;
	if(b % groups == 0)
	{
		result = b/groups;
	}
	else
	{
		result = b/groups +1;
	}
	printf("%d\n", result);
	return 0;
}