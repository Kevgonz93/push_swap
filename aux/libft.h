/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:49:30 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/16 17:49:34 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include "../types.h"
# include <stdlib.h>
# include <stdio.h>

///	LIBC FUNCTIONS
void	*ft_memset(void *buff, int value, size_t size);
void	ft_bzero(void *buff, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *src, int c, size_t n);
void	*ft_calloc(size_t data, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strchr(const char *c, int n);
char	*ft_strrchr(const char *c, int n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);

///	ADITIONALS FUNCTIONS

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isalpha(int c);
int		ft_isdigit(int n);
int		ft_isalnum(char c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *src1, const void *src2, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

///	BONUS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_node	*ft_lstnew(int content);
t_node	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack *lst, t_node *new);
void	ft_lstadd_back(t_stack *lst, t_node *new);
void	ft_lstdelone(t_node *lst, void (*del)(int));
void	ft_lstclear(t_stack *lst, void (*del)(int));
int		ft_lstsize(t_node *lst);
void	ft_lstiter(t_node *lst, void (*f)(int));
t_stack	*ft_lstmap(t_node **lst, int(*f)(int), void (*del)(int));

#endif
