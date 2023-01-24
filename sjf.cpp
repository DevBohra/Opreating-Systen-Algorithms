#include <iostream>
using namespace std;

int main()
{
    int pro[] ={1,2,3,4};
    int bt[] = {3,4,2,4};
    int t;
    int wt[5], tat[5];

    int n = sizeof(pro)/ sizeof(pro[0]);

    //sort
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n-i-1; j++)
    //     {
    //         if(bt[j]>bt[j+1]){
    //             t = bt[j];
    //             bt[j] = bt[j+1];
    //             bt[j+1] = t;

    //             t = pro[j];
    //             pro[j] = pro[j+1];
    //             pro[j+1] = t;


    //         }
    //     }
        
    // }

    //ljf

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(bt[j]<bt[j+1]){
                t = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = t;

                t = pro[j];
                pro[j] = pro[j+1];
                pro[j+1] = t;


            }
        }
        
    }
    cout << "process" << "Brust time" << "turm around time" << "wait time"<< endl; 

    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (int j = 0; j < i; j++)
        {
            wt[i] = wt[i] +bt[j];
        }
        tat[i] = wt[i] + bt[i]; 
        cout<< " " << i+1 << "\t\t" << bt[i] << "\t\t" << tat[i] << "\t\t "<< wt[i]<<endl;
    }
    
    
    return 0;
}