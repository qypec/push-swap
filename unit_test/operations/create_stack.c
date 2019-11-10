#include "unit_test_operations.h"

# define NUMBER(matr) matr[0]
# define CORRECT_POSITION(matr) matr[1]

static size_t				get_used_size(char **matr)
{
	size_t					i;
	size_t					used_size;

	used_size = 0;
	i = 0;
	while (matr[i] != NULL)
	{
		if (matr[i][0] != '0')
			used_size++;
		i++;
	}
	return (used_size);
}

static void					fill_stack(t_psstk *stack, char **matr_a)
{
	size_t					i;
	size_t					matrsize;
	char					**data;

	matrsize = ft_matrlen((const char **)matr_a);
	stack->used_size = get_used_size(matr_a);
	i = 0;
	while (i < matrsize)
	{
		data = ft_strsplit(matr_a[i], '|');
		stack->arr[i]->number = ft_atoi(NUMBER(data));
		stack->arr[i]->correct_position = ft_atoi(CORRECT_POSITION(data));
		ft_matrdel(&data);
		i++;
	}
}

void						create_stacks(t_psstk *stack_a, t_psstk *stack_b, \
								const char *a, const char *b)
{
	char					**matr_a;
	char					**matr_b;

	matr_a = ft_strsplit(a, ' ');
	matr_b = ft_strsplit(b, ' ');
	fill_stack(stack_a, matr_a);
	fill_stack(stack_b, matr_b);
}
