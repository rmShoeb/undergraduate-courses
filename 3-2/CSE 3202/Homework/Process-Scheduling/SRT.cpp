//Sortest Reamining Time First

#include <iostream>
#include "ProcessSRT.h"
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
    int NumberOfProcessesCompleted = 0;
    while(true)
    {
        //checking if all the processes have executed or not
        //if so, break the loop
        if(NumberOfProcesses == NumberOfProcessesCompleted)
            break;
        
        //temporarily choosing a process which has not been executed yet
        for(iter=0; iter<NumberOfProcesses; iter++)
        {
            if(!isProcessExecuted[iter])
                break;
        }
        // cout << "process: " << iter+1 << endl;
        
        //in case the arrival time is greater than the cpu time
        //need to adjust that
        //used this shortcut minimize loop cycles
        if(UserProcesses[iter].getArrivalTime() > cpuTime)
            cpuTime = UserProcesses[iter].getArrivalTime();
        // cout << "cpu time: " << cpuTime << endl;
        
        for(int i=iter+1; i<NumberOfProcesses; i++)//previous processes have been completed
        {
            // if((UserProcesses[i].getArrivalTime() == UserProcesses[iter].getArrivalTime()) && (!isProcessExecuted[i]))
            if((UserProcesses[i].getArrivalTime() <= cpuTime) && (!isProcessExecuted[i]))
            {
                if(UserProcesses[i].getBurstTime() < UserProcesses[iter].getBurstTime())
                {
                    UserProcesses[iter].Waiting();
                    iter = i;
                }
            }
        }
        // cout << "process: " << iter+1 << endl;

        //one cycle has been completed
        //time to increase cpu cycle
        //and decrease remaining time i.e. burst time
        cpuTime++;
        UserProcesses[iter].setBurstTime(UserProcesses[iter].getBurstTime()-1);

        //if the burst time (which I am using as remaining time) becomes zero
        //that means the process is completed
        //time to make changes so that it doesn't stay in the queue
        if(UserProcesses[iter].getBurstTime() == 0)
        {
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
