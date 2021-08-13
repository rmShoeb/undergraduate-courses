//Shortest Job First

#include <iostream>
#include <cstdio>
#include <queue>
#include "Process.h"
using namespace std;


int main(void)
{
    int NumberOfProcesses;
    queue<int> ReadyQueue;
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

    //scheduling process
    iter = 0;
    cpuTime = UserProcesses[0].getArrivalTime();
    while(iter<NumberOfProcesses)
    {
        int WhichIndex;

        for(temp=0; temp<NumberOfProcesses; temp++)
        {
            //if the arrival time is greater than cpu time
            //that means the process has not arrived yet
            if(UserProcesses[temp].getArrivalTime() <= cpuTime)
            {
                //if the process has not executed yet
                //push it in the queue
                if(!isProcessExecuted[temp])
                    ReadyQueue.push(temp);
            }
            else
                break;
        }

        if(ReadyQueue.size() == 0) continue;    //can't go further if there is no process in the queue
        else if(ReadyQueue.size() == 1)
        {
            WhichIndex = ReadyQueue.front();
            ReadyQueue.pop();
        }
        else
        //find the process with lowest burst time
        {
            WhichIndex = ReadyQueue.front();
            ReadyQueue.pop();
            while(!ReadyQueue.empty())
            {
                if(UserProcesses[ReadyQueue.front()].getBurstTime() < UserProcesses[WhichIndex].getBurstTime())
                    WhichIndex = ReadyQueue.front();
                ReadyQueue.pop();
            }
        }

        if(UserProcesses[WhichIndex].getArrivalTime() > cpuTime)
            cpuTime = UserProcesses[WhichIndex].getArrivalTime();
        UserProcesses[WhichIndex].setCompletionTime(cpuTime);
        cpuTime += UserProcesses[WhichIndex].getBurstTime();
        isProcessExecuted[WhichIndex] = true;

        iter++;
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
