#include "../philo.h"

int parsing(char **argv)
{   
    int i;
    int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return(printf("ERROR, BAD ARGUMENTS GIVE -> %c\n", argv[i][j]));
			j++;
		}
		i++;
	}
    return(0);
}
