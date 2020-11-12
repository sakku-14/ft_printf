#include <stdio.h>
#include <stdarg.h>

void printnums(int num, ...)
{
	va_list args;
	va_start(args, num);
	for(int i = 0; i < num; ++i)
	{
		printf("%d\n", va_arg(args, int));
	}
	va_end(args);
}

void sum(int num, ...)
{
	va_list args;
	int sum = 0;
	va_start(args, num);
	while (num-- > 0)
	{
		sum += va_arg(args, int);
	}
	printf("%d\n", sum);
	va_end(args);
}

void printchars(int num, ...)
{
	va_list args;
	va_start(args, num);
	while (num-- > 0)
	{
		printf("%s\n", va_arg(args, char*));
	}
	va_end(args);
}

void printbyfmt(char *fmt, ...)
{
	va_list ap;
	int d = 0;
	char *str, c;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == 's')
		{
			str = va_arg(ap, char *);
			printf("%s\n", str);
		}
		else if (*fmt == 'd')
		{
			d = va_arg(ap, int);
			printf("%d\n", d);
		}
		else if (*fmt == 'c')
		{
			c = va_arg(ap, int);
			printf("%c\n", c);
		}
		fmt++;
	}
	va_end(ap);
}

int main()
{
	printnums(5, 1, 2, 3, 4, 5);
	sum(6, 33, 44, 33, 22, 11, 3);
	printchars(2, "hello", "world");
	printbyfmt("sdc", "hello", 14, 'c');
}
