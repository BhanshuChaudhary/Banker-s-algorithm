# Banker-s-algorithm
C code for banker's algorithm

The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating
the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for
possible activities, before deciding whether allocation should be allowed to continue.

Safety Algorithm:-
1)Initialize: Work = Available
Finish[i] = false; for i=1, 2, 3, 4….n
2) Find an i such that both
a) Finish[i] = false
b) Needi <= Work
if no such i exists goto step (4)
3) Work = Work + Allocation[i]
Finish[i] = true
goto step (2)
4) if Finish [i] = true for all i
then the system is in a safe state
