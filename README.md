# Operating_system
Operating system simulation programs

## Disk Scheduling

```
Enter the Maximum disk size
199
Enter no. of locations
8
Enter HEAD location
53
Enter locations
98
Enter locations
183
Enter locations
37
Enter locations
122
Enter locations
14
Enter locations
124
Enter locations
65
Enter locations
67
53	98	183	37	122	14	124	65	67	



---- FCFS Algorithm ----
Head moved from   53 to   98 location.
Head moved from   98 to  183 location.
Head moved from  183 to   37 location.
Head moved from   37 to  122 location.
Head moved from  122 to   14 location.
Head moved from   14 to  124 location.
Head moved from  124 to   65 location.
Head moved from   65 to   67 location.
Total seek time :640
Average seek time :80




---- SSTF Algorithm ----
Head moved from   53 to   65 location.
Head moved from   65 to   67 location.
Head moved from   67 to   37 location.
Head moved from   37 to   14 location.
Head moved from   14 to   98 location.
Head moved from   98 to  122 location.
Head moved from  122 to  124 location.
Head moved from  124 to  183 location.
Total seek time :236
Average seek time :29.5




---- SCAN Algorithm ----
Head moved from   53 to   65 location.
Head moved from   65 to   67 location.
Head moved from   67 to   98 location.
Head moved from   98 to  122 location.
Head moved from  122 to  124 location.
Head moved from  124 to  183 location.
Head moved from  183 to  199 location.
Head moved from  199 to   37 location.
Head moved from   37 to   14 location.
Head moved from   14 to    0 location.
Total seek time :345
Average seek time :43.125




---- CSCAN Algorithm ----
Head moved from   53 to   65 location.
Head moved from   65 to   67 location.
Head moved from   67 to   98 location.
Head moved from   98 to  122 location.
Head moved from  122 to  124 location.
Head moved from  124 to  183 location.
Head moved from  183 to  199 location.
Head moved from  199 to    0 location.
Head moved from    0 to   14 location.
Head moved from   14 to   37 location.
Total seek time :382
Average seek time :47.75




---- LOOK Algorithm ----
Head moved from   53 to   65 location.
Head moved from   65 to   67 location.
Head moved from   67 to   98 location.
Head moved from   98 to  122 location.
Head moved from  122 to  124 location.
Head moved from  124 to  183 location.
Head moved from  183 to   37 location.
Head moved from   37 to   14 location.
Total seek time :299
Average seek time :37.375




---- CLOOK Algorithm ----
Head moved from   53 to   65 location.
Head moved from   65 to   67 location.
Head moved from   67 to   98 location.
Head moved from   98 to  122 location.
Head moved from  122 to  124 location.
Head moved from  124 to  183 location.
Head moved from  183 to   14 location.
Head moved from   14 to   37 location.
Total seek time :322
Average seek time :40.25


Process finished.
```

## CPU Scheduling 

