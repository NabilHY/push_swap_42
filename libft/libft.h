/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:07 by nhayoun           #+#    #+#             */
/*   Updated: 2024/03/30 07:30:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_dlist
{
	int				index;
	int				value;
	struct s_dlist	*target_node;
	int				cost;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

size_t				ft_strlen(const char *s);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

int					ft_toupper(int c);

int					ft_tolower(int c);

char				*ft_strchr(const char *s, int c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strrchr(const char *s, int c);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

int					ft_atoi(const char *str);

void				*ft_calloc(size_t count, size_t size);

char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s1, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s1, char const *set);

char				**ft_split(char const *s, char c);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_itoa(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int n, int fd);

t_dlist				*ft_dlstnew(int index, int value);

void				ft_dlstadd_back(t_dlist **dlst, t_dlist *new);

void				ft_dlstadd_front(t_dlist **dlst, t_dlist *new);

t_dlist				*ft_dlstlast(t_dlist *dlst);

t_dlist				*ft_dlstfirst(t_dlist *dlst);

int					ft_dlstsize(t_dlist **dlist_start);

void				ft_dlstprint(t_dlist *current_node, char s);

t_dlist				*ft_dlstindex(t_dlist **stack, int index);

// void				ft_lstdelone(t_list *lst, void (*del)(void *));

// void				ft_lstclear(t_list **lst, void (*del)(void *));

// void				ft_lstiter(t_list *lst, void (*f)(void *));

// t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
//						void (*del)(void *));

#endif