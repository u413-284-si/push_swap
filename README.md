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

## Implementation

### Stacks

The stacks are implemented as integer arrays. The first element of the array arr[0] represents the bottom of the stack. A top variable tracks the top of the stack and indicates where the next element is to be inserted. Initially the provided values are saved into the stack in the following order: The first argument is at the top of the stack (= arr[top]) and the last argument at the bottom (= arr[0]). Both stack a and b have the same size as the number of numerical elements.

### Sorting algorithm

A mixture of different sorting algorithms are implemented.

**For up to n = 5** numerical values a simple sorting algorithm is called. 

---

If **5 < n <= 64** insertion sort is applied. The values are split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part. Stack b represents the sorted part, stack a the unsorted. The top both values of stack a are compared and the smaller one swapped to the top. Before pushing this value x over to stack b the correct position in b is identified and presented by rotating the directly inferior value y (y < x) in b to the top.  When all but one value (the max of all values) are pushed to b, it is rotated to a descending order so that its max value is on top. Finally all values are pushed back to a.

| Time complexity:	| Average	| Best	| Worst	|
| :---			| :---		| :---	| :---	|
| 			| O(n²)		| O(n)	| O(n²)	|

Space: const. <br />
Stability: stable

---

For **n > 64** a recursive version of quicksort is applied. It creates two empty arrays to hold elements less than the pivot value and elements greater than the pivot value, and then recursively applies itself on the created two sub arrays. As time complexity is not taken into account for this program the median value of each array is calculated and chosen as the pivot. This increases the effectivity of quick sort.

Stack b represents the part with values smaller than the pivot. Stack a contains values equal or greater than the pivot. All values in stack a are compared to the pivot and sorted accordingly into stack a or b. As this requires the array to be rotated (only pushing of top element possible), the rotation eventually needs to be reversed to the initial sequence minus the pushed values. Then the algorithm is recursively calling itself on both stacks while providing the number of values present in each stack in its call. This number depends on the previous total n being odd or even.

**Even:** <br />
	Stack a contains (n + 1) / 2 + 1 values <br />
	Stack b contains (n + 1) / 2 - 1 values <br />
**Odd:** <br />
	Stack a contains (n + 1) / 2 values <br />
	Stakc b contains (n + 1) / 2 - 1 values <br />

The recursive loop is broken when the stacks reach a total n of 3 or less. In this case a sorting algorithm respective to each stack is executed. Finally all values are sorted in descending order in stack b and are pushed back to a.

| Time complexity:	| Average	| Best		| Worst	|
| :---			| :---		| :---		| :---	|
| 			| O(n*log(n))	| O(n*log(n))	| O(n²)	|

Space: const. <br />
Stability: unstable

### Checker

Additionally a checker program is implemented to verify the correctness of the output of the main program. It receives the numerical values as arguments and then reads in the operations of push_swap or manually entered via stdin (keyboard). If the operations lead to a sorted order of the given values, it displays 'OK'. Otherwise 'KO'. 

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

or

./checker <random numbers>
<input to stdin> <ENTER>
<end read from stdin with CTRL+D>
```

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
```
