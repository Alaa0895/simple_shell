#include "shell.h"

/**
 * find_command_in_path - Searches for a command in
 * the directories specified by PATH
 * @cmd: Command to search for
 * Return: Full path to the command if found, NULL otherwise
 */
char *find_command_in_path(char *cmd)
{
	char *path = getenv("PATH");
	char *path_copy, *dir;
	char *full_path = malloc(PATH_MAX);

	if (!full_path)
	{
		perror("Unable to allocate buffer for full path");
		return (NULL);
	}
	if (!path)
	{
		free(full_path);
		return (NULL);
	}
	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Unable to duplicate PATH");
		free(full_path);
		return (NULL);
	}

	for (dir = strtok(path_copy, ":"); dir; dir = strtok(NULL, ":"))
	{
		snprintf(full_path, PATH_MAX, "%s/%s", dir, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
	}
	free(path_copy);
	free(full_path);
	return (NULL);
}
