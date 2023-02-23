#include "../inc/minishell.h"

int	error_wrong_pipe(t_parse_lexer *pl)
{
	// static int start_of_group = 1;
	static int no_exe_yet = 1;

	printf("is exe %d\n", pl->is_exe);
	if (pl->is_exe)
		no_exe_yet = 0;
	if (no_exe_yet && pl->cat == PIPE)
		return (1);
	if (!no_exe_yet && pl->cat == PIPE)
		no_exe_yet = 1;
	return (0);
}