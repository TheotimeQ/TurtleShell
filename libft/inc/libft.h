/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquere <tquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:22:44 by tquere            #+#    #+#             */
/*   Updated: 2023/01/11 17:31:14 by tquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4098
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_flag
{
	int				fd;
	int				nb_caract;
	int				index;
	int				error;

}	t_flag;

//ft_gnl
char		*get_next_line(int fd);
char		*save(char *str, char *buffer, int i);

//ft_is
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isnum(char *str);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_is_double(int *tab, int size);
int			ft_isalphas(char *str);
int			ft_isalphas_nums(char *str);

//ft_ls
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//ft_mem
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);

//ft_printf
void		ft_putchar_fd_printf(char c, t_flag *all_flag);
void		ft_putstr_fd_printf(char *s, t_flag *all_flag);
void		ft_putnbr_fd_printf(long long int nb, t_flag *all_flag);
void		ft_basprintf(unsigned int nb_long, char *base, t_flag *all_flag);
void		ft_uprintf(unsigned long int nb_long, char *base, t_flag *all_flag);
int			ft_printf(int fd, const char *str, ...);

//ft_put
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//ft_str
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

//ft_strs
int			ft_count_tab(char **tab);
void		ft_free_tab(char **tab);
char		**ft_split(char const *s, char c);
void		ft_sort_tab(char **tab);
void		ft_print_tab(char **tab);

//ft_to
int			ft_toupper(int c);
int			ft_tolower(int c);
long int	ft_atoi(const char *str);
char		*ft_itoa(int n);

//ft_max
int			ft_isinset(char c, char const *set);
int			ft_isspace(int c);
void		ft_strdel(char **as);
char		*ft_strnew(size_t size);
void		ft_strsdel(char ***strs);
char		**ft_strsnew(size_t size);
void		ft_memdel(void **ap);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);

#endif
