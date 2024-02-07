# StackTrace Usage and Debugging Guide

This guide provides instructions on using the stack trace in a C++ program and utilizing the GNU Debugger (GDB) for debugging.

## Prerequisites

- C++ compiler (e.g., g++)
- GNU Debugger (GDB)

## Compilation

Ensure that your program is compiled with debugging information. Use the `-g` flag to include debug symbols:

```bash
g++ -g -o StackTrace StackTrace.cpp
```

## Debugging with GDB

1. Start GDB with your compiled executable:

   ```bash
   gdb ./StackTrace
   ```

2. Set a breakpoint at the `main` function:

   ```bash
   break main
   ```

3. Run the program:

   ```bash
   run
   ```

4. When GDB breaks at the `main` function, set a breakpoint where you want to examine the stack trace (e.g., before handling exceptions):

   ```bash
   break StackTrace.cpp:3
   ```

   This breakpoint is strategically placed at line 3 of `StackTrace.cpp`, corresponding to `funcC`, where an exception is thrown. It allows for a detailed examination of the program's state just before handling exceptions.

5. Continue the program execution:

   ```bash
   continue
   ```

6. GDB will stop at the specified breakpoint, allowing you to examine the stack trace:

   ```bash
   bt
   ```

   This will display the call stack, showing the functions called up to the point of the breakpoint. The breakpoint at `StackTrace.cpp:3` provides a closer inspection of the program's state just before handling exceptions, aiding in the identification and debugging of issues.

    ```bash
    Reading symbols from ./StackTrace...
    (gdb) break main
    Breakpoint 1 at 0x1316: file StackTrace.cpp, line 11.
    (gdb) run
    Starting program: /home/user/StackTrace_vs_CoreDump/StackTrace/StackTrace
    [Thread debugging using libthread_db enabled]
    Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

    Breakpoint 1, main () at StackTrace.cpp:11
    11          funcA();
    (gdb) break StackTrace.cpp:3
    Breakpoint 2 at 0x555555555294: file StackTrace.cpp, line 3.
    (gdb) continue
    Continuing.

    Breakpoint 2, funcC () at StackTrace.cpp:3
    3       void funcC() { throw std::runtime_error("Fehler in funcC"); }
    (gdb) bt
    #0  funcC () at StackTrace.cpp:3
    #1  0x00005555555552f6 in funcB () at StackTrace.cpp:5
    #2  0x0000555555555306 in funcA () at StackTrace.cpp:7
    #3  0x000055555555531b in main () at StackTrace.cpp:11
    ```