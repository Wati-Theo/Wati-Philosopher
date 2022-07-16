/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati-Main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:45:28 by tschlege          #+#    #+#             */
/*   Updated: 2022/07/16 22:41:00 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Wati-Includes/Wati_Philosopher.h"

int	main(int argc, char *argv[])
{
	if (argc < 3 || argc > 6)
	{
		printf("ERR, Nb of ARG\n");
		return (1);
	}
	check_if_digit(argc, argv);
}