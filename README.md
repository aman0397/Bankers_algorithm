# Bankers_algorithm
This is a classical deadlock avoidance technique. It is primarily applicable to resource-allocation system with multiple instances of each resource type. 

Data Structures used :
Available: A vector of length m indicates teh number of available resources of each type. 
Max: An n*m matrix defines the maximum demand for each process.
Allocation: An n*m matrix defines number of resources of each type currently allocated to each process. 
Need: An n*m matrix indicates the remaining resource need of each process.

Algorithms used :
Safety Algorithm
To find if the given system is or isn't in a safe state.
Resource-Request Algorithm
To determine whether resources can be safely granted.
