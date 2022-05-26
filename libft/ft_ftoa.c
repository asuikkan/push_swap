/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:40:10 by asuikkan          #+#    #+#             */
/*   Updated: 2022/03/07 12:40:11 by asuikkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	round_nb(t_dbl *dbl, int prec)
{
	if (prec == 0)
		dbl->integer++;
	else
	{
		if (ft_count_digits(dbl->frac_final) \
			< ft_count_digits(dbl->frac_final + 1))
			dbl->zeroes--;
		if (dbl->zeroes < 0)
		{
			dbl->integer++;
			dbl->frac_final = 0;
		}
		else
		{
			if (dbl->frac_final == 0)
				dbl->zeroes--;
			dbl->frac_final++;
		}
	}
}

static void	form_fraction(t_dbl *dbl, int prec)
{
	int					i;
	unsigned long long	round_check;

	dbl->frac_final = 0;
	dbl->zeroes = 0;
	i = 0;
	while (i++ < prec && i <= 15 + dbl->zeroes)
	{
		dbl->fraction = (dbl->fraction << 3) + (dbl->fraction << 1);
		dbl->frac_final = dbl->frac_final * 10 + (dbl->fraction >> 53);
		if (dbl->fraction != 0 && dbl->frac_final == 0)
			dbl->zeroes++;
		dbl->fraction = dbl->fraction & FIFTY_THREE_BITS;
	}
	round_check = ((dbl->fraction << 3) + (dbl->fraction << 1)) >> 53;
	if (round_check % 10 >= 5 && prec <= 15)
	{
		if (prec != 0
			|| (prec == 0 && (dbl->integer % 2 == 1 || dbl->integer == 0)))
			round_nb(dbl, prec);
	}
}

static void	exp_handler(t_dbl *dbl, short exp, long long mnts)
{
	dbl->integer = 0;
	dbl->fraction = 0;
	if (exp >= 63)
		dbl->integer = 0;
	else if (exp >= 52)
		dbl->integer = mnts << (exp - 52);
	else if (exp >= 0)
	{
		dbl->integer = mnts >> (52 - exp);
		dbl->fraction = (mnts << (exp + 1)) & FIFTY_THREE_BITS;
	}
	else if (exp < -53)
		dbl->fraction = 0;
	else if (exp < 0)
		dbl->fraction = (mnts & FIFTY_THREE_BITS) >> -(exp + 1);
}

char	*ft_ftoa(double nb, int prec)
{
	t_convert	conv;
	t_dbl		*dbl;
	short		exp;
	long long	mnts;
	int			sign;

	dbl = (t_dbl *)malloc(sizeof(t_dbl));
	if (dbl == NULL)
		exit(1);
	conv.number = nb;
	sign = 0;
	if (conv.pattern & SIXTY_FOURTH_BIT)
	{
		sign = 1;
		conv.pattern = conv.pattern ^ SIXTY_FOURTH_BIT;
	}
	exp = (conv.pattern >> 52 & ELEVEN_BITS) - EXP_BIAS;
	mnts = (conv.pattern & FIFTY_TWO_BITS) | FIFTY_THIRD_BIT;
	exp_handler(dbl, exp, mnts);
	form_fraction(dbl, prec);
	return (form_str(dbl, prec, sign));
}
