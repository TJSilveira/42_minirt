/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_types_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:51 by amoiseik          #+#    #+#             */
/*   Updated: 2025/12/19 15:36:59 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//added new file for float imports, devided from import_types_1.c

int	rt_import_float_non_negative(char *param, float *result)
{
	if (is_float(param) == FALSE)
		return (EXIT_FAILURE);
	ft_str_to_float(param, result);
	if (*result <= 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	rt_import_float_between_01(char *param, float *result)
{
	if (is_float(param) == FALSE)
		return (EXIT_FAILURE);
	ft_str_to_float(param, result);
	if (*result < 0 || *result > 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
