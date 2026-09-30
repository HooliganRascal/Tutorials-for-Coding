# Memory Models and Namespaces
---
## Separate Compilation

- Recall [compiling and linking](Chapter_1.md)
    - `g++ *.cpp` compiles and links and produces `a.out` as output 
    - `g++ -c *.cpp` compiles only, leave a `*.o`
    - `g++ *.o` links and produces `a.out`
    - `g++ *.cpp -o *` is always recommended
- If we modify some files, just recompile the corrsponding ones and link them to the previously compiled `*.o`, and upgrade output

## Storage Duration, Scope and Linkage

## Namespaces

