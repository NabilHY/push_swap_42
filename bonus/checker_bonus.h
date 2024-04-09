/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 08:23:41 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/04 05:05:55 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"
# include <limits.h>

char	*get_next_line(int fd);
void	do_op(char *str, t_dlist **stack_a, t_dlist **stack_b);
int		is_valid(char *str);
int		sorted(t_dlist **stack);
char	*split_strdup(const char *s1);
char	*split_strjoin(char *s1, char *s2);
char	*split_strchr(const char *s, int c);
char	*split_substr(char *s, size_t start, size_t len);
t_dlist	*parse_args(int ac, char **av);
int		check_args(char **arr_of_args);
void	free_arr(char **arr);
int		check_repetition(char **arr_of_args);
void	update_indexes(t_dlist **stack);
void	free_stack(t_dlist **stack);
void	free_arr(char **arr);
t_dlist	*handle_fail(char **arr);
void	free_stack(t_dlist **stack);
int		is_sorted(t_dlist **stack);
void	get_min_to_top(t_dlist **stack_a);
void	ft_chunk(t_dlist **stack_a, t_dlist **stack_b);
void	free_int_arr(int **arr, int size);
int		*arr_alloc(int size);
int		in_range(char **args);
long	ft_atol(char *str);
int		in_range(char **args);
int		ft_invalid(char **args);
void	move_node_to_stack(t_dlist **source_stack, t_dlist **dest_stack);
void	rotate_stack(t_dlist *stack);
void	rrotate_stack(t_dlist *stack);
void	swap_stack(t_dlist *tail);
int		only_whitespace(char *str);
char	**handle_set_fail(char **args_arr, char **temp, int i);
#endif