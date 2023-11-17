#include "shell.h"

/**
 * i_cmd - the function for determines if execuve
 * @sk: the sk struct
 * @path: the path of the file
 * Return: 1 or 0
 */
int i_cmd(AWS *sk, char *path)
{
	struct tnt trt;

	(void)sk;
	if (!path || tnt(path, &trt))
	{
		return (0);
	}
	if (trt.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * d_chars - the duplicates chars
 * @pathr: the path of string
 * @set: the index
 * @but: the stopping index
 * Return: the pointer
 */
char d_chars(char *pathr, int set, int but)
{
	static char BUFFER[1024];
	int i = 0;
	int k = 0;

	for (i = set; i < but && pathr[i] != ':'; i++)
		BUFFER[K++] = pathr[i];
	BUFFER[k] = 0;
	return (BUFFER);
}

/**
 * f_path - the cmd in the path
 * @sk: the sk struct
 * @pathr: the path of string
 * @cmd: the command i find
 * Return: the full path fo command
 */
char *f_path(AWS *sk, char *pathr, char *cmd)
{
	int i = 0;
	int curr_pos = 0;
	char *path;

	!pathr ? (return (NULL), 0) : 0;
	if ((_strlen(cmd) > 2) && start_with(cmd, "./"))
	{
		if (i_cmd(sk, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathr[i] || pathr[i] == ':')
		{
			path = d_chars(pathr, curr_pos, i);
			if (!*path)
			{
				_strcat(path, cmd);
			}
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (i_cmd(sk, path))
				return (path);
			if (!pathr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
