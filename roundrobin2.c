#include <stdio.h>

typedef struct{
    int pid;
    int at;
    int bt;
    int rm;
    int tat;
    int cmp;
    int wt;
    int inQ;

} Process;

int front=-1, rear=-1;

void printTable(int n, Process proc[n]){
    int avgT=0, avgW=0;
    printf("Process ID:\tArrival Time:\tBurst Time:\tCompletion Time:\tTurn Around Time:\tWait Time:\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].cmp, proc[i].tat, proc[i].wt);
        avgT += proc[i].tat;
        avgW += proc[i].wt;
    }
    printf("Average Turn Around Time: %f\n", (float)avgT/n);
    printf("Average Waiting Time: %f\n", (float)avgW/n);
}

void sortProcess(int n, Process proc[n]){
    Process temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(proc[j].at > proc[j+1].at){
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

void enqueue(int n, Process q[1000], Process pr){
    if(front==-1) front=0;
    q[++rear] = pr;  
}

Process dequeue(int n, Process q[1000]){
    if(front==rear){
        int k = front;
        front=-1;
        rear=-1;
        return q[k];
    }
    else{
        return q[front++];
    }

}

void roundRobin(int n, Process proc[n], int quanta){
    int completed=0, time=proc[0].at;
    Process queue[1000];

    for(int i=0; i<n; i++) proc[i].inQ = 0;

    enqueue(n, queue, proc[0]);
    proc[0].inQ = 1;
    while(completed<n){
        //allocate cpu
        if(rear==-1 && front==-1){
            time++;
        }
        else{
            Process pr = dequeue(n, queue);
            int exeTime = pr.rm<quanta ? pr.rm: quanta;
            pr.rm -= exeTime;
            time += exeTime;

            //add to queue
            for(int i=0; i<n; i++){
                if(proc[i].at<=time && !proc[i].inQ){
                    proc[i].inQ = 1;
                    enqueue(n, queue, proc[i]);
                }
            }
            if(pr.rm <= 0){
                completed++;
                for (int i = 0; i < n; i++){
                    if(proc[i].pid==pr.pid){
                        proc[i].cmp = time;
                        proc[i].tat = time - proc[i].at;
                        proc[i].wt = proc[i].tat - proc[i].bt;
                        break;
                    }
                }
            }
            else{
                pr.inQ = 1;
                enqueue(n, queue, pr);
            }
        }
    }
}

int main(){
	int n, quanta;
	printf("Enter no. of process: ");
	scanf("%d", &n);
    Process proc[n];
	printf("Enter time quanta: ");
	scanf("%d", &quanta);

    printf("Enter (arrival time, burst time):\n");
    for(int i=0; i<n; i++){
        scanf("%d", &proc[i].at);
        scanf("%d", &proc[i].bt);
        proc[i].rm = proc[i].bt;
        proc[i].pid = i+1;
    }

    sortProcess(n, proc);
    roundRobin(n, proc, quanta);
    printTable(n, proc);
}

/*
0 5
1 6
2 3
6 4
3 1
4 5
*/
