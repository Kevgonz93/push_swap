#include "../checker.h"
#include <stdio.h>

char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

void	ft_lstadd_back(t_stack *lst, t_node *new);
void	ft_lstadd_front(t_stack *lst, t_node *new);
void	ft_lstclear(t_stack *lst);
void	ft_lstdelone(t_node *lst, void (*del)(int));
void	ft_lstiter(t_node *lst, void (*f)(int));
t_node	*ft_lstlast(t_stack *lst);
t_node	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
