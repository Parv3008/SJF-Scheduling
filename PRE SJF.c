//Write a C/C++ program to calculate AWT, ATT & ART for CPU Scheduling with pre-emptive Shortest Job First (SJF) Scheduling Algorithm.

#include <stdio.h>

struct Process {
    int pid; // Process ID
    int burst_time; // Burst time (execution time)
    int arrival_time; // Arrival time
    int remaining_time; // Remaining burst time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
    int response_time; // Response time
};

// Function to perform Preemptive Shortest Job First (SJF) scheduling
void SJF_Preemptive(struct Process processes[], int n) {
    int completed = 0; // Number of completed processes
    int current_time = 0; // Current time
    int shortest_process = -1; // Index of the process with the shortest burst time

    while (completed < n) {
        // Find the process with the shortest burst time among the arrived processes
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if (shortest_process == -1 || processes[i].remaining_time < processes[shortest_process].remaining_time) {
                    shortest_process = i;
                }
            }
        }

        // If no process is found, move the current time to the next process arrival time
        if (shortest_process == -1) {
            int min_arrival_time = processes[0].arrival_time;
            for (int i = 1; i < n; i++) {
                if (processes[i].arrival_time < min_arrival_time && processes[i].remaining_time > 0) {
                    min_arrival_time = processes[i].arrival_time;
                }
            }
            current_time = min_arrival_time;
            continue;
        }

        // Execute the process for 1 time unit
        processes[shortest_process].remaining_time--;
        current_time++;

        // If the process is completed, update the waiting time and turnaround time
        if (processes[shortest_process].remaining_time == 0) {
            completed++;
            processes[shortest_process].waiting_time = current_time - processes[shortest_process].burst_time - processes[shortest_process].arrival_time;
            processes[shortest_process].turnaround_time = current_time - processes[shortest_process].arrival_time;
            processes[shortest_process].response_time = processes[shortest_process].waiting_time;
            shortest_process = -1;
        }
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
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = 0;
    }

    SJF_Preemptive(processes, n);

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

