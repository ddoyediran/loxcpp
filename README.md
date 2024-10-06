# Creating a Programming language Interpreter using CPP
The objective of this project is to build a C++ Interpreter from Scratch: Applying concepts from [Crafting Interpreters book](https://www.amazon.com/Crafting-Interpreters-Robert-Nystrom/dp/0990582930) to create a custom language interpreter in C++. This project focuses on developing skills in:
- Lexical analysis and parsing (using regular expressions or hand-written lexers)
- Bytecode generation and execution (defining and interpreting instructions)
- Memory management (potentially implementing garbage collection for automatic memory management)
- Building a virtual machine to execute the bytecode efficiently


### How to Build & Run the project using CMake for the first time
```bash
# Step 1: Create a 'build' sub-directory. Run the following command from the parent directory
/loxcpp % mkdir build

# Step 2: Change to the 'build' sub-directory.
loxcpp/build % cd build

# Step 3: Run CMake
loxcpp/build % cmake ..

# Step 4: Build the project
loxcpp/build % make

# Step 5: Run the executable directly without any file:
loxcpp/build % ./loxcpp

# Step 6 (alternative to step 5): Run the executable directly with file or passing arguments:
loxcpp/build % ./loxcpp <file.lox> # e.g ./loxcpp script.lox
```

### How to Build & Run the project using CMake after the initial build if changes were made
```bash
# Step 1: Change to the 'build' sub-directory.
loxcpp/build % cd build

# Step 2: Build the project
loxcpp/build % make

# Step 3: Run the executable directly without any file:
loxcpp/build % ./loxcpp # type the code in the cmd line prompt.

# Step 4 (alternative to step 3): Run the executable directly with file or passing arguments:
loxcpp/build % ./loxcpp <file.lox> # e.g ./loxcpp script.lox
```
