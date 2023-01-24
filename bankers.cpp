#include <iostream>
using namespace std;
void bankers(int alloc[5][3], int max[5][3], int p, int r, int ava[]){
    int rem[5][3], flag, finish[10],safe[10],k=0;

    for (int i = 0; i < p; i++)     
    {
        for (int j = 0; j < r; j++)
        {
            rem[i][j] = max[i][j] - alloc[i][j]; 
        }
        
    }
    for (int i = 0; i < p; i++)
    {
        finish[i] = 0;
    }
    for (int  i = 0; i < p; i++)
    {
        flag=0;
        if (finish[i]==0)
        {
            for (int j = 0; j < r; j++)
            {
                if (rem[i][j]>ava[j])
                {
                    flag=1;
                    break;
                }
                
            }
            if(flag==0){
                finish[i] = 1;
                safe[k]=i;
                k++;

                for (int j = 0; j < r; j++)
                {
                    ava[j] += alloc[i][j]; 
                }
                i=-1;
                
            }
            
        }
        
    }
    flag=0;
    for (int i = 0; i < p; i++)
    {
        if (finish[i] == 0)
        {
            cout<< "deadlock"<< endl;
            flag =1;
            break;
        }
        
    }

    if (flag==0)
    {
        cout<<"safe"<<endl;
        for (int i = 0; i < p; i++)
        {
            cout<< safe[i];
        }
        
    }
    
    
    
    
    

}
int main()
{
    int alloc [5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max [5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int p = 5, r= 3;
    int ava[3] = {3,3,2};
    bankers(alloc,max,p,r,ava);
    return 0;
}