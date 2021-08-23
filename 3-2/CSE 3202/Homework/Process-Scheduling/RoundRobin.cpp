//Round Robin
//incomplete

#include <iostream>
#include <queue>
#include "ProcessSRT.h"
using namespace std;


int main(void)
{
    int NumberOfProcesses;
    int NumberOfProcessesCompleted;
    int SliceTime;
    queue<int>ReadyQueue;
    int iter;
    int cpuTime;
    int temp;

    cout << "Enter the number of processes: ";
    cin >> NumberOfProcesses;

    Process UserProcesses[NumberOfProcesses];
    bool isProcessExecuted[NumberOfProcesses] = {false};

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

    cout << "Enter slice time: ";
    cin >> SliceTime;

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

    //sheduling processes
    cpuTime = UserProcesses[0].getArrivalTime();
    ReadyQueue.push(0);
    NumberOfProcessesCompleted = 0;
    while(true)
    {
        //checking if all the processes have executed or not
        //if so, break the loop
        if(NumberOfProcesses == NumberOfProcessesCompleted)
            break;
        
        iter = ReadyQueue.front();
        if(UserProcesses[iter].getBurstTime() <= SliceTime)
        {
            ReadyQueue.pop();
            cpuTime += UserProcesses[iter].getBurstTime();
            UserProcesses[iter].setBurstTime(0);
            UserProcesses[iter].setCompletionTime(cpuTime);
            NumberOfProcessesCompleted++;
            isProcessExecuted[iter] = true;
        }
    }

    //printing the result
    printf("Process ID | Completion Time | Turn Around Time | Waiting Time\n");
    for(iter=0; iter<NumberOfProcesses; iter++)
    {
        printf("%-10d | %-15d | %-16d | %d\n",
                UserProcesses[iter].getPID(),
                UserProcesses[iter].getCompletionTime(),
                UserProcesses[iter].getTurnAroundTime(),
                UserProcesses[iter].getWaitingTime());
    }


    return 0;
}
