# push_swap project

This consists 2 main parts, namely checker and push_swap. The goal is to receive an input of unsorted numbers in a stack and sort them automatically in ascending order as efficiently as possible using only one extra stack with certain rules.

# rules

The following rules may be used as a means of input after running checker with input, or a means of reading the output after running push_swap with input:

**sa**  - swaps the top 2 values of stack A

**sb**  - swaps the top 2 values of stack B

**ss**  - swaps the top 2 values of both stack A & stack B

**ra**  - moves the top value of stack A to the bottom

**rb**  - moves the top value of stack B to the bottom

**rr**  - moves the top value of stack A & stack B to the bottom

**rra** - moves the bottom value of stack A to the top

**rrb** - moves the bottom value of stack B to the top

**rrr** - moves the bottom value of both stack A & stack B to the top

**pa**  - moves the top value of stack B on the top of stack A

**pa**  - moves the top value of stack A on the top of stack B

Any input other than these will result in an ``Error``.

# running the project

By typing ``make re`` in the terminal with all files, programs named ``checker`` and ``push_swap`` are created.

When running either checker or push_swap it should take in numeric arguments for sorting, for example:

``$> ./push_swap 7 2 1 5 4 3 6``
``$> ./checker 7 2 1 5 4 3 6``

The following restrictions apply (an ``Error`` is returned otherwise):

1. No arguments may extend beyond the integer range of -2147483648 to 2147483647.
2. No arguments may consist of duplicate numbers.
3. No arguments may contain alphabet characters, foreign characters or symbols. This includes `+` symbols at the start of positive integers, decimal floating points, exponential symbols, and padding/trailing 0s. Flags are the only _exception to this rule_.
4. No arguments may be in the form of a string, except when it is exactly 1 argument which is strictly numeric and separated by spaces.

# checker

After running checker with valid input (Example: ``$> ./checker 7 2 1 5 4 3 6``), you can manually sort out the list to ascending order using any of the commands listed in the rules, one at a time.

1. the program will return ``OK`` if the list is sorted at the end.
2. the program will return ``KO`` if the list is unsorted at the end.
3. the program will return ``Error`` whenever there is an invalid input.

# push_swap

After running push_swap with valid input (Example: ``$> ./push_swap 7 2 1 5 4 3 6``), you can watch as the program automatically returns a list of commands listed in the rules in a step-wise fashion which will automatically sort the list.

push_swap and checker may also be run with each other, for example: 

``$> ARG="7 2 1 5 4 3 6"; ./push_swap $ARG | ./checker $ARG``

This will return the list of commands as well as a final statement whether the number list ended up being sorted ( ``OK`` ), unsorted ( ``KO`` ), or an error has occured ( ``Error`` ).

push_swap may also be run with the ``wc -l`` command + flag, which would indicate how many commands it took to sort the input list, for example:

``$> ARG="7 2 1 5 4 3 6"; ./push_swap $ARG | wc -l``

# using randomized lists

So maybe you'd like to test how push_swap works with 500 random values, but don't have the time to type it out? Just use one of the following codes and edit the corresponding value in the bracket to test to your liking:

List of commands sorting 3 values:

``$> ARG=`ruby "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG``

Number of commands to sort 3 values:

``$> ARG=`ruby "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l``

List of commands sorting 5 values:

``$> ARG=`ruby "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG``

Number of commands to sort 5 values:

``$> ARG=`ruby "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l``

List of commands sorting 100 values:

``$> ARG=`ruby "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG``

Number of commands to sort 100 values:

``$> ARG=`ruby "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l``

List of commands sorting 500 values:

``$> ARG=`ruby "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG``

Number of commands to sort 500 values:

``$> ARG=`ruby "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l``

You can always run ``$> echo $ARG`` after running any of the commands listed here to find out what the actual input values were

# flags

The push_swap and checker program accepts 3 flags:

**v** - (v)isualiser; this returns a visual output of both stacks A & B as each command is getting fed to it. Each number is listed in the format ``number(rank)``, where ``number`` is the actual number input and ``rank`` is the ranking of each number starting from 1, lowest to highest.

**c** - (c)olour; this returns the output in colour yellow. Works best with the visualiser flag.

**r** - (r)un; this returns the output with a 1 second delay so you can see what is happening step by step. Ideal use for push_swap program.

Notes on running the optional flags:

1. Flags must be the first argument.
2. Flags must start with the ``-`` symbol.
3. Flags must contain any mix of ``v``, ``c``, and/or ``r`` in any order following the ``-`` symbol without spaces.
4. No duplicate characters may be present in flags (for example ``-vvv``).
5. An error will be returned otherwise.
