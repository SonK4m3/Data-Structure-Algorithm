                        Master Theory

    The master method is a formula for solving recurrence relations of the form: 
        T(n) = aT(n/b) + f(n),
        where,
        n = size of input
        a = number of subproblems in the recursion
        n/b = size of each subproblem. All subproblems are assumed 
            to have the same size.
        f(n) = cost of the work done outside the recursive call, 
            which includes the cost of dividing the problem and
            cost of merging the solutions

        Here, a ≥ 1 and b > 1 are constants, and f(n) is an asymptotically positive function.

    Master Theorem
        - If a >= 1 and b > 1 are constants and f(n) is an asymptotically positive function, then the time complexity of a recursive relation is given by:
            T(n) = aT(n/b) + f(n)

            where, T(n) has the following asymptotic bounds:

                1. If f(n) = O(n^(logb a-ϵ)), then T(n) = Θ(n^(logb a)).

                2. If f(n) = Θ(n^(logb a)), then T(n) = Θ(n^logb a * log n).

                3. If f(n) = Ω(n^(logb a+ϵ)), then T(n) = Θ(f(n)).

            ϵ > 0 is a constant.