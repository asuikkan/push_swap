# Push_swap

The goal of this project is to sort a stack of numbers in ascending order using another stack and a set of operations to manipulate the stacks. Performance is measured by the number of operations the program push_swap outputs as a solution to sort the stack.

## Rules

There are two stacks: A and B. The program execution is considered successful if the set of numbers given to the program is sorted in stack A and stack B is empty.

At the start, all numbers are in stack A in the order they are received, from top to bottom, with no duplicate numbers. Stack B is empty. For example:

If the numbers given to the program are `3 2 1 0`, the starting position will be:

![push_swap_stacks.png](https://i.ibb.co/h7kyPZB/push-swap-stacks.png)

### Operations

Only the following operations are allowed to sort the numbers:

- **sa: swap A** - swap the first two numbers at the top of stack A. Do nothing if there are less than two numbers.
- **sb: swap B** - swap the first two numbers at the top of stack B. Do nothing if there are less than two numbers.
- **ss: swap both** - sa and sb at the same time.
- **pa: push A** - take the first number at the top of B and put it at the top of A. Do nothing if B is empty.
- **pb: push B** - take the first number at the top of A and put it at the top of B. Do nothing if A is empty.
- **ra: rotate A** - shift up all numbers of stack A by one position. The top number becomes the bottom one.
- **rb: rotate B** - shift up all numbers of stack B by one position. The top number becomes the bottom one.
- **rr: rotate both** - ra and rb at the same time.
- **rra: reverse rotate A** - shift down all numbers of stack A by one position. The bottom number becomes the top one.
- **rrb: reverse rotate B** - shift down all numbers of stack B by one position. The bottom number becomes the top one.
- **rrr: reverse rotate both** - rra and rrb at the same time.

## Programs

You are required to create two programs in this project: **push_swap** and **checker**.

### push_swap

The program **push_swap** takes numbers as command line arguments and prints a set of operations that sort the numbers to stack A leaving stack B empty. Duplicate numbers are not allowed. Example:

![push_swap_example.png](https://i.ibb.co/gznBS3X/push-swap-example.png)

Visualization of sorting a hundred numbers with this program:

![push_swap_visualization.gif]<img src ="https://i.ibb.co/zXdHMxG/push-swap-visualization.gif">

Left side is stack A and right side is stack B. Visualizer by https://github.com/o-reo/push_swap_visualizer

### checker

The program **checker** also takes numbers as command line arguments with no duplicates and starts reading operations from the standard input. Unknown operations cause an error. After the operations are read, it will perform these operations on the stacks and check if the numbers are sorted as stated by the rules. It will then print “OK” if the sorting is successful and “KO” if it is not.

![checker_ko.png](https://i.ibb.co/r0KHr4B/checker-ko.png)

![checker_ok.png](https://i.ibb.co/d70YCxr/checker-ok.png)

The intended way to use these programs is to pipe the output of **push_swap** to **checker**:

![push_swap_checker_pipe.png](https://i.ibb.co/Z2YwQSm/push-swap-checker-pipe.png)

## Performance

As stated in the opening paragraph, the performance is measured by the number of operations that **push_swap** outputs. The lower the number, the better the performance. This number is always lower than what is required from the program, meaning that the performance is excellent, even though the solution is not always optimal.

## How to run

Create both executables with

```bash
make
```

Run **push_swap**

```bash
./push_swap <set_of_numbers>
```

Run checker

```bash
./checker [OPTIONS] <set_of_numbers>
```

and write operations as input. End input reading with `Ctrl+D` . **Checker** has an option `-r` to print the state of the stacks after each operation.

There is also a very basic number generator included in the repository, but it is advisable to use a better tool to create sets of random numbers for the programs.
