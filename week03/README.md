## Lecture 1: Introduction

### Develop environment
National Colligiate Programming Contest (NCPC) and International Colligiate Programming Contest (ICPC) usually provide GNU/Linux.

### Terminal

+   Compile
    +   GNU Compiler Collection (`gcc` for C and `g++` for C++)
        +   `-o`: set output
            +   Without `-o`, the default output is `a.out`
        +   `-O2`: optimization
        +   `-std=c11`: use C11
        +   `-std=c++11`: use C++11
    +   Java: `javac` Main.java
+   Execution
    +   `./a.out`
    +   `java Main`
        +   `-Xmx=1024m`: set the maximum heap memory
        +   `-Xss=8m`: set the maximum stack memory
    +   `python main.py`
+   I/O redirection
    +   Input: `<`
    +   Output: `>`
    +   Error: `2>`
    +   Example: `./a.out < the.in > the.out 2> the.err`
+   Execution time measurenment
    +   Use `time`
    +   Example: `time ./a.out < the.in > the.out`
        +   Runs `a.out`
        +   Use `the.in` as the input
        +   `the.out` stores the output
        +   The terminal displays the error messages and execution time.

### I/O processing templates

+	[`eof_fgets.cpp`](eof_fgets.cpp) for line-based input terminated by End-Of-File
+	[`eof_scanf.cpp`](eof_scanf.cpp) for token-based input terminated by End-Of-File
+	[`token_on_a_line.cpp`](token_on_a_line.cpp) for variable numbers of tokens on a line

### String Tokenizer

+	C
+	Java
+	Python 3

### Online judge systems

+   [UVa](https://uva.onlinejudge.org/)
+   [CodeForces](http://codeforces.com/)
+   [NCTU OJ](https://oj.nctu.me/)
+   [PKU](http://poj.org/)
+   [AtCoder](http://atcoder.jp/)
+   [HDOJ](http://acm.hdu.edu.cn/)

### Judge responses

Sample problems:
[CodeForces 319 Div 2 A](http://codeforces.com/contest/577/problem/A), 
[CodeForces 340 Div 2 A](http://codeforces.com/problemset/problem/617/A), 
[CodeForces 340 Div 2 B](http://codeforces.com/problemset/problem/617/B). 

+   CE - Compilation Error

    CodeForces 340 Div 2 A: [`CE-cf340_div2_A.cpp`](CE-cf340_div2_A.cpp)
+   WA - Wrong Answer

    CodeForces 340 Div 2 A: [`WA-cf340_div2_A.cpp`](WA-cf340_div2_A.cpp)
+   RE - Rumtime Error

    CodeForces 319 Div 2 A: [`RE-cf319_div2_A.c`](RE-cf319_div2_A.c)
+   TLE - Time Limit Exceeded

    CodeForces 319 Div 2 A: [`TLE-cf319_div2_A.c`](TLE-cf319_div2_A.c)
    
    CodeForces 340 Div 2 B: [`TLE-cf340_div2_B.cpp`](TLE-cf340_div2_B.cpp)
+   MLE - Memory Limit Exceeded

    CodeForces 319 Div 2 A: [`MLE-cf319_div2_A.c`](MLE-cf319_div2_A.c)
+   AC - Accepted

    CodeForces 319 Div 2 A: [`AC-cf319_div2_A.c`](AC-cf319_div2_A.c)
    
    CodeForces 340 Div 2 A: [`AC-cf340_div2_A.cpp`](AC-cf340_div2_A.cpp)
    
    CodeForces 340 Div 2 B: [`AC-cf340_div2_B.cpp`](AC-cf340_div2_B.cpp)

## Two approches to solve a problem

You have already known the following two approaches.

+	Decrease and conquer
+	Divide and conquer

Let us see some examples.

+	Evaluate arithmetic expressions
+	Multiplications
+	Sorting
+	Binary search

## Computation Resources

In this course, we focus on the following two kinds of resources.

+	Time
+	Space

Let us see an example: prefix sums and their applications.

## Basic data structures and STL

+   [Slides](lec02.pdf)
+   [Reference](http://www.cplusplus.com/reference/)
+   Suppliments
    +   [Binary heaps](PSPT_lec02_complexity.pdf)
    +   [Josephus problem](PSPT_lec03_joseph.pdf)
    +   [C strings](PSPT_lec06_cstring.pdf)

### STL containers

The following containers are frequently used in programming contest.
+   [`pair`](http://www.cplusplus.com/reference/utility/pair/)
+   [`vector`](http://www.cplusplus.com/reference/vector/vector/)
    +   [`vector<bool>`](http://www.cplusplus.com/reference/vector/vector-bool/)
+   [`list`](http://www.cplusplus.com/reference/list/list/)
+   [`queue`](http://www.cplusplus.com/reference/queue/queue/)
+   [`stack`](http://www.cplusplus.com/reference/stack/stack/)
    +   In programming contest, `stack` is usually slower than `vector`.
+   [`priority_queue`](http://www.cplusplus.com/reference/queue/priority_queue/)
+   [`set`](http://www.cplusplus.com/reference/set/set)
    +   Example: [iterating over a `set`](set-iter.c++11.cpp) (C++11)
    +   [`unordered_set`](http://www.cplusplus.com/reference/unordered_set/unordered_set) (C++11)
+   [`map`](http://www.cplusplus.com/reference/map/map)
    +   Example: [iterating over a `map`](map-iter.c++11.cpp) (C++11)
    +   [`unordered_map`](http://www.cplusplus.com/reference/unordered_map/unordered_map) (C++11)

### STL algorithms

The following algorithms are frequently used in programming contest.
+   [`sort()`](http://www.cplusplus.com/reference/algorithm/sort/)
+   [`lower_bound()`](http://www.cplusplus.com/reference/algorithm/lower_bound/)
+   [`upper_bound()`](http://www.cplusplus.com/reference/algorithm/upper_bound/)
+   [`next_permutation()`](http://www.cplusplus.com/reference/algorithm/next_permutation/)
