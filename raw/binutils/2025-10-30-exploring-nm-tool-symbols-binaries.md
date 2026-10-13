# Exploring the nm Tool: Understanding Symbols in Binaries

> Source: https://can-ozkan.medium.com/exploring-the-nm-tool-understanding-symbols-in-binaries-1ae03193212a
> Collected: 2026-10-09
> Published: 2025-10-30

Author: Can Özkan (Medium). 14 min read. Oct 30, 2025.

## 1. Introduction

When working with compiled programs, it's often necessary to understand what's inside a binary, such as what functions it contains, what variables are defined, and how it interacts with other modules or libraries. The nm tool, part of the GNU Binutils package, serves this purpose. It allows you to inspect the symbol table of object files, static and shared libraries, and executables. In simpler terms, nm reveals the names of functions and variables known to the binary, along with their corresponding addresses and types.

Fundamentally, nm provides a window into the structure of compiled code, bridging the gap between source code and machine code. It lists symbols (such as functions, global variables, and external references). It categorizes them based on their location, e.g., in the text (code), data, or BSS (uninitialized data) sections.

Furthermore, the nm tool proves especially useful in reverse engineering, debugging, and binary analysis workflows. Reverse engineers use nm to identify function names, global variables, and external dependencies in ELF files. Debuggers rely on symbol information to trace program execution and identify which functions or data structures are causing errors.

Under the hood, nm works by reading the symbol table embedded within a compiled file. The symbol table is a special section in object files and executables that maps symbolic names (such as function or variable identifiers) to their corresponding memory addresses or offsets. This table is critical during the linking stage of compilation, where different object files are combined to form a complete executable.

In practice, nm has several common use cases. One of the most frequent is understanding function names in compiled code, for example when examining a compiled .o or .so file to see which functions it exports. Another is investigating linking errors: when a compiler or linker complains about "undefined references," nm can help pinpoint which symbols are missing and from which file they should originate. Finally, nm is also valuable when comparing stripped and unstripped binaries.

## 2. Understanding Symbols in Binaries

In programming, a symbol is a name that represents a function, variable, or data structure in a program. During compilation, these symbols are used as references to identify where things are located in memory or how they are connected across different modules. Essentially, symbols bridge the gap between human-readable code and machine-executable instructions.

The compiler stores this symbolic information inside the symbol table, a special data structure that exists within object files (.o), static libraries (.a), and executables (.out, .elf, etc.). The symbol table lists each symbol's name, its memory address (if known), and its type (e.g., function, variable, or external reference).

The symbol table plays a crucial role in both linking and debugging. During the linking phase, the linker combines multiple object files into a single executable. It uses the symbol tables from each object file to match undefined symbols (symbols referenced but not defined in that file) with defined symbols (symbols actually implemented in another file). For example, if one file references a function called hello() but does not define it, the linker looks for hello() in another object file's symbol table. If it finds a match, it resolves the reference by linking them together. If not, an "undefined reference" error occurs.

Symbols also assist in debugging by making compiled programs more readable to developers and tools. Debuggers like gdb rely on symbol tables to map binary instructions back to meaningful names.

There are two major ways to classify symbols: defined vs. undefined and global vs. local.

- Defined symbols represent entities that are actually implemented in the file. For example, if your source file defines a function int sum(int a, int b), that function will appear in the symbol table as a defined symbol.
- Undefined symbols, on the other hand, are references to entities defined elsewhere. For instance, if your file calls printf() but doesn't define it, printf will appear as an undefined symbol. The linker must later resolve it by connecting it to the actual printf function in the C standard library.

The second distinction concerns scope:

- Global symbols are visible across different object files and can be accessed or referenced by other modules. These include public functions and global variables.
- Local symbols are internal to a single object file and cannot be referenced externally. For example, functions declared as static in C are local symbols. They're confined to the file where they're defined and not exposed to other parts of the program.

Understanding how compilers and linkers generate and use symbol tables sheds light on how nm retrieves its information. When you compile a source file with gcc -c, the compiler translates the code into an object file, generating entries for every symbol it encounters, both defined and undefined. Each entry contains metadata, including its section (text, data, or BSS), binding (local or global), and value (address offset). During linking, the linker merges these symbol tables, resolves undefined symbols by matching them with defined ones, and produces a final symbol table for the executable.

## 3. Basic Usage of nm

Syntax:

```
nm [options] <object-file>
```

Example with a simple C program (compilation: gcc -c hello.c -O0 -o hello.o):

```c
#include <stdio.h>

void hello() {
    printf("Hello, world!\n");
}

int main() {
    int a = 35;
    hello();
    return 0;
}
```

Each line typically contains three columns:

