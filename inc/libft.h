/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:28:14 by cajulien          #+#    #+#             */
/*   Updated: 2019/04/08 16:14:11 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "wchar.h"

# define BUFF_SIZE	42

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t	n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** 								ft_printf PROJECT
*/

# define UINT_MAX	4294967296
# define FLAGS		"cCsSpdDioOuUbxX%fFZ"
# define OTHER		".1234567890QqWwEeRrTtYyAaGgHJKkZVvBbNnMm"
# define OTHER2		"QqWwEeRrTtYyAaGgHJKkZVvBbNnMmI"
# define OPTIONS	"#0-+ "
# define B1			0x0000000000FF
# define _X_		"0123456789ABCDEF"
# define _XMIN_		"0123456789abcdef"
# define SIG		0x1
# define EXPONENT	0x7FF
# define FRACTION	0xFFFFFFF
# define CUT		0x0F
# define _ULLMAX_	0xFFFFFFFFFFFFFFFF

typedef	struct		s_flag
{
	char	*parsing;
	char	*to_print;
	char	flag;
	char	*option;
	int		precision;
	int		field;
	char	*modif;
}					t_flag;

typedef struct		s_double
{
	short int			s;
	int					e;
	int					pow;
	unsigned long long	f;
}					t_double;

/*
** ft_printf.c
*/

int					ft_printf(const char *format, ...) __attribute__
					((format(printf,1,2)));
int					pf_manager(const char *format, va_list ap);
int					check_format(const char *str);
int					check_format2(const char *str);
int					ft_strstringlen(const char *str, char *chr);

/*
** pf_str_manager.c
*/

int					pf_str_manager(const char *str, int *pos);

/*
** pf_arg_manager.c
*/

int					ft_parsing(const char *format, int *i, va_list list);
void				ft_putstrbk0(char *str, int len);

/*
** pf_manage_struct.c
*/

void				pf_init_struct(t_flag *flag);
char				*ft_fillparsing(const char *str, int i, char *chr);
t_flag				fill_flag(t_flag flag, va_list list);
void				pf_free_struct(t_flag *flag);

/*
** pf_parsing_util.c
*/

int					pf_catch_precision(char *str, int i, va_list list);
int					pf_catch_field(char *str, int i, va_list list);
char				*pf_catch_option(char *str, int i, char *res);
char				*pf_catch_modifier(char *str, int i, char *res);

/*
** conversions :
** pf_arg_b.c
** pf_arg_c.c
** pf_arg_d.c
** pf_arg_dd.c
** pf_arg_f.c
** pf_arg_o.c
** pf_arg_oo.c
** pf_arg_p.c
** pf_arg_per.c
** pf_arg_s.c
** pf_arg_u.c
** pf_arg_uu.c
** pf_arg_x.c
** pf_arg_xx.c
** pf_arg_z.c
*/

char				*ft_flag_b(va_list list, t_flag flag);
char				*ft_flag_c(va_list list, t_flag flag);
char				*ft_flag_d(va_list list, t_flag flag);
char				*ft_flag_dd(va_list list, t_flag flag);
char				*ft_flag_f(va_list list, t_flag flag);
char				*ft_flag_o(va_list list, t_flag flag);
char				*ft_flag_oo(va_list list, t_flag flag);
char				*ft_flag_p(va_list list, t_flag flag);
char				*print_address(void *address);
char				*ft_flag_per(t_flag flag);
char				*ft_flag_s(va_list list, t_flag flag);
char				*ft_flag_u(va_list list, t_flag flag);
char				*ft_flag_uu(va_list list, t_flag flag);
char				*ft_flag_x(va_list list, t_flag flag);
char				*ft_flag_xx(va_list list, t_flag flag);
char				*ft_flag_other(t_flag flag);

/*
** pf_conversion.c
*/

char				*handle_field(t_flag flag);
char				*add_sign(char *str, char *option);
char				*bytes_to_str(unsigned char b[8]);
int					ft_char_only(char *str, char c, char d);
char				*add_hashtag(char *str, char *add);

/*
** pf_conversion_util.c
*/

char				*zero_fill(char *str, int i);
char				*zero_fill_l(char *str, int i);
char				*space_fill_l(char *str, int i);
char				*space_fill_r(char *str, int i);

/*
** pf_util.c
*/

char				*ft_ltoa_base(long value, int base);
char				*ft_ltoa_base_2(long value, int base);
int					ft_size(long n);
char				*ft_ltoa(long n);
char				*pf_strjoin(char const *s1, char const *s2);

/*
** pf_util_2.c
*/

int					search_zero(char *str);
int					char_counter(char *str, char c);
char				*precision_string(char *str, int i);

/*
** 								FLOAT :
*/

/*
** pf_atoull.c
*/

char				*ft_decimal_zeros(int zero);
unsigned long long	ft_decimal_process(unsigned long long pows[56],
					char *str, int i, int tmp);
char				*ft_add_neg_pows(int zero, unsigned long long pows[56],
					char *str);
char				*ft_rightatoulltoa(char *str);
char				*ft_leftatoulltoa(char *str);

/*
** pf_double.c
*/

t_double			*ft_decomp(void *d);
char				*ft_put_zeros_neg(int pow, char *fraction);
char				*ft_put_zeros_pos(int pow, char *fraction);
char				*ft_zeros(int pow, char *fraction);
char				*ft_double(double d);

/*
** pf_float_utils.c
*/

int					ft_search_c(char *str, char c);
char				*ft_large_number(int pow, char *fraction);
char				*ft_carry(char *str);
char				*ft_round(char *str, int prec);
char				*final_process(char *tmp);

/*
** pf_split_float.c
*/

char				*case1(char *str, char *str1, char *str2, int i);
char				*case2(char *str, char *str1, char *str2, int prec);
char				*case3(char *str, char *str1, char *str2, int prec);

/*
** new_functions.c
*/

char				*init_pars(const char *str, int i);
int					get_option(t_flag *flag, int i);
int					get_field(t_flag *flag, int i, va_list list);
int					get_precision(t_flag *flag, int i, va_list list);
char				*particular_case(const char *str, int i);

/*
** Improvement of the basic libft :
*/

int					ft_chrchar(char c, char *chr);
int					ft_chrstring(const char *str, char *chr);
long				ft_digit_len(int n);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_lltoa_base(long long value, int b_size, char *base);
char				*ft_no_whitespaces(char *str);
int					ft_numlen(unsigned long long int n, int b_size);
void				ft_print_words_tables(char **tab);
char				*ft_str_dupfree(char *str);
char				*ft_strchrs(const char *s, int c);
size_t				ft_strclen(const char *s, char c);
int					ft_strcmps(const char *s1, const char *s2);
size_t				ft_strcountsplit(const char *s, char c);
char				*ft_strdups(const char *s1);
char				*ft_strjoinfs1(char *s1, char *s2);
char				*ft_strjoinfs2(char *s1, char *s2);
char				*ft_strjoinfs1s2(char *s1, char *s2);
char				*ft_strjoins(char const *s1, char const *s2);
size_t				ft_strlens(const char *s);
char				*ft_strndup(const char *s1, size_t n);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strtrimc(char const *s, char c);
void				ft_tab_filling(char **split, char *s, char c);
char				**ft_tabcpy(char **dst, char **src);
void				ft_tabdel(char **as);
char				*ft_ulltoa_base(unsigned long long n, int b_size,
					char *base);
int					ft_word_count(char *s, char c);
int					get_next_line(const int fd, char **line);

#endif
