#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <boolean.h>

typedef struct	s_flag
{
	char	*fmt;
	va_list	ap;
	int		ret;
	bool	positive;
	bool	negative;
	bool	space;
	int		minField;
	bool	dot;
	int		vaDigit;
	char	conversion;
}				t_flag

#endif

