#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char check_xy(char **grid, int fix_x, int fix_y, int limit, char test)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    //printf("this is checking in chec [0][0] : [\"%c\"]\n", grid[0][0]);
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
    //printf("replace with this [%c]\n", test);
    return (test);
}

int main()
{
    char    i;
    char    *test;
    int     limit;
    char    **grid;
    int     x;
    int     y;
    int     m;
    int     n;
    int     t;
    char    **p;
    
    x = 0;
    y = 0;
    t = 0;
    limit = 4;
    grid = (char **)malloc(sizeof(char *) * (limit + 1));
    *grid = (char *)malloc(sizeof(char) * (limit + 1));
    grid[0] = "1000";
    grid[1] = "0000";
    grid[2] = "0002";
    grid[3] = "4103";
    test = "1234";
    p = (char **)malloc(sizeof(char *) * (20));
    while (y < limit)
    {
        if (grid[x][y] == '0')
        {
            n = 0;
            while (test[t] != '\0')
            {
                if (check_xy(grid, x, y, limit, test[t]) != '0')
                {
                    p[m] = malloc(100);
                    p[m][n++] = test[t];
                    printf("this is it [%c]\n", p[m][n - 1]);
                }
                t++;
            }
            p[m][n] = '\0';
            printf("this is the possible answer fir grid[%d][%d] is [%s]\n", x, y, p[m]);
            m++;
            t = 0;
        }
        x++;
        if (x == limit)
        {
            x = 0;
            y++;
        }
    }
}