#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

char check_xy(char **grid, int fix_x, int fix_y, int limit, char test)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    printf("this is checking in chec [0][0] : [\"%c\"]\n", grid[0][0]);
    while (limit-- > 0)
    {
        if ((test == grid[fix_x][y++]) ||(test == grid[x++][fix_y]))
        {
            //printf("x:[%d], y:[%d], grid is [%c], test:[%c]\n", x, y, grid[fix_x][y], test);
            //printf("x:[%d], y:[%d], grid is [%c], test:[%c]\n", x, y, grid[x][fix_y], test);
            //printf("do not replace with this [%c]\n", test);
            return ('0');
        }
    }
    printf("replace with this [%c]\n", test);
    return (test);
}

int     prior_size(**grid)
{

}

char    **priority_arr(char **grid, int limit)
{
    int     x;
    int     y;
    int     i;
    int     j;
    int     m;
    int     n;
    char    *p;
    char    *test;

    i = limit + 4;
    j = 0;
    m = 0;
    n = 1;
    x = 0;
    y = 0;
    test = "1234";
    p = (char *)malloc(sizeof(char) * (limit + 5));//p[prior][box][x][y][possible answer...]['\0']
    p[m][0] = strlen(p[m]);
    p[m][n++] = '0'; //box
    p[m][n++] = x; //x
    p[m][n++] = y; //y
    while (test != '\0')
    {
        if (check_xy(char **grid, int x, int y, int limit, char test) != '0');
            p[n++] = test++;
    }

}

int main()
{
    int     limit;
    char    **grid;
    
    limit = 4;
    grid = (char **)malloc(sizeof(char *) * (limit + 1));
    *grid = (char *)malloc(sizeof(char) * (limit + 1));
    grid[0] = "1234";
    grid[1] = "2A41";
    grid[2] = "3412";
    grid[3] = "4123";
    priority_grid(grid, limit);
}