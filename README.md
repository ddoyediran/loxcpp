# Creating a Programming language Interpreter using CPP


## How to Build & Run the project using CMake
```bash
# step 1: Create a 'build' sub-directory. Run the following command from the parent directory
/loxcpp % mkdir build

# step 2: Change to the 'build' sub-directory.
loxcpp/build % cd build

# step 3: Run CMake
loxcpp/build % cmake ..

# step 4: Build the project
loxcpp/build % make

# step 5: Run the executable directly without any file:
loxcpp/build % ./loxcpp

# step 6 (alternative to step 5): Run the executable directly with file or passing arguments:
loxcpp/build % ./loxcpp <file.lox> # e.g ./loxcpp script.lox
```
