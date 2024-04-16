#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

void    print_grid(char **grid, int limit)
{
    int x;
    int y;

    x = 0;
    y = 0;
    printf("this is print_grid\n");
    printf("this is checking [%d]\n", grid[2][2]);
    while (42)
    {
        printf("[%c] ", grid[x][y]);
        y++;
        if (y == limit)
        {
            printf("\n");
            y = 0;
            x++;
        }
        if (x == limit)
        {
            printf("end of print_grid\n");
            break;
        }
    }
}

int check_xy(char **grid, int fix_x, int fix_y, int limit, char test)
{
    int     x;
    int     y;
    char    test;

    x = 0;
    y = 0;
    while (x <= limit && y <= limit)
    {
        if (test == grid[x++][fix_y] || test == grid[fix_x][y++])
            return (0);
    }
    return (1);
}

char    **save_grid(char *av, int limit)
{
    int     i;
    int     x;
    int     y;
    char    **grid;

    i = 0;
    x = 0;
    y = 0;
    grid = malloc(sizeof(char *) * (limit + 1));
    grid[x] = malloc(sizeof(char) * (limit + 1));
    printf("this is save grid\n");
    printf("this is av [1]\n[%s]\n", av);
    while (av[i] != '\0')
    {
        if (av[i] >= '0' && av[i] <= '9')
        {
            grid[x][y] = av[i];
            printf("[%c] ", grid[x][y]);
            y++;
        }
        i++;
        if (av[i] == ',')
        {
            grid[x][y] = '\0';
            printf("\n");
            x++;
            grid[x] = malloc(sizeof(char) * (limit + 1));
            y = 0;
        }
    }
    printf("\nend of save_grid\n");
    return (grid);
}

int main(int ac, char *av[]){
    char    **grid;
    int     limit;

    limit = 4;
    if (ac != 2)
    {
        printf("wrong input\n");
        return (0);
    }
    grid = save_grid(av[1], limit);
    print_grid(grid, limit);
    return (0);
}