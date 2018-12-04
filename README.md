# Bankers_algorithm
This is a classical deadlock avoidance technique. It is primarily applicable to resource-allocation system with multiple instances of each resource type. 

<b>Data Structures used :</b></br>
Available: A vector of length m indicates teh number of available resources of each type. </br>
Max: An n x m matrix defines the maximum demand for each process.</br>
Allocation: An n x m matrix defines number of resources of each type currently allocated to each process. </br>
Need: An n x m matrix indicates the remaining resource need of each process.</br>

<b>Algorithms used :</b></br>
Safety Algorithm:</br>
To find if the given system is or isn't in a safe state.</br>
Resource-Request Algorithm:</br>
To determine whether resources can be safely granted.</br>
