# push_swap
This project sorts integers on a stack - which are provided in a random order - into an ascending order by applying a limited set of operations. The goal of the project is to identify and familiarise oneself with various sorting algorithms, choosing the most adept approach to sort the stack in the most efficient manner.

## Project Overview

The integer values are provided in a first stack 'a'. Their range spans positive as well as negative numbers, but there cannot be duplicates. A second stack 'b' serves as temporary buffer to store and manipulate selected values. A set of operations are allowed to transfer values between the stacks and manipulate their position within each respective stack.

```
**sa** (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

**sb** (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

**ss** : sa and sb at the same time.

**pa** (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

**pb** (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

**ra** (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

**rb** (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

**rr** : ra and rb at the same time.

**rra** (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

**rrb** (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

**rrr** : rra and rrb at the same time.
```

The goal is to sort in ascending order the numbers into stack 'a'. The minimum required operations to achieve this goal are displayed unto the terminal.

## Installation
