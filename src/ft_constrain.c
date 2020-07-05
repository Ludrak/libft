
#include "libft.h"

int		ft_constrain(int val, int min, int max)
{
	if (min > max)
		return (0);
	if (val > max)
		val = max;
	if (val < min)
		val = min;
	return (val);
}
