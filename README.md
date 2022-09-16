# Simultaneously-Threads
 Create three threads as A, B and C, and run them simultaneously.

- Thread A has three code blocks: A1, A2, A3
- Thread B has four code blocks: B1, B2, B3, B4
- Thread C has three code blocks: C1, C2, C3

passes to the function its own name
and code block number – A1, A2, A3, B1, etc. as a parameter to indicate which code block
is running as of that moment. Therefore, as can be seen from above, a code block for each
thread consists of writing the corresponding block tag five times in a row. (A1A1A1A1A1
etc.). Code blocks are executed sequentially in threads (block A2 does not start until the
block A1 ends, etc.). When you run your application without any synchronization control,
you can see that the code blocks of different threads are interleaved, like;
A1A1C1B1A1B1B1.....A3C2C3......
