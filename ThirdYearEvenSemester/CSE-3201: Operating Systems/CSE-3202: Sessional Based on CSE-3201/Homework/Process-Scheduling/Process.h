#ifndef PROCESS_H
#define PROCESS_H
class Process
{
    public:
        void    setPID(int PID)                 {this->PID = PID;}
        int     getPID(void)                    {return this->PID;}

        void    setArrivalTime(int ArrivalTime) {this->ArrivalTime = ArrivalTime;}
        int     getArrivalTime(void)            {return this->ArrivalTime;}

        void    setBurstTime(int BurstTime)     {this->BurstTime = BurstTime;}
        int     getBurstTime(void)              {return this->BurstTime;}

        void    setTurnAroundTime(void)         {this->TurnAroundTime = this->CompletionTime - this->ArrivalTime;}
        int     getTurnAroundTime(void)         {return this->TurnAroundTime;}

        void    setCompletionTime(int cpuTime)
        {
            this->CompletionTime = cpuTime+this->BurstTime;
            this->setTurnAroundTime();
            this->setWaitingTime(cpuTime);
        }
        int     getCompletionTime(void)         {return this->CompletionTime;}

        void    setWaitingTime(int cpuTime)     {this->WaitingTime = cpuTime - this->ArrivalTime;}
        int     getWaitingTime(void)            {return this->WaitingTime;}
    
    private:
        int PID;
        int ArrivalTime;
        int BurstTime;
        int WaitingTime;
        int TurnAroundTime;
        int CompletionTime;
};
#endif