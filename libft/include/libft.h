/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:52:37 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/30 16:01:23 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(x) (x < 0) ? -(x) : x

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
	int				id;
}					t_btree;

typedef	struct		s_infos2
{
	int				words;
	char			**new;
	char			*tmp;
	int				t;
	int				i;
}					t_infos2;

typedef	struct		s_infos
{
	int				words;
	unsigned char	**new;
	int				t;
	int				i;
}					t_infos;

typedef struct		s_itoa
{
	char			*buff;
	int				i;
	int				negative;
	long long int	nb;
}					t_itoa;

int					ft_isinstr(char c, char *str);
int					ft_count_words(char const *s, char c);
int					*ft_datodi(char **tab);
int					ft_readline(char *line, const int fd);
void				ft_itabremove(int **tab, int index, int len);
int					*id(void);
int					ft_rand(void);
void				btree_del(t_btree *tree);
void				ft_swap_str(char **a, char **b);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
char				**ft_strsplit_once(char *s, char c);
void				ft_tabdel(char ***tab);
char				**ft_tabdup(char **tab);
size_t				ft_tablen(char **tab);
int					ft_tabremove(char ***tab, char *str, char *by);
char				*ft_newclean(char *str);
char				**ft_tabstr(char **tab, char *str);
t_btree				*btree_create_node(void *item);
void				btree_insert_data(t_btree **root, void *item, int bin);
char				*ft_ctoa(char c);
char				**ft_strsplit_op(char const *s);
char				ft_getlast(char *str);
int					ft_isspace(int c);
char				***ft_tabsplit(char **tab, char *c);
void				ft_remove_shit(char ***new);
void				ft_replace_with_shit(char **s);
int					get_next_line_stdin(int fd, char **line);
void				ft_lstpushback(t_list **blst, void const *content,
				size_t content_size);
int					get_next_line(int const fd, char **line);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_intlength(long long int n);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplit_whitespace(char *s);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrchr(const char *s, int c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_punbrendl(int n);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
char				*ft_itoa(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_strclr(char *s);
char				*ft_strdup(char *src);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, int nb);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
long long			ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
