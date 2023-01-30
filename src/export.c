#include"../inc/minishell.h"

int		cmp_by_alpha(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	env_list_sort(t_info *env)
{
	
	t_info		*ptr_1;
	t_info		*last_ptr;
	int			swapped;
	int i = -1;

	swapped = 1;
	ptr_1 = env;
	last_ptr = NULL;
	if (!env)
		return ;
	while (swapped)
	{
		swapped = 0;
		ptr_1 = env;
		while (++i < info->num_groups)
		{
			if (cmp(ptr_1, ptr_1->next) > 0)
			{
				swap_var(ptr_1, ptr_1->next);
				swapped = 1;
			}
			ptr_1 = ptr_1->next;
		}
		last_ptr = ptr_1;
	}
}

void	export(t_info *sh, char **arg)
{
	env_list_sort(sh);
	print_groups( sh -> groups, sh);
}

//printf("%s %s\n", info->env[5][0], info->env[5][1]);
/*
int i = -1;
	while (++i < info->num_groups)

*/