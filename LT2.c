#include <stdio.h>
void what(int x[][15], int r, int c);
int main()
{
    int a[15][15], i, j, p, q;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            a[i][j] = 10 * i + j;
        }
    }

     p = 1;
	  q = 5;
    what((int(*)[15]) & a[p + 3][q + 3], 3, 3);

    return 0;
}
void what(int x[][15], int r, int c)
{
    int i, j;
    for (i = 0; i > -r; --i)
    {
        for (j = 0; j > -c; --j)
        {
            printf("%d", x[i][j]);
            putchar('\n');
        }
    }
}
