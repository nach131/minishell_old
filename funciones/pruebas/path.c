#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *path = "/Library/Frameworks/Python.framework/Versions/3.10/bin:/Library/Frameworks/Python.framework/Versions/3.7/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public:/opt/X11/bin:/usr/local/mongodb/bin";
	char **paths = NULL;
	int num_paths = 0;

	printf("Original path: %s\n\n", path);

	// Create a copy of the original path as strtok will modify it
	char *path_copy = strdup(path);

	// Temporary variable to hold each token
	char *token = strtok(path_copy, ":");

	// Count the number of tokens
	while (token != NULL)
	{
		num_paths++;
		token = strtok(NULL, ":");
	}

	// Allocate memory for paths
	paths = (char **)malloc(num_paths * sizeof(char *));

	// Reset the tokenization process
	free(path_copy);				// Free the memory used for path_copy
	path_copy = strdup(path);		// Create a new copy of the original path
	token = strtok(path_copy, ":"); // Reset token to the start of the new copy

	// Store each token in paths
	for (int i = 0; i < num_paths; i++)
	{
		paths[i] = strdup(token);
		token = strtok(NULL, ":");
	}

	// Print each value in paths
	for (int i = 0; i < num_paths; i++)
	{
		printf("Path %d: %s\n", i + 1, paths[i]);
	}

	// Clean up allocated memory
	for (int i = 0; i < num_paths; i++)
	{
		free(paths[i]);
	}
	free(paths);
	free(path_copy);

	return 0;
}
