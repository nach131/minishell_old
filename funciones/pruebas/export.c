#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_env_strings(const void *a, const void *b)
{
	// The environment strings are in the format "VARIABLE=value"
	// We need to compare only the VARIABLE part, so find the '=' character.
	const char *str_a = *(const char **)a;
	const char *str_b = *(const char **)b;
	// const char *equals_a = strchr(str_a, '=');
	// const char *equals_b = strchr(str_b, '=');

	return strcmp(str_a, str_b);
}

// void custom_qsort(void *base, size_t num_elements, size_t element_size, int (*compare)(const void *, const void *))
// {
// 	char *arr = (char *)base;
// 	size_t i, j;
// 	char *temp = (char *)malloc(element_size);

// 	for (i = 0; i < num_elements - 1; i++)
// 	{
// 		for (j = i + 1; j < num_elements; j++)
// 		{
// 			char *element_a = arr + i * element_size;
// 			char *element_b = arr + j * element_size;

// 			if (compare(element_a, element_b) > 0)
// 			{
// 				memcpy(temp, element_a, element_size);
// 				memcpy(element_a, element_b, element_size);
// 				memcpy(element_b, temp, element_size);
// 			}
// 		}
// 	}

// 	free(temp);
// }

void custom_qsort(void *base, size_t num_elements, size_t element_size, int (*compare)(const void *, const void *))
{
	char *arr = (char *)base;
	size_t i = 0;
	char *temp = (char *)malloc(element_size);

	while (i < num_elements - 1)
	{
		size_t j = i + 1;
		while (j < num_elements)
		{
			char *element_a = arr + i * element_size;
			char *element_b = arr + j * element_size;

			if (compare(element_a, element_b) > 0)
			// if (strcmp(element_a, element_b) > 0)
			{
				memcpy(temp, element_a, element_size);
				memcpy(element_a, element_b, element_size);
				memcpy(element_b, temp, element_size);
			}

			j++;
		}

		i++;
	}

	free(temp);
}

int main(void)
{

	char *env[] = {
		"NVM_RC_VERSION=",
		"TERM_PROGRAM=iTerm.app",
		"NVM_CD_FLAGS=",
		"SHELL=/bin/bash",
		"TERM=xterm-256color",
		"CLICOLOR=1",
		"TMPDIR=/var/folders/4n/804bwxpj5vl86x7z5h4zk0_h0000gn/T/",
		"Apple_PubSub_Socket_Render=/private/tmp/com.apple.launchd.QvsX3bwQhs/Render",
		"TERM_PROGRAM_VERSION=3.3.12",
		"TERM_SESSION_ID=w0t0p2:8305BA1D-952A-488D-BE41-B7AE09E8DC1F",
		"USER=nacho",
		"NVM_DIR=/Users/nacho/.nvm",
		"COMMAND_MODE=unix2003",
		"SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.7iauEZO949/Listeners",
		"__CF_USER_TEXT_ENCODING=0x0:0:0",
		"LSCOLORS=ExFxBxDxCxegedabagacad",
		"PATH=/Library/Frameworks/Python.framework/Versions/3.10/bin:/Library/Frameworks/Python.framework/Versions/3.7/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/opt/X11/bin:/usr/local/mongodb/bin",
		"PWD=/Volumes/1TB/Dropbox/00_42Barcelona/42Barcelona/C3/minishell/sources",
		"LANG=es_ES.UTF-8",
		"ITERM_PROFILE=Nach",
		"XPC_FLAGS=0x0",
		"PS1=\\[\\033[36m\\]\\u\\[\\033[m\\]@\\[\\033[32m\\]\\h:\\[\\033[33;1m\\]\\w\\[\\033[m\\]$",
		"XPC_SERVICE_NAME=0",
		"COLORFGBG=15;0",
		"HOME=/Users/nacho",
		"SHLVL=2",
		"LC_TERMINAL_VERSION=3.3.12",
		"GREP_OPTIONS=--color=auto",
		"ITERM_SESSION_ID=w0t0p2:8305BA1D-952A-488D-BE41-B7AE09E8DC1F",
		"LOGNAME=nacho",
		"DISPLAY=/private/tmp/com.apple.launchd.8gC13ssoJV/org.xquartz:0",
		"LC_TERMINAL=iTerm2",
		"SECURITYSESSIONID=186a7",
		"COLORTERM=truecolor",
		"_=./minishell",
		"OLDPWD=/Volumes/1TB/Dropbox/00_42Barcelona/42Barcelona/C3/minishell/sources/lib",
		NULL};

	// Calculate the number of elements in the array
	size_t env_size = sizeof(env) / sizeof(env[0]);

	// Sort the array using the custom comparison function
	custom_qsort(env, env_size - 1, sizeof(char *), compare_env_strings);

	// Print the sorted array
	for (size_t i = 0; i < env_size - 1; i++)
	{
		printf("%s\n", env[i]);
	}

	return 0;
}

// int i = 1;
// while (env[i] != NULL)
// {
// 	printf("%s\n", env[i]);
// 	i++;
// }
