# OS Lab

Small C exercises exploring processes, `fork()`, IPC, CPU scheduling, page
replacement, and file I/O.

## Experiment checklist

All 13 experiments in the supplied list are covered. Existing programs are kept
in their original folders; the missing experiments are added below.

| No. | Question (simple wording) | Source |
| --- | --- | --- |
| 1 | Create a child process using fork(). | [Fork demo](July31/fork_parent_child_messages.c) |
| 2 | Parent adds odd numbers; child adds even numbers from 1 to n. | [Odd/even sums](November12/parent_odd_child_even_sum.c) |
| 3 | Make the parent wait until the child finishes. | [Wait demo](July31/child_print_numbers_parent_wait.c) |
| 4 | Show orphan and zombie processes. | [Orphan](July31/orphan_process_demo.c), [Zombie](July31/zombie_process_demo.c) |
| 5 | Send data between processes using a pipe. | [Pipe demo](September25/child_write_even_numbers_pipe_wait_status.c) |
| 6 | Send a message using a FIFO (named pipe). | [Writer](November12/fifo_writer.c), [Reader](November12/fifo_reader.c) |
| 7 | Send and receive a message using a message queue. | [Sender](November12/message_queue_sender.c), [Receiver](November12/message_queue_receiver.c) |
| 8 | Write and read a message using shared memory. | [Writer](November12/shared_memory_writer.c), [Reader](November12/shared_memory_reader.c) |
| 9 | Run processes in first come, first served order. | [FCFS](November13/fcfs_scheduling.c) |
| 10 | Run the shortest available job first. | [SJF](November13/sjf_scheduling.c) |
| 11 | Run the available process with the highest priority first. | [Priority](November13/priority_scheduling.c) |
| 12 | Replace the oldest loaded page when frames are full. | [FIFO pages](November13/fifo_page_replacement.c) |
| 13 | Replace the page that has not been used for the longest time. | [LRU pages](November13/lru_page_replacement.c) |

## Running the new programs

Use Linux or Ubuntu in WSL with GCC. The process and IPC programs need Linux
system calls and cannot be run directly with a Windows-only C compiler.
Compile each source separately, for example from the project folder:

```sh
gcc -std=c11 -Wall -Wextra November12/parent_odd_child_even_sum.c -o /tmp/odd_even
/tmp/odd_even
gcc -std=c11 -Wall -Wextra November13/fcfs_scheduling.c -o /tmp/fcfs
/tmp/fcfs
```

For each IPC pair, compile both files separately in the same way:

- FIFO: start the writer, enter a message, then run the reader in another
  terminal from the same directory. The writer waits for the reader. The reader
  removes `os_lab_fifo` after reading it.
- Message queue: run the sender first, then the receiver. The receiver removes
  the queue after reading the message.
- Shared memory: run the writer first and let it finish, then run the reader.
  The reader removes the shared memory after reading it.

Run one pair at a time. The message queue uses key 1234 and shared memory uses
key 5678; use these examples where those keys are free. If a run is interrupted,
`ipcs` lists remaining IPC objects; remove only this example's queue or memory
with `ipcrm -Q 1234` or `ipcrm -M 5678`. Remove a leftover FIFO with
`rm os_lab_fifo` from the directory where the writer ran.

Scheduling programs accept up to 20 processes. Arrival and burst times are
whole numbers up to 100000; burst time must be positive. SJF and priority are
non-preemptive: a running process finishes before another starts. Smaller
priority numbers mean higher priority. Ties follow input order.

Page replacement programs accept up to 100 nonnegative page numbers and up to
20 frames. They print the frames after each reference and count hits and faults.

## Programs

### July 31
- [Child prints numbers; parent waits](July31/child_print_numbers_parent_wait.c)
- [Child Fibonacci; parent factorial](July31/child_fibonacci_parent_factorial.c)
- [Create three child processes](July31/create_three_child_processes.c)
- [Fork: parent and child messages](July31/fork_parent_child_messages.c)
- [Orphan process demonstration](July31/orphan_process_demo.c)
- [Parent and child PIDs/PPIDs](July31/parent_child_pid_ppid.c)
- [Parent prints evens; child prints odds](July31/parent_even_child_odd.c)
- [Parent reads child exit status](July31/parent_reads_child_exit_status.c)
- [Parent sum, child Fibonacci, grandchild factorial](July31/parent_sum_child_fibonacci_grandchild_factorial.c)
- [Zombie process demonstration](July31/zombie_process_demo.c)

### August 7
- [Child Fibonacci; parent Armstrong numbers](August7/child_fibonacci_parent_armstrong_numbers.c)
- [Child checks prime; parent calculates factorial](August7/child_prime_parent_factorial.c)

### August 17
- [Child sums an array and checks whether the sum is prime](August17/child_sum_array_check_prime.c)
- [Array sum and prime-check variant](August17/child_sum_array_check_prime_variant.c)

### September 18
- [Parent writes a file; child reads it](September18/parent_write_child_read_file.c)
- [Parent sums an array; child checks primality via pipe](September18/parent_sum_array_child_check_prime_pipe.c)

### September 25
- [Child sends even numbers to parent through a pipe](September25/child_write_even_numbers_pipe.c)
- [Pipe example with child exit-status checking](September25/child_write_even_numbers_pipe_wait_status.c)
- [Zombie process placeholder (empty)](September25/zombie_process_demo.c)

## AI assistance

Copilot was used to structure this README.
