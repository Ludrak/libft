/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobino <lrobino@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:57:39 by lrobino           #+#    #+#             */
/*   Updated: 2020/07/15 22:22:35 by lrobino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
**	Need to add more sorting algorithms
*/
# define BUBBLE_SORT	0

# define FIRST_FREE 1
# define LAST_FREE	2
# define BOTH_FREE	3
# define NO_FREE	4

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
void				ft_freestab(char **tab);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strstartswith(const char *str, const char *prefix);
int					ft_strendwith(const char *str, const char *suffix);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *little,
					const char *big, size_t len);
int					ft_atoi(const char *nptr);
int					ft_atoi_base(char *str, char *base);
char				*ft_strdup(const char *s);
char				*ft_strldup(const char *s, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int c, int fd);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strinsert(char *src, char *in, size_t pos);
int					ft_strnum(char *str);
int					ft_sign(float i);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
char				*ft_itoa_base(int n, char *base);
char				*ft_ltoa_base(long n, char *base);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				**ft_split(const char *s, char c);
char				**ft_splitcharset(const char *str, const char *charset);
int					ft_constrain(int val, int min, int max);

/*
**	CHAINED LIST UTILS
*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
void				ft_lstsort(int sort_type, t_list **lst,
					int (*cmp)(void*, void*));
void				ft_bubblesort(t_list **alst, int (*cmp)(void*, void*));

#endif
