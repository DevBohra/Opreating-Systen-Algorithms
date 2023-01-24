#include <stdio.h> 

int main(int argc, char const *argv[])
{
    int rq[10] = {176, 79, 34, 60, 92, 11, 41, 114}, initial=50, n=8;
    int headmov=0;

    for (int i = 0; i < n; i++)
    {
        headmov += abs(initial - rq[i]);
        initial = rq[i];

    }

    for (int i = 0; i < n; i++)
    {
        printf("%d \n++",rq[i]);
    }
    

    printf("head moves = %d",headmov);


    return 0;
}
