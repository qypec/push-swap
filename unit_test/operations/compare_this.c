#include "unit_test_operations.h"

# define NUMBER(matr) matr[0]
# define CORRECT_POSITION(matr) matr[1]

static char				*get_actual_result(t_psstk *stack)
{
	t_buff				*buff;
	char				*tmp;
	size_t				i;

	buff = ft_buffinit(100);
	i = 0;
	while (i < stack->size)
	{
		tmp = ft_itoa((long long)(stack->arr[i].number));
		ft_buffadd(buff, tmp);
		ft_strdel(&tmp);
		ft_buffaddsymb(buff, '|');
		tmp = ft_itoa((long long)(stack->arr[i].correct_position));
		ft_buffadd(buff, tmp);
		ft_strdel(&tmp);
		if (++i < stack->size)
			ft_buffaddsymb(buff, ' ');
	}
	return (ft_strdup(buff->str));
}

static void				print_stacks(char *actual, char *expected)
{
	char				**matr_ac;
	char				**matr_ex;
	char				**data_ac;
	char				**data_ex;
	size_t				i;

	matr_ac = ft_strsplit(actual, ' ');
	matr_ex = ft_strsplit(expected, ' ');
	ft_printf("\t{cyan}actual:\t\texpected:{reset}\n");
	i = 0;
	while (matr_ac[i] != NULL && matr_ex[i] != NULL)
	{
		data_ac = ft_strsplit(matr_ac[i], '|');
		data_ex = ft_strsplit(matr_ex[i], '|');
		ft_printf("\t[%d] %s | %s", i, NUMBER(data_ac), CORRECT_POSITION(data_ac));
		ft_printf("\t%s | %s\n", NUMBER(data_ex), CORRECT_POSITION(data_ex));
		ft_matrdel(&data_ac);
		ft_matrdel(&data_ex);
		i++;
	}
	ft_matrdel(&matr_ac);
	ft_matrdel(&matr_ex);
}

int						compare_this(t_psstk *stack, \
							const char *expected_result, const char *operation)
{
	int					equal_or_no;
	char				*actual_result;

	ft_printf("\toperation: %s\n\n", operation);
	actual_result = get_actual_result(stack);
	print_stacks(actual_result, (char *)expected_result);
	equal_or_no = ft_strequ(actual_result, expected_result);
	ft_strdel(&actual_result);
	ft_printf("\n");
	return (equal_or_no);
}
