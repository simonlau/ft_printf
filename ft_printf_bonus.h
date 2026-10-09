#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

/* Bonus parsing state for flags '-0.', width, '#', '+', ' '. */
typedef struct s_flags
{
	int	left_align;		/* '-' */
	int	zero_pad;		/* '0' */
	int	has_precision;	/* '.' seen */
	int	precision;
	int	min_width;
	int	alt_form;		/* '#' */
	int	show_sign;		/* '+' */
	int	blank_sign;		/* ' ' */
}	t_flags;

/* TODO: parse flags/width starting at *i, fill *flags, return spec char. */
int	ft_parse_flags_bonus(const char *format, int *i, t_flags *flags);

#endif
