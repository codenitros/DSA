// Same as Shortest_Path.cpp

Process:
1. Get the topological sort of given graph using dfs and store in stack
2. start popping from stack
3. initialize distance array with infinity
4. for each poppped node check if there is a lower distance 
    then update in distance array
5. when you are done with your stack your distance array will have the answer