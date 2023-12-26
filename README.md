# Multilevel Queue Scheduling Program

This program implements a multilevel queue scheduling algorithm with three priority-based queues. Each queue utilizes a different scheduling algorithm to efficiently manage processes with varying priorities. The key features and algorithm flow are outlined below:

## Key Features:
- **Multilevel Queue Scheduling:** Processes are categorized into three queues based on their priority levels.
- **Hybrid Scheduling Within Queues:**
  1. **Queue 1 (Round Robin with Time Quantum 4):** Processes with higher priority (1-5) are scheduled using the Round Robin algorithm with a time quantum of 4 units.
  2. **Queue 2 (Priority Scheduling - non-preemptive):** Processes with medium priority (6-10) are scheduled based on their priority levels using the Priority Scheduling algorithm.
  3. **Queue 3 (First Come First Serve):** Processes with lower priority (11-15) are scheduled using the First Come First Serve (FCFS) algorithm.
- **Inter-Queue Scheduling:** Round Robin (time quantum = 10) is employed to allocate CPU time between the queues themselves.

## Algorithm Flow:
1. **Process Input:** Users input details for each process, including arrival time, burst time, and priority.
2. **Queue Assignment:** Processes are assigned to queues based on their priority levels.
3. **Main Scheduling Loop:**
    - Round Robin cycles between queues with a fixed time quantum of 10 units.
    - Within each queue, the respective scheduling algorithm is applied.
4. **Calculations and Output:**
    - Waiting time and turnaround time are computed for each process and queue.
    - Detailed results, including execution patterns and averages, are displayed for each queue and the overall process execution.

## Usage:
1. Execute the program.
2. Input the number of processes, arrival time, burst time, and priority for each process.
3. View the detailed output showcasing the execution pattern of each queue and relevant process information.

This program provides a comprehensive understanding of the multilevel queue scheduling algorithm, its hybrid scheduling strategies, and the overall execution flow.

