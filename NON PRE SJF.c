//Write a C/C++ program to calculate AWT, ATT & ART for CPU Scheduling with Non-pre-emptive Shortest Job First (SJF) Scheduling Algorithm.

#include <stdio.h>

struct Process {
    int pid; // Process ID
    int burst_time; // Burst time (execution time)
    int arrival_time; // Arrival time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
    int response_time; // Response time
};

// Function to perform Non-preemptive Shortest Job First (SJF) scheduling
void SJF_NonPreemptive(struct Process processes[], int n) {
    // Sort the processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        // Finding the process with the shortest burst time
        int shortest_process = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].burst_time < processes[shortest_process].burst_time) {
                shortest_process = j;
            }
        }

        // Swap the shortest process with the current process
        struct Process temp = processes[i];
        processes[i] = processes[shortest_process];
        processes[shortest_process] = temp;

        // Calculate the waiting time for the current process
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
            current_time = processes[i].arrival_time;
        }

        // Calculate the turnaround time and response time
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].response_time = processes[i].waiting_time;

        // Update the current time
        current_time += processes[i].burst_time;
    }
}

// Function to calculate and print the average times
void calculateAndPrintAverageTimes(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0, total_response_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    float avg_response_time = (float)total_response_time / n;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);

        processes[i].pid = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = 0;
    }

    SJF_NonPreemptive(processes, n);

    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\t Response Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }

    printf("\n");
    calculateAndPrintAverageTimes(processes, n);

    return 0;
}