```
CPU scheduling simulation
Enter no. of process
4

Enter Priority(lower number -> higher priority) :5
Arrival time :0
Burst time :7

Enter Priority(lower number -> higher priority) :2
Arrival time :2
Burst time :4

Enter Priority(lower number -> higher priority) :1
Arrival time :4
Burst time :1

Enter Priority(lower number -> higher priority) :8
Arrival time :5
Burst time :4



------------------- FCFS Algorithm ------------------
Gantt chart (by PID):
 1 2 3 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |   7  |   5  |   9  |
|  3  |     1    |   4  |   1  |  11  |   7  |   8  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 7.50 | 4.75 | 8.75 |
-----------------------------------------------------



-------------------- SJF Algorithm ------------------
Gantt chart (by PID):
 1 3 2 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |   8  |   6  |  10  |
|  3  |     1    |   4  |   1  |   7  |   3  |   4  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 6.75 | 4.00 | 8.00 |
-----------------------------------------------------



------------------- SRTF Algorithm ------------------
Gantt chart (by PID):
 1 1 2 2 3 2 2 4 4 4 4 1 1 1 1 1
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   9  |  16  |
|  2  |     2    |   2  |   4  |   2  |   1  |   5  |
|  3  |     1    |   4  |   1  |   4  |   0  |   1  |
|  4  |     8    |   5  |   4  |   7  |   2  |   6  |
-----------------------------------------------------
|                  Average =   | 3.25 | 3.00 | 7.00 |
-----------------------------------------------------



--------- Priority (non-primtive) Algorithm ---------
Gantt chart (by PID):
 1 4 3 2
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |  12  |  10  |  14  |
|  3  |     1    |   4  |   1  |  11  |   7  |   8  |
|  4  |     8    |   5  |   4  |   7  |   2  |   6  |
-----------------------------------------------------
|                  Average =   | 7.50 | 4.75 | 8.75 |
-----------------------------------------------------



----------- Priority (primtive) Algorithm -----------
Gantt chart (by PID):
 1 1 2 2 3 2 2 1 1 1 1 1 4 4 4 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   5  |  12  |
|  2  |     2    |   2  |   4  |   2  |   1  |   5  |
|  3  |     1    |   4  |   1  |   4  |   0  |   1  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 4.50 | 3.25 | 7.25 |
-----------------------------------------------------



--------------- Round Robin Algorithm ---------------
Time interval :3
Gantt chart (by PID):
 1 1 1 2 2 2 3 4 4 4 1 1 1 2 4 1
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   9  |  16  |
|  2  |     2    |   2  |   4  |   3  |   8  |  12  |
|  3  |     1    |   4  |   1  |   6  |   2  |   3  |
|  4  |     8    |   5  |   4  |   7  |   6  |  10  |
-----------------------------------------------------
|                  Average =   | 4.00 | 6.25 | 10.25 |
-----------------------------------------------------



--------------- Round Robin Algorithm ---------------
Time interval :10
Gantt chart (by PID):
 1 1 1 1 1 1 1 2 2 2 2 3 4 4 4 4
-----------------------------------------------------
| PID | Priority |  A_t |  B_t |  R_T |  W_T |  TAT |
-----------------------------------------------------
|  1  |     5    |   0  |   7  |   0  |   0  |   7  |
|  2  |     2    |   2  |   4  |   7  |   5  |   9  |
|  3  |     1    |   4  |   1  |  11  |   7  |   8  |
|  4  |     8    |   5  |   4  |  12  |   7  |  11  |
-----------------------------------------------------
|                  Average =   | 7.50 | 4.75 | 8.75 |
-----------------------------------------------------

Process finished.

```

## Page Replacement

```
Page Replacement Simulation

Enter page size :3

Enter no. of pages :12

Enter pageframe (integer) :1

Enter pageframe (integer) :2

Enter pageframe (integer) :3

Enter pageframe (integer) :4

Enter pageframe (integer) :1

Enter pageframe (integer) :2

Enter pageframe (integer) :5

Enter pageframe (integer) :1

Enter pageframe (integer) :2

Enter pageframe (integer) :3

Enter pageframe (integer) :4

Enter pageframe (integer) :5
 1 2 3 4 1 2 5 1 2 3 4 5


-------- FIFO --------
 1
 1 2
 1 2 3
 2 3 4
 3 4 1
 4 1 2
 1 2 5
 1 2 5
 1 2 5
 2 5 3
 5 3 4
 5 3 4
No. of page faults :9


-------- LRU --------
 1
 1 2
 1 2 3
 2 3 4
 3 4 1
 4 1 2
 1 2 5
 2 5 1
 5 1 2
 1 2 3
 2 3 4
 3 4 5
No. of page faults :10


-------- OPTIMAL --------
 1
 1 2
 1 2 3
 2 3 4
 3 4 1
 3 4 2
 3 4 5
 4 5 1
 4 5 2
 4 5 3
 4 5 3
 4 5 3
No. of page faults :10


Process finished.
```
