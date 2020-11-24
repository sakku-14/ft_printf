#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct	s_flag
{
	char	*fmt;
	va_list	ap;
	int		ret;
	bool	negative;
	bool	zero;
	int		minField;
	bool	dot;
	int		vaDigit;
	char	conversion;
}				t_flag;

void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putusnbr_fd(unsigned int nbr, int fd);
void	ft_putxnbr_fd(unsigned int nbr, int fd);
void	ft_putlxnbr_fd(unsigned int nbr, int fd);
void	ft_putadnbr_fd(int64_t nbr, int fd);
size_t	ft_strlen(const char *s);
void pf_initflag(t_flag **flag);
void pf_pack_flag(t_flag **flag, const char **fmt, va_list *ap);
int pf_switch(const char **fmt, va_list *ap);
int ft_printf(const char *fmt, ...);

#endif

