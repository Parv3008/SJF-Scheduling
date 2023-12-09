# SJF-Scheduling

Algorithm of non pre-emptive SJF:-
1.	Start the program.
2.	Input the number of processes (n).
3.	For each process (i = 1 to n): a. Input the arrival time of the process. b. Input the burst time of the process. c. Set the waiting time, turnaround time, and response time to 0.
4.	Sort the processes based on their burst times in ascending order (if not already sorted).
5.	Initialize current_time to 0 (the current time in the CPU).
6.	For each process (i = 1 to n): a. Calculate the waiting time for the process:<br>
•	waiting_time[i] = current_time - arrival_time[i]<br>
•	If the waiting time is negative, set it to 0 (process has not arrived yet). b. Calculate the turnaround time for the process:<br>
•	turnaround_time[i] = burst_time[i] + waiting_time[i] c. Calculate the response time for the process:<br>
•	response_time[i] = waiting_time[i] (for non-preemptive SJF, response time is the same as waiting time). d. Increment the current_time by the burst time of the current process.<br>
7.	Calculate the total_waiting_time, total_turnaround_time, and total_response_time as the sum of the respective times of all processes.
8.	Calculate the average_waiting_time, average_turnaround_time, and average_response_time:<br>
•	average_waiting_time = total_waiting_time / n<br>
•	average_turnaround_time = total_turnaround_time / n<br>
•	average_response_time = total_response_time / n<br>
9.	Print the results:<br>
•	Average Waiting Time: average_waiting_time<br>
•	Average Turnaround Time: average_turnaround_time<br>
•	Average Response Time: average_response_time
10.	End the program.


<br><br><br>
Algorithm of pre-emptive SJF:-
1.	Start the program.
2.	Input the number of processes (n).
3.	For each process (i = 1 to n): a. Input the arrival time of the process. b. Input the burst time of the process. c. Set the remaining time, waiting time, turnaround time, and response time to 0.
4.	Initialize current_time to 0 (the current time in the CPU).
5.	Initialize completed to 0 (the number of completed processes).
6.	Repeat until completed = n: a. Find the process with the shortest remaining time among the arrived processes at current_time. b. If no process is found, move the current_time to the next process arrival time. c. Execute the process for 1 time unit. d. If the process is completed: i. Set waiting_time = current_time - arrival_time - burst_time (waiting time is time spent in the ready queue before starting execution). ii. Set turnaround_time = waiting_time + burst_time (turnaround time includes waiting time and burst time). iii. Set response_time = waiting_time (for preemptive SJF, response time is the same as waiting time). iv. Increment completed by 1.
7.	Calculate the total_waiting_time, total_turnaround_time, and total_response_time as the sum of the respective times of all processes.
8.	Calculate the average_waiting_time, average_turnaround_time, and average_response_time <br>
•	average_waiting_time = total_waiting_time / n<br>
•	average_turnaround_time = total_turnaround_time / n<br>
•	average_response_time = total_response_time / n<br>
9.	Print the results:<br>
•	Average Waiting Time: average_waiting_time<br>
•	Average Turnaround Time: average_turnaround_time<br>
•	Average Response Time: average_response_time<br>
10.	End the program.


