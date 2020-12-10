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
	const char	*fmt;
	va_list	ap;
	int		ret;
	bool	negative;
	bool	zero;
	ssize_t		minField;
	ssize_t		vaDigit;
	char	conversion;
	bool	zero_signal;
}				t_flag;

int pf_check_digit(int num);
int pf_check_usdigit(unsigned int num);
int pf_check_xdigit(unsigned int num);
int pf_check_adddigit(uintptr_t address);
int ft_error_free_flag(t_flag **flag);
void ft_last_free_flag(t_flag **flag);
int pf_pack_minf(t_flag **flag);
int pf_pack_vad_sub(t_flag **flag, ssize_t *tmp);
int pf_pack_vad(t_flag **flag);
void pf_pack_asta_va(t_flag **flag);
int pf_pack_asta_min(t_flag **flag);
int pf_pack_asta(t_flag **flag);
void pf_print_add(t_flag **flag, int digit, uintptr_t address);
void pf_print_address(t_flag **flag);
void pf_print_onechar(t_flag **flag, int c);
void pf_print_char(t_flag **flag);
void pf_print_lxnum_sub(t_flag **flag, int digit, unsigned int num);
void pf_print_lxnum(t_flag **flag);
void pf_print_num_pos(t_flag **flag, int digit, int num);
void pf_print_num_neg(t_flag **flag, int digit, int num);
void pf_print_num(t_flag **flag);
void pf_print_percent(t_flag **flag);
void pf_print_zero(t_flag **flag, int digit);
void pf_print_space(t_flag **flag);
void pf_print_str_sub(t_flag **flag, char *str);
void pf_print_str(t_flag **flag);
void pf_print_usnum_pos(t_flag **flag, int digit, unsigned int num);
void pf_print_usnum(t_flag **flag);
void pf_print_xnum_sub(t_flag **flag, int digit, unsigned int num);
void pf_print_xnum(t_flag **flag);
int pf_switch(t_flag **flag);
void pf_initflag(t_flag **flag);
int pf_check_conversion(t_flag **flag);
int pf_pack_after_dot(t_flag **flag);
int pf_pack_conversion(t_flag **flag);
int pf_pack_flag(t_flag **flag);
int ft_printf(const char *fmt, ...);
void	ft_bzero(void *s, size_t n);
void	ft_putchar(char c, t_flag **flag);
void	ft_putnbr(int n, t_flag **flag);
void	ft_putusnbr(unsigned int nbr, t_flag **flag);
void	ft_putxnbr(unsigned int nbr, t_flag **flag);
void	ft_putlxnbr(unsigned int nbr, t_flag **flag);
void	ft_putadnbr(uintptr_t nbr, t_flag **flag);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
