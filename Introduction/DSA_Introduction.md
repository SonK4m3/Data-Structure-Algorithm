                                                    DATA STRUCTURE ALGORITHM Introduction   
I. What is an Algorithm?

    - In computer programming terms, an algorithm is a set of well-defined instructions to solve a particular problem. It
    takes a set of input and produces a desired output. For example,
    1. Take two number inputs
    2. Add numbers using the + operator
    3. Display the result

    - Qualities if Good Algorithms
        - Input and output should be defined precisely.
        - Each step in the algorithm should be clear and unambiguous.
        - Algorithm should be most effective among many different ways to solve a problem.
        - An algorithm shouldn't include computer code. Instead, the algorithm should be written in such a way that it can be used in different programming languages.

    - Algorithm 1: Add two numbers entered by user
        Step 1: Start
        Step 2: Declare variables num1, num2, and sum.
        Step 3: Read values num1 and num2.
        Step 4: Add num1 and num2 and assign the result to sum.
                sum<-num1+num2
        Step 5: Display sum.
        Step 6: Stop.

    - Algorithm 2: Find the largest number among three numbers.
        Step 1: Start
        Step 2: Declare variables a, b and c.
        Step 3: Read variables a, b and c.
        Step 4: If a > b
                    If a > c
                        Display a is the largest number.
                    Else
                        Display c is the largest number.
                Else
                    If b > c
                        Display b is the largest number.
                    Else
                        Display c is the largest number.
        Step 5: Stop

II. Data Structure and Types

    1. What is Data Structures?
        - Data structure is a storage that is used to store and organize data. It is a way of arranging data on a computer so that it can be accessed and updated efficiently.
        
        - Depending on your requirement and project, it is important to choose the right data structure for your project.
        
        - Note: Data structure and data types are slightly different. Data structure is the collection of data types arranged in a specific order.
    
    2. Types of Data Structure

        Basically, data structures are divided into two categories:
            - Linear data structure
            - Non-linear data structure

    3. Linear data structure 

        - In linear data structures, the elements are arranged in sequence once after other. Since elements are arranged in particular order, they are easy to implement.

        - However, when the complexity of the program increases, the linear data structures might not be the choice because of operational complexities.

        - Popular linear data structures:
            1. Array
            2. Stack
            3. Queue
            4. Linked list

     4. Non-linear data structures

        - Unlike linear data structures, elements in non-linear data structures are not in any sequence. Instead they are arranged in a hierarchical manner where one element will be connected to one or more elements.

        - Non-linear data structures are further divided into grah and tree based data structures.

        - Popular non-linear data structures:
        1. Graph data structures:
            - Spanning Tree and Minmum Spanning Tree
            - Strongly Connected Componets
            - Adjacency Matrix
            - Adjacency List
        2. Trees data structures:
            - Binary Tree
            - Binary Search Tree
            - AVL Tree
            - Red-Black Tree

        - Linear Vs Non-linear Data Structures

        Linear Data Structures                  Non-linear Data Structures   

    1.  The data items are arranged in          The data items are arranged in
        sequential order, one after             non_sequential order.
        the other.

    2.  All the items are present on            The data items are present at
        the single layer.                       different layers.

    3.  It can be traversed on a single         It requires multiple runs. That 
        run. That is, if we start from          is, if we start from the first 
        the first element, we can traverse      element in might not be possible
        all the elements sequential in a        to traverse all the elements in
        single pass.                            a single pass.

    4.  The memory utilizaion not               Different structures utilize 
        efficient.                              memory in different efficient
                                                ways depending on the need.

    5.  The time complexity increase            Time complexity remains the same.
        with the data size.


    III. Why learn Data Structures and Algorithm?

        - Software development involves learning new technologies on a daily basis. You get to learn most of these technologies while using them in one of your projects. However, it is not the case with algorithms.

        - If you don't know algorithms well, you won't be albe to identfy if you can optimize the code you are writing right now. You are expected to know them in advance and apply them wherever possible and critical.