
#include"../inc/minishell.h"

int		cmp_by_alpha(a ,b)
{
	return (ft_strncmp(a->name, b->name));
}

void				env_list_sort(t_info *env, int cmp(t_info.env *, t_info.env *))
{
	env.env		*last_ptr;
	int			swapped;

	swapped = 1;
	ptr_1 = env;
	last_ptr = NULL;
	if (!env)
		return ;
	while (swapped)
	{
		swapped = 0;
		ptr_1 = env;
		while (ptr_1->next != last_ptr)
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
	env_list_sort(sh->env, &cmp_by_alpha);
	display_env_list(sh->env, sh->pipe, EXPORT);
	sh->last_status = 0;
}

//printf("%s %s\n", info->env[5][0], info->env[5][1]);