# Philosophers

The Dining Philosophers Problem is a classic synchronization problem proposed by Edsger W. Dijkstra in 1965. It illustrates the challenges of allocating shared resources without causing deadlocks in a system. This repository contains an implementation of the Dining Philosophers Problem written in C.

## Problem Statement

Five philosophers sit at a table and spend their lives thinking, sleeping and eating. Between each philosopher is a single fork. In order to eat, a philosopher must use two forks. The objective is to design a protocol that allows the philosophers to eat without starving themselves or each other.

![Dining Philosophers](img/Dining_Philosophers.png)

## Implementation

This implementation uses POSIX threads (pthreads) for creating threads representing each philosopher and simulates their actions. It also uses mutexes to handle the synchronization problem related to the usage of forks.

### Features

- Utilizes pthreads for simulating philosophers' actions.
- Employs mutex locks to prevent deadlocks and ensure mutual exclusion when philosophers pick up or put down forks.
- Includes a mechanism to prevent starvation.

### Prerequisites

To run this program, you will need:

- GCC
- POSIX threads library (should be available on most Unix-like operating systems)
- Make

### Compilation & Usage

To compile and run the program, you can use the following command:

```bash
cd philo
make && ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]
```
