Stack is a linear datastrcutre which allow insertion/deletion only from one side.
Main functions of Stack : -- >

push() : insert element at top of stack.
pop() : remove elemetn from top of stack.
top() / peek() : returns top element of stack.
empty() : checks wheather stack is empty or not.



NOTE: If brute force method of an array based question is O(n^2) and inner loop 
is deppendent on outter loop the STACK can help in reduction of time complexity.



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


