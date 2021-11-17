                        Divide and Conquer Algorithm
    - A divide and conquer algorithm is a strategy of solving a large problem by:
        1. breaking the problem into smaller sub-problems
        2. solving the sub-problems, and
        3. combining them to get the desired output.
    
    - To use the divide and conquer algorithm, recursion is used.

    - How Divide and Conquer Algorithms Work?

        1. Divide: Divide the given problem into sub-problems using         recursion.
        2. Conquer: Solve the smaller sub-problems recursively. If the subproblems is small enough, then solve it directly.
        3. Combine: Combine the solutions of the sub-problems that are part of the recursive process to solve the actual problem.
    
    Time Complexity 
        For a merge sort, the equation can be writen as:
        T(n) = aT(n/b) + f(n)
            = 2T(n/2) + O(n)
        Where, 
        a = 2 (each time, a problem is divided into 2 subproblems)
        n/b = n/2 (size of each sub problem is half of the input)
        f(n) = time taken to divide the problem and merging the subproblems
        T(n/2) = O(n log n) (To understand this, please refer to the master theorem.)

        Now, T(n) = 2T(n log n) + O(n)
                ≈ O(n log n)
        
    Divide and Conquer Vs Dynamic approach

        - The divide and conquer approach divides a problem into smaller subproblems; these subproblems are further solved recursively. The result of each subproblem is not stored for future reference, whereas, in a dynamic approach, the result of each subproblem is stored for future reference.

        - Use the divide and conquer approach when the same subproblem is not solved multiple times. Use the dynamic approach when the result of a subproblem is to be used multiple times in the future.

        For example:
            Divide and Conquer approach:

            fib(n)
                If n < 2, return 1
                Else , return f(n - 1) + f(n -2)

            Dynamic approach:

            mem = []
            fib(n)
                If n in mem: return mem[n] 
                else,     
                    If n < 2, f = 1
                    else , f = f(n - 1) + f(n -2)
                    mem[n] = f
                    return f

    Divide and Conquer Applications:
        1. Binary Search
        2. Merge Sort
        3. Quick Sort
        4. Strassen's Matrix multiplication
        5. Karatsuba Algorithm
