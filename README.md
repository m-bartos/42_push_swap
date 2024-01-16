# 42_push_swap

The goal of this project is to sort numbers in ascending order within a stack using only 11 predefined operations and one more stack.

## Result visualization - sorting 100 random numbers
![push_swap](https://github.com/m-bartos/42_push_swap/assets/28412526/8b6993d4-8360-4bbd-854e-c648afdd5616)

## How to use
The program is easy to use. 
* First, you need to make: `Make`
* Run program with command: `./push_swap [random numbers]` example: `./push_swap 4 -19 1 23 50 -1`
* Output is set of instructions (see below)
* If you want to check how many instructions were displayed, use pipe and `wc -l` command:
`./push_swap 4 -19 1 23 50 -1 | wc -l`


## Requirements for the sorting algorithm
You have 2 stacks named a and b. At the beginning:
* The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
* The stack b is empty.
* The goal is to sort in ascending order numbers into stack a. 

To do so you have the following operations at your disposal:
* sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* ss: sa and sb at the same time.
* pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
* rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
* rr: ra and rb at the same time.
* rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
* rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
* rrr: rra and rrb at the same time.

## Used algorithm
After researching a suitable algorithm for my push_swap, I decided to use the **'Turk algorithm'** described by **A. Yigit Ogun in his** [article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) on medium.com. This algorithm is straightforward to comprehend, nice to implement in C code and it guarantees maximum points in the evaluation.

## Results - number of operations
* Sorting stack with 100 random numbers - MIN = 496, MAX = 610 (average 540 - 570)
* Sorting stack with 500 random numbers - MIN = 4833, MAX = 5377 (average 4900 - 5200)

## Error check
Several input errors are checked before the comparison algorithm is performed:
* Verification that all arguments are numbers (digits and '+', '-' sign)
* Verification that all arguments are integers (in between MIN_INT and MAX_INT values)
* Identification and handling of duplicate numbers

## Thanks and credits:
* **A. Yigit Ogun** for his [article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) about 'Turk algorithm'
* **elijahkash** for his push_swap visualizer - [push_swap_gui](https://github.com/elijahkash/push_swap_gui)
