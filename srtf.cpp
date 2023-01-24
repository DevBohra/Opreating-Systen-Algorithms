#include <iostream>
using namespace std;

void strf(int p[], int at[], int bt[], int n){
    int wt[10], tat[10], ct, atat = 0, awt = 0;
    int time, done = 0, s;
    int rt[10];

    for (int i = 0; i < n; i++)
    {
        rt[i] = bt[i];
    }
    cout << "process" << "Arrival time" << "Brust time" << "turm around time" << "wait time" << "completion time"<< endl;
    
    for ( time = 0; done != n; time++)
    {
        for (int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i]){
                s = i;
            }
        }
        rt[s]--;
        if(rt[s]==0){
            done++;
            ct = time + 1;
            tat[s] = ct - at[s];
            wt[s] = ct - bt[s] - at[s];
            atat = atat + tat[s];
            awt = awt + wt[s];

            cout<<s+1 << "\t\t" << at[s] << "\t\t" << bt[s] << "\t\t" << tat[s] << "\t\t "<< wt[s]<< "\t\t" << ct<<endl;

        }
       
    }
    cout << atat/n;
    cout << awt/n;
        
    
    

}

int main()
{
    int p[10] = {1,2,3,4};
    int at[10]= {0,1,2,3};
    int bt[10] = {3,1,1,2};
    int n=4;
    strf(p,at,bt,n);

    return 0;
}