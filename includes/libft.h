/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggenois <ggenois@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 11:21:37 by ggenois      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/08 16:17:07 by ggenois     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_pfdata
{
	char			t;
	int				w;
	char			*input;
	int				p;
	int				s;
	int				wspace_char;
	struct s_list	*f;
	struct s_list	*data;
}					t_pfdata;

void				ftpf_tmp_printpfdata(t_pfdata **dt);

void				ftpf_precision(t_pfdata **dt);
void				ft_lstcutat(t_list **lst, int count);
int					ftpf_getlength(t_pfdata **dt);
char				*ftpf_get_n(t_pfdata **dt, va_list *data);
void				ftpf_numbers_put_ox(t_pfdata **dt, int mode);
char				ftpf_getcfl(t_list **lst);
int					ftpf_iscinlist(t_list **list, char c);
int					ftpf_istypenum(char c);
void				ftpf_addprefix(t_pfdata **dt);
int					ftpf_numbers(t_pfdata **dt, va_list *data);
int					ftpf_islflag(char c);
int					ftpf_write(t_pfdata **data);
void				ftpf_strings(t_pfdata **dt, va_list *data);
void				ftpf_types(char **input, va_list *data, int *size);
char				*ftpf_isolate(const char **str, int *ipos, int *size);
void				ftpf_core(const char **str, va_list *data, int *istatus);
int					ft_printf(const char *str, ...);

int					ft_strlenw(wchar_t *s);
int					get_next_line(const int fd, char **line);
void				ft_putlchar(wchar_t c);
void				ft_putlstr(wchar_t *s);
void				ft_putlsnbr(long signed int n);
void				ft_putlunbr(long unsigned int n);
char				*ft_luitoa_base(long unsigned int nbr, size_t base);
char				*ft_uitoa_base(unsigned int nbr, size_t base);
char				*ft_litoa_base(long signed int nbr, int base);
char				*ft_itoa_base(int nbr, int base);
char				*ft_strupper(char *str);
void				ft_putunbr(unsigned int n);
//int					ft_atoi_base(const char *str, int base);
int					ft_convert_baseten(int mode, ...);
int					ft_strfindchar(char *haystack, char item);

int					ft_isprintable(int c);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *d, const char *s);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *str, char *to_find, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

int					ft_findcis(char **haystack, char item);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char**as);
void				ft_strclr(char*s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char *s, char delimiter);
char				*ft_itoa(int nbr);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_llitoa_base(long long int nbr, long long int base);
char				*ft_lluitoa_base(long long unsigned int nbr, long long unsigned int base);
void				ft_lstfromstr(t_list **lst, char **str);
int					ft_lstcount(t_list **d);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **list, void (*del)(void*, size_t));
void				ft_lstdel(t_list **list, void (*del)(void *, size_t));
void				ft_lstadd(t_list **list, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstwipe(t_list **list);
t_list				*ft_lstcpy(t_list *src);

#endif
