<<<<<<< HEAD
#include <stdio.h>
#include <math.h>

int main()
{
    int i,o;
    char linha1[15],linha2[15];
    double x1,y1,x2,y2, distancia;

    x1=x2=y1=y2=distancia=0;

    fflush(stdin);
    gets(linha1);
    fflush(stdin);
    gets(linha2);

    for(i = 0 ; i < 15 ; i++)
    {
        if(linha1[i] == '.')
        {
            for(o = i; o < 15; o--)
            {
                if(linha1[o] >= '0' && linha1[o] <= '9')
                {
                    
                }
            }
        }
    }

    distancia = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    printf(" %.4lf\n", distancia);
=======
#include <stdio.h>
#include <math.h>

int main()
{
    int i,o;
    char linha1[15],linha2[15];
    double x1,y1,x2,y2, distancia;

    x1=x2=y1=y2=distancia=0;

    fflush(stdin);
    gets(linha1);
    fflush(stdin);
    gets(linha2);

    for(i = 0 ; i < 15 ; i++)
    {
        if(linha1[i] == '.')
        {
            for(o = i; o < 15; o--)
            {
                if(linha1[o] >= '0' && linha1[o] <= '9')
                {
                    
                }
            }
        }
    }

    distancia = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    printf(" %.4lf\n", distancia);
>>>>>>> b40020655e623470d8694fef4dab9e11f5ddbd76
}