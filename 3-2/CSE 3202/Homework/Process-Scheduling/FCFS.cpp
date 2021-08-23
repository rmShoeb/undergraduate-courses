//First Come First Serve

#include <iostream>
#include "Process.h"
using namespace std;


int main(void)
{
    int NumberOfProcesses;
    int iter;
    int cpuTime;
    int temp;

    cout << "Enter the number of processes: ";
    cin >> NumberOfProcesses;
    Process UserProcesses[NumberOfProcesses];

    for(iter=0; iter<NumberOfProcesses; iter++)
    {
        cout << "Enter process ID: ";
        cin >> temp;
        UserProcesses[iter].setPID(temp);

        cout << "Enter Arrival Time: ";
        cin >> temp;
        UserProcesses[iter].setArrivalTime(temp);

        cout << "Enter Burst Time: ";
        cin >> temp;
        UserProcesses[iter].setBurstTime(temp);

        cout << endl;
    }

    //sorting the processes according to their arrival time
    for(int i=0; i<NumberOfProcesses; i++)
    {
        for(int j=i+1; j<NumberOfProcesses; j++)
        {
            if(UserProcesses[j].getArrivalTime() < UserProcesses[i].getArrivalTime())
            {
                //interchange PID
                temp = UserProcesses[j].getPID();
                UserProcesses[j].setPID(UserProcesses[i].getPID());
                UserProcesses[i].setPID(temp);

                //interchange arrival time
                temp = UserProcesses[j].getArrivalTime();
                UserProcesses[j].setArrivalTime(UserProcesses[i].getArrivalTime());
                UserProcesses[i].setArrivalTime(temp);

                //interchange burst time
                temp = UserProcesses[j].getBurstTime();
                UserProcesses[j].setBurstTime(UserProcesses[i].getBurstTime());
                UserProcesses[i].setBurstTime(temp);
            }
        }
    }

    cpuTime = UserProcesses[0].getArrivalTime();
    printf("Process ID | Completion Time | Turn Around Time | Waiting Time\n");
    for(iter=0; iter<NumberOfProcesses; iter++)
    {
        if(UserProcesses[iter].getArrivalTime() > cpuTime)
            cpuTime = UserProcesses[iter].getArrivalTime();
        UserProcesses[iter].setCompletionTime(cpuTime);
        cpuTime += UserProcesses[iter].getBurstTime();
        printf("%-10d | %-15d | %-16d | %d\n",
                UserProcesses[iter].getPID(),
                UserProcesses[iter].getCompletionTime(),
                UserProcesses[iter].getTurnAroundTime(),
                UserProcesses[iter].getWaitingTime());
    }


    return 0;
}