1. Address (Value): The memory address or offset of the symbol within the file. For symbols that are not defined in the current file, this field is blank because the linker will resolve them later.
2. Type: A single character indicating the symbol type (for example, whether it's a function, variable, or undefined reference).
3. Name: The name of the symbol itself (usually the function or variable name).

In the example above, the first column shows addresses for hello and main but not for puts, since puts is not defined in this file. It comes from the standard C library. The second column shows T for both hello and main, meaning they are defined functions located in the text section (the part of the binary that holds executable code). The U next to puts indicates that it's an undefined symbol, a placeholder that the linker must later resolve by connecting it to the actual implementation in the C library.

You can also use nm directly on a fully linked executable to see how symbols are resolved:

```
gcc hello.c -o hello
nm hello
```

The output will include many more symbols, since it now contains not only your code but also references to the system libraries and startup routines that make your program executable.

## 4. Decoding Symbol Types

The symbol type, a single letter in the middle column, indicates the section of the binary in which the symbol resides or its role in the program's structure. The most common sections are the text, data, and BSS sections. The text section stores executable code (functions), the data section contains initialized global and static variables, and the BSS section holds uninitialized global or static variables. Symbols can also represent read-only data, weak symbols, or undefined external references.

Example (compilation: gcc -c symbols.c -o symbols.o):

```c
#include <stdio.h>

int global_var = 42;        // initialized global variable
static int counter;         // static variable (local to this file)

void display() {            // globally visible function
    printf("Value: %d\n", global_var);
}

static void helper() {      // local (static) function
    counter++;
}
```

Decoded line by line:

- global_var has a type D, meaning it's a defined, initialized global variable stored in the data section.
- counter is marked b, which means it's a local uninitialized variable (residing in the BSS section).
- display has a T, indicating it's a globally visible function located in the text section.
- helper has a t, showing it's a local (static) function.
- printf is marked U, meaning it's undefined in this file and must be resolved by linking against the standard C library.

The difference between uppercase and lowercase letters is important. Uppercase indicates global scope, while lowercase represents local scope. This distinction helps you understand which functions or variables are visible to other files during the linking process.

Another interesting case is weak symbols (W or w). These symbols allow multiple definitions of the same name, where one definition can override another. This is often used in libraries or when providing default implementations that can be replaced by user-defined ones. For instance, you might define a weak function in a library as a fallback, which the user can override by defining a stronger (non-weak) function of the same name.

## 5. Other Use Cases

By default, nm shows symbols from the static symbol table (.symtab) found in object files and non-stripped executables. However, dynamically linked executables and shared libraries (.so files) also contain a dynamic symbol table (.dynsym), which lists only the symbols needed at runtime for dynamic linking. To view these, you can use the -D option.

If you're working with C++ binaries, symbol names look strange and unreadable due to name mangling, a process by which the compiler encodes additional information (such as namespaces, classes, and argument types) into symbol names to support function overloading. For example, instead of seeing add(int, int), you might encounter _Z3addii. To make these symbols human-readable, you can use the -C flag, which demangles C++ symbol names:

```
nm -C main.o
```

This option tells nm to decode mangled names back into their original form, displaying add(int, int) instead of the encoded symbol.

nm also becomes more powerful when used alongside other tools like objdump and readelf. For example, while nm lists symbols and their types, objdump -d can disassemble the corresponding code sections. Similarly, readelf -s provides a more detailed breakdown of symbol table attributes (such as binding and visibility), complementing the concise output of nm.

Here's a simple workflow for deeper analysis:

1. Use nm to find function addresses in an executable: nm -n hello
2. Then use objdump to disassemble that address range: objdump -d hello | less
3. Cross-reference the function names from nm with the corresponding assembly instructions in objdump.

In addition, another use case of nm involves scripting and automation. Because its output is plain text, nm is easily integrated into shell scripts to perform automated checks or analyses. For example, you could write a script to list all undefined symbols in multiple object files, identify missing library dependencies, or detect whether sensitive functions (like system or execve) appear in a binary, which is useful for both build validation and security auditing.

## 6. Stripped vs. Unstripped Binaries

When a program is compiled, it typically contains a wealth of metadata, including the symbol table, debug information, and relocation entries. The process of removing this information is called stripping, and it has a significant impact on what tools like nm can reveal.

An unstripped binary retains all of its symbol information. This means that nm can display not only function names and variable identifiers but also addresses and sections where they reside.

A stripped binary, on the other hand, has most or all of its symbol information removed using the strip command. The resulting executable still works exactly the same way since the CPU doesn't need symbol names to run code — but it becomes smaller in size and significantly harder to analyze. Stripping is often performed before software distribution to reduce file size and to obscure the program's internal logic, making reverse engineering more difficult. For example:

```
gcc hello.c -o hello
nm hello | head
strip hello
nm hello | head
```

From a reverse engineering perspective, stripped binaries are far more difficult to analyze. Without symbol names, tools like nm or debuggers can no longer identify which functions perform specific tasks. Instead of meaningful identifiers like authenticate_user() or encrypt_data(), analysts are left with addresses such as 0x401050 or generic labels like FUN_401050.

From a developer's perspective, stripping serves both performance and security purposes. Removing symbol and debug information reduces the size of executables, which can be beneficial for embedded systems, firmware, or performance-critical environments where every byte counts. It also serves as a lightweight form of obfuscation, making it slightly more difficult for attackers to understand or tamper with the binary.

## 7. Practical Scenarios

### Debugging Linking Issues

One of the most common uses of nm is diagnosing linking errors during compilation. When the message undefined reference to `foo_function` appears, it means the compiler found a reference to foo_function() but couldn't locate its definition in any of the linked object files or libraries.

For example, with a.c calling foo() and b.c defining foo(), compiling only a.c gives an undefined reference error. Debugging with nm:

```
gcc -c a.c -o a.o
gcc -c b.c -o b.o
nm a.o
nm b.o
```

Here, U in a.o means foo() is undefined in that file, while T in b.o means foo() is defined there. This confirms that linking both files together should resolve the issue:

```
gcc a.o b.o -o test
```

### Reverse Engineering and ELF Analysis

When analyzing an ELF executable or shared library, you can use nm to list all function names, global variables, and undefined symbols, helping you reconstruct the program's logic. Entries like authenticate_user, process_input, and encrypt_password marked T immediately indicate the binary's purpose, while undefined symbols like printf show standard library reliance.

### Exploring Libraries and Shared Objects

Inspecting static (.a) and shared (.so) libraries shows which functions they export or require:

```
nm -D /usr/lib/x86_64-linux-gnu/libm.so.6 | grep cos
```

This tells you that the math library (libm.so) exports several cosine-related functions for different data types. You can verify symbol availability before attempting to compile.
