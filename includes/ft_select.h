/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:07:52 by ezonda            #+#    #+#             */
/*   Updated: 2019/06/25 01:01:34 by ezonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"

# include <curses.h>
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>

struct termios	term;
struct winsize	wind;;

typedef struct	s_var
{
	int pos;
	int nb_args;
	char **args;
	char **selected;
	int char_count;
	int nb_cols;
	int nb_row;
}				t_var;

void	display(t_var *data);
void	default_display(t_var *data);
void	clear_display(t_var *data);

void	select_arg(t_var *data);
int		check_selection(t_var *data, char *str);

void	remove_arg(t_var *data);
void	move_left(t_var *data);
void	move_right(t_var *data);
void	move_down(t_var *data);
void	move_up(t_var *data);

void	signal_handler(int signal);
int		ft_putchar_v2(int c);
void	free_tab(char **tab);
char	**ft_tabdup(char **tab);
void	init_data(t_var *data);

int		hide_cursor(int mod);

void	check_winsize(t_var *data);

int		count_words(t_var *data);

void	update_data(int mod, t_var *data);

void	get_key(t_var *data);

#endif
