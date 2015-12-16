#include <cstdio>
#include <cstdlib>

int fib[50] = {0,1,1};
int main(int argc, char **argv) {
	for(int i = 3; i < 50; ++i)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}	
	int n;
	scanf(" %d",&n);
	printf("%d\n", fib[n]);
	return 0;
}
