#include <iostream>
using namespace std;
void RoundRobin(int at[], int bt[], int n , int tq){
    int wt[10], tat[10], atat = 0, awt = 0;
    int rt[10], counter, ct = 0, i ;
    counter = n;

    for (int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    cout << "process" << "Arrival time" << "Brust time" << "turm around time" << "wait time" << "completion time"<< endl;

    for (ct = 0, i = 0; counter!=0;)
    {
        if(rt[i]<=tq && rt[i]>0)
        {
            ct = ct+rt[i];
            rt[i] = 0;
            counter--;
            tat[i] = ct - at[i];
            wt[i] = ct - at[i] - bt[i];
            cout << " " << i+1 << "\t\t" << at[i] << "\t\t"<< bt[i] << "\t\t" << tat[i] << "\t\t "<< wt[i]  <<  "\t\t " << ct << endl;
            atat = atat + tat[i];
            awt = awt + wt[i];


        }
        
        else if (rt[i]>0)
        {
            rt[i] = rt[i] - tq;
            ct = ct+tq;
        }
        if (i == n-1)
        {
            i=0;
        }

        else if (at[i+1] <= ct)
        {
            i++;
        }
        
        else
        {
            i=0;
        }
        
    }
    //cout
    cout << "avg tat = " << (float)atat/n << endl;
    cout << "avg wt = " << (float)awt/n << endl;


    
}
int main()
{
    int p[] = {1,2,3,4};
    int at[]= {0,0,1,3};
    int bt[] = {5,4,2,1};
    int n=4,tq=2;
    RoundRobin(at,bt,n,tq);
    return 0;
}