/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:25:44 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/23 15:35:01 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>

int		main(void)
{
	initsrc();
	raw();
	printw("Hello World !");
	getch();
	endwin();
	return (0);
}