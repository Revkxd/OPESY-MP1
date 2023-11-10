#pragma once

#define ARR_MAX 512

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int start_time[ARR_MAX];
    int end_time[ARR_MAX];
} Process;

typedef struct {
    Process **processes;
    int size;
    float ave_wait_time;
} ProcessList;

ProcessList* createProcessList(int num_process);
Process* createProcess(int pid, int arrival_time, int burst_time);
void freeProcessList(ProcessList *pl);
void printProcessList(ProcessList *pl);
void appendStartTime(Process *p, int start);
void appendEndTime(Process *p, int end);
int getCompletion(Process *p);
Process* findMinBurst(Process **table, int size);
void appendProcess(Process **table, int pos, Process *p);
void removeProcess(Process **table, int size, Process *p);