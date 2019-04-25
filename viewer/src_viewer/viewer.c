/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:35:07 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/25 16:03:30 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int			main(void)
{
	WINDOW *ptr_win;

	initscr();
	cbreak();
	ptr_win = newwin(20, 30, 10, 40);
	refresh();
	start_color();
	init_pair(1, 2, 0);
	wborder(ptr_win, '|', '|', '-', '-', '+', '+', '+', '+');
	wattron(ptr_win, COLOR_PAIR(1));
	wattron(ptr_win, A_BOLD);
	mvwprintw(ptr_win, 1, 1, "This is my box !");
	wrefresh(ptr_win);
	wattroff(ptr_win, COLOR_PAIR(1));
	wattroff(ptr_win, A_BOLD);
	getch();
	endwin();
	return (0);
}
