Stack is a linear datastrcutre which allow insertion/deletion only from one side.
Main functions of Stack : -- >

push() : insert element at top of stack.
pop() : remove elemetn from top of stack.
top() / peek() : returns top element of stack.
empty() : checks wheather stack is empty or not.



NOTE: If brute force method of an array based question is O(n^2) and inner loop 
is deppendent on outter loop then STACK can help in reduction of time complexity.



/*
 *
 * Parent/Pattern Questions
 *
 */


1. Next Greatest Element : 
This pattern is solved usign monotonic stack i.e strictly increasing/decreasing stack.

*Straight forward questions --> 
Next Greater to Left
Next Greater to Right
Next Smaller to Left
Next Smaller to Right

*Pattern based question -->
Stock Span Problem
Maximum Area of Histogram
Maximum size of binary matrix containing 1 


2. Parentheses based problem : 
This question mainly consist of two complementry elements lik ( and ), 
or object moving in x axis and some condition are for colliosions.

* Straign parenthese bases question only consist of '()'
Valid Parentheses
Length of longest valid substring 


3. Reversign property
Stackk return the inserted data in reversed manner.
This prety comes handy in reversing data of other data-strcutre like queue.

4. Desiging problems 
There are some beautiful Design problem based on stack like K-Stacks and Max-Freq stack.
