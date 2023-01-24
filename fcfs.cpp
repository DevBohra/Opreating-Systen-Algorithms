#include <iostream>
using namespace std;
#define m 30
void fcfs(int pro[], int at[],int bt[], int n){
    int temp[m];
    temp[0] = 0;
    int wt[5],tat[5];
    int awt = 0, atat = 0, ct;
    cout << "process" << "Arrival time" << "Brust time" << "turm around time" << "wait time" << "completion time"<< endl;

    for (int i = 0; i <n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] -at[i];
        if(wt[i]<0){
            wt[i] = 0;
        }
        tat[i] = wt[i]+bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        ct = tat[i]+at[i];
        
        cout << " " << i+1 << "\t\t" << at[i] << "\t\t"
             << bt[i] << "\t\t" << tat[i] << "\t\t "
             << wt[i]  <<  "\t\t " << ct << endl;

    }
    cout << "avg tat = " << (float)atat/(float)n << endl;
    cout << "avg wt = " << (float)awt/(float)n << endl;
    

}
int main()
{
    int pro[] = {1,2,3,4};
    int At[] = {0,1,5,6};
    int Bt[] = {2,2,3,4};
    int n = sizeof(pro)/ sizeof(pro[0]);
    fcfs(pro,At,Bt,n);
    return 0;
}


// // C++ program for implementation of FCFS
// // scheduling with different arrival time
// #include<iostream>
// using namespace std;

// // Function to find the waiting time for all
// // processes
// void findWaitingTime(int processes[], int n, int bt[],
// 								int wt[], int at[])
// {
// 	int service_time[n];
// 	service_time[0] = at[0];
// 	wt[0] = 0;

// 	// calculating waiting time
// 	for (int i = 1; i < n ; i++)
// 	{
// 		// Add burst time of previous processes
// 		service_time[i] = service_time[i-1] + bt[i-1];

// 		// Find waiting time for current process =
// 		// sum - at[i]
// 		wt[i] = service_time[i] - at[i];

// 		// If waiting time for a process is in negative
// 		// that means it is already in the ready queue
// 		// before CPU becomes idle so its waiting time is 0
// 		if (wt[i] < 0)
// 			wt[i] = 0;
// 	}
// }

// // Function to calculate turn around time
// void findTurnAroundTime(int processes[], int n, int bt[],
// 									int wt[], int tat[])
// {
// 	// Calculating turnaround time by adding bt[i] + wt[i]
// 	for (int i = 0; i < n ; i++)
// 		tat[i] = bt[i] + wt[i];
// }

// // Function to calculate average waiting and turn-around
// // times.
// void findavgTime(int processes[], int n, int bt[], int at[])
// {
// 	int wt[n], tat[n];

// 	// Function to find waiting time of all processes
// 	findWaitingTime(processes, n, bt, wt, at);

// 	// Function to find turn around time for all processes
// 	findTurnAroundTime(processes, n, bt, wt, tat);

// 	// Display processes along with all details
// 	cout << "Processes " << " Burst Time " << " Arrival Time "
// 		<< " Waiting Time " << " Turn-Around Time "
// 		<< " Completion Time \n";
// 	int total_wt = 0, total_tat = 0;
// 	for (int i = 0 ; i < n ; i++)
// 	{
// 		total_wt = total_wt + wt[i];
// 		total_tat = total_tat + tat[i];
// 		int compl_time = tat[i] + at[i];
// 		cout << " " << i+1 << "\t\t" << bt[i] << "\t\t"
// 			<< at[i] << "\t\t" << wt[i] << "\t\t "
// 			<< tat[i] << "\t\t " << compl_time << endl;
// 	}

// 	cout << "Average waiting time = "
// 		<< (float)total_wt / (float)n;
// 	cout << "\nAverage turn around time = "
// 		<< (float)total_tat / (float)n;
// }

// // Driver code
// int main()
// {
// 	// Process id's
// 	int processes[] = {1, 2, 3,4};
// 	int n = sizeof processes / sizeof processes[0];

// 	// Burst time of all processes
// 	int burst_time[] = {2,2,3,4};

// 	// Arrival time of all processes
// 	int arrival_time[] = {0,1,5,6};

// 	findavgTime(processes, n, burst_time, arrival_time);

// 	return 0;
// }
