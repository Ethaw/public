#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#define TEST(...) do { \
	printf("ft:   "); fflush(stdout); \
	int a = ft_printf(__VA_ARGS__); \
	printf("real: "); \
	int b = printf(__VA_ARGS__); \
	fflush(stdout); \
	printf("ret: ft=%d real=%d %s\n\n", a, b, a == b ? "OK" : "FAIL"); \
} while (0)

int	main(void)
{
	char	*null_str = NULL;
	void	*null_ptr = NULL;
	int		x = 42;

	TEST("%c|%c|%c\n", 'a', '0', 'Z');
	TEST("%s|%s|%s\n", "hello", "", null_str);
	TEST("%p|%p\n", &x, null_ptr);
	TEST("%d|%i|%d|%d\n", 0, -1, INT_MAX, INT_MIN);
	TEST("%u|%u|%u\n", 0, UINT_MAX, -1);
	TEST("%x|%X|%x|%X\n", 0, 255, UINT_MAX, 0xabcdef);
	TEST("100%% sure %%%%\n");
	TEST("no conversion\n");
	TEST("%s %d %c %x %p\n", "mix", -7, 'z', 3054, &x);
	return (0);
}
