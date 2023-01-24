
#include<stdio.h>
#include<stdlib.h> //for abs
#include<stdbool.h>  //for bool
#include<limits.h>  //for INT_MAX
#include<string.h> //for memset
int findclosest(int rq[],bool visited[], int initial, int n){
    int min=INT_MAX,min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && abs(initial-rq[i]<min))
        {
            min = abs(initial-rq[i]);
            min_index = i;
        }
        
    }
    return min_index;
    

}

int sstf(int rq[], int initial, int seek[], bool visited[], int n){
    int i=0, min_index;
    int  completed=0, headmov =0;
    while(completed!=n){
        min_index=findclosest(rq, visited, initial, n);
        headmov += abs(initial - rq[min_index]);
        initial = rq[min_index];
        seek[i++] = rq[min_index];
        visited[min_index] = true;


        

        completed++;

    }
    return headmov;

}


int main(int argc, char const *argv[])
{
    int rq[10] = {176, 79, 34, 60, 92, 11, 41, 114}, initial=50, n=8;
    int seek[8], headmov=0;

    bool visited[n];        //to keep track of visited cylinder
    memset(visited, false, n*sizeof(bool));

    headmov = sstf(rq, initial, seek, visited, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d \n",seek[i]);
    }
    

    printf("head moves = %d",headmov);
    return 0;
}
