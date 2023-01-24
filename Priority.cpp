#include <iostream>
using namespace std;
void Priority(int pi[], int at[], int bt[], int n)
{
    int i, j, k = 1, b = 0, min, t, temp[10];
    int wt[10], tat[10], atat = 0, awt = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (at[i] < at[j])
            {
                t = at[j];
                at[j] = at[i];
                at[i] = t;

                t = bt[j];
                bt[j] = bt[i];
                bt[i] = t;
            }
        }
    }

    for (j = 0; j < n; j++)
    {
        b = b + bt[j];
        min = bt[k];

        for (i = k; i < n; i++)
        {
            min = pi[k];
            if (b >= at[i])
            {
                if (pi[i] < min)
                {
                    t = at[k];
                    at[k] = bt[i];
                    at[i] = t;
                    t = bt[k];
                    bt[k] = bt[i];
                    bt[i] = t;
                    t = bt[k];
                    bt[k] = bt[i];
                    bt[i] = t;
                }
            }
        }
        k++;


        
    }
    temp[0] = 0;
    for (int i = 0; i < n; i++)
        {
            wt[i] = 0;
            tat[i] = 0;
            temp[i + 1] = temp[i] + bt[i];
            wt[i] = temp[i] - at[i];
            if (wt[i] < 0)
            {
                wt[i] = 0;
            }
            tat[i] = wt[i] + bt[i];
            awt = awt + wt[i];
            atat = atat + tat[i];
            

            cout << " " << i + 1 << "\t\t" << at[i] << "\t\t"
                 << bt[i] << "\t\t" << tat[i] << "\t\t "
                 << wt[i]<< endl;
        }
        cout << "avg tat = " << (float)atat / (float)n << endl;
        cout << "avg wt = " << (float)awt / (float)n << endl;
}
int main()
{
    int pi[] = {2,1,3,4};
    int at[] = {0,2,4,6};
    int bt[] = {7,2,1,5};
    int n = 4;
    Priority(pi,at,bt,n);
    return 0;
}