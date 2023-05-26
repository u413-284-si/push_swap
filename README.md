# push_swap
This project is an implementation of a sorting algorithm which sorts numbers provided in a random sequence into an ascending order by applying a limited set of operations. These operations allow the modification of two stacks which contain the numbers. The goal of the project is to identify and familiarise oneself with various sorting algorithms, choosing the most adept approach to sort the numbers in the most efficient manner. 

## Project Overview

The integer values are initially read into stack 'a'. Their range spans positive as well as negative numbers, but there are a number of limitations:

* no non-numerical values
* no duplicates
* no values out of the boundaries of an integer

If one of these limitations is not fullfilled, the program aborts and displays an error message.

A second stack 'b' serves as a temporary buffer to store and manipulate selected values. A predefined set of operations is allowed to transfer values between the stacks and manipulate their position within each respective stack. Per definition of stacks only the top values of a stack can be removed from it and new additions to a stack land on the top - according to the "LIFO = Last in first out" principle.

<pre>
<b>sa</b> (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

<b>sb</b> (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

<b>ss</b> : sa and sb at the same time.

<b>pa</b> (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

<b>pb</b> (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

<b>ra</b> (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

<b>rb</b> (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

<b>rr</b> : ra and rb at the same time.

<b>rra</b> (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

<b>rrb</b> (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

<b>rrr</b> : rra and rrb at the same time.
</pre>

The goal is to sort the numbers in ascending order into stack 'a'. The operations required to achieve this goal are displayed unto the terminal. A minimal amount of required operations is aspired to - this being a KPI for the efficiency of the implemented algorithm.

## Installation
```
git clone git@github.com:u413-284-si/push_swap.git
cd push_swap
make
./push_swap <random numbers>
```

For bonus program (while within the push_swap directory):

```
make bonus
./checker <random numbers>
<input to stdin> <ENTER>
<end read from stdin with CTRL+D>
```
