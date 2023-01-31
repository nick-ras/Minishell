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
char	*ft_str_cpy(char *dst, const char *src)
{
	char	*save;

	save = dst;
	if (!src || !dst)
		return (dst);
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (save);
}

static void			swap_var(t_group *a, t_group *b)
{
	/*
	char	*cmd; 
	char	*path;
	int		redirect_input;
	char	*redirect_input_filename;
	int		redirect_output;
	char 	*redirect_output_filename;
	*/
	int		int_1;
	int		int_2;
	char	*char_1;
	char	*char_2;


	ft_str_cpy(char_1 , a->cmd);
	ft_str_cpy(char_2 , a->path);
	//
	ft_str_cpy(a->cmd , b->cmd);
	ft_str_cpy(a->path , b->path);
	//
	ft_str_cpy(b->cmd , char_1);
	ft_str_cpy(b->path , char_2);
	// -part 2-
	ft_str_cpy(char_1 , a->redirect_input_filename);
	ft_str_cpy(char_2 , a->redirect_output_filename);
	//
	ft_str_cpy(a->redirect_input_filename , b->redirect_input_filename);
	ft_str_cpy(a->path , b->redirect_output_filename);
	//
	ft_str_cpy(b->redirect_input_filename , char_1);
	ft_str_cpy(b->redirect_output_filename , char_2);
	//
	int_1 = a->redirect_input;
	int_2 = a->redirect_output;
	//
	a->redirect_input = b->redirect_input;
	a->redirect_output = b->redirect_output;
	//
	b->redirect_input = int_1;
	b->redirect_output = int_2;
}

void	env_list_sort(t_group *groups, t_info *info)
{
	int			swapped;
	int i = -1;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (++i < info->num_groups)
		{
			if (cmp_by_alpha(groups[i].redirect_output_filename, groups[i + 1].redirect_output_filename) > 0)
			{
				swap_var(&groups[i], &groups[i + 1]);
				swapped = 1;
			}
		}
	}
}

void	export(t_group *groups, t_info *info)
{
	env_list_sort(groups, info);
	print_groups( groups , info);
}

//printf("%s %s\n", info->env[5][0], info->env[5][1]);
/*
int i = -1;
	while (++i < info->num_groups)

*/