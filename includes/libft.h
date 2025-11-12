/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:34:38 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/10 13:18:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdint.h>
/*# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <bsd/string.h> */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
int		ft_isalpha(int symbol);
int		ft_isdigit(int symbol);
int		ft_isalnum(int symbol);
int		ft_isascii(int symbol);
int		ft_isprint(int symbol);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *mem_area, int symbol, size_t num_bytes);
void	ft_bzero(void *mem_area, size_t num_bytes);
void	*ft_memcpy(void *dst_mem, const void *src_mem, size_t num_bytes);
void	*ft_memmove(void *dst_mem, const void *src_mem, size_t num_bytes);
size_t	ft_strlcpy(char *dst_str, const char *src_str, size_t dst_size);
size_t	ft_strlcat(char *dst_str, const char *src_str, size_t dst_size);
int		ft_toupper(int chrctr);
int		ft_tolower(int chrctr);
char	*ft_strchr(const char *str, int chrctr);
char	*ft_strrchr(const char *str, int chrctr);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	*ft_memchr(const void *mem_area, int byte, size_t num_bytes);
int		ft_memcmp(const void *area1, const void *area2, size_t num_bytes);
char	*ft_strnstr(const char *big_str, const char *lit_str, size_t num);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count_obj, size_t size_per_obj);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
