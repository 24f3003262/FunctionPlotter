# FunctionPlotter
Coding a function plotter to evaluate and display ANY math function in pure C. Involves graphical user interface (GUI) programming, math expression parsing, and 2D geometric transformations to scale and transform the function into a user-specified grid.

# How to Use
1. Download: Grab the latest plot.exe from the [Releases] section.

2. Run: Double-click the .exe.

3. Input: - Enter your X and Y axis boundaries (e.g., -10 to 10).

4. Enter the step size (lower values like 0.01 mean higher precision).

5. Type your math expression (e.g., sin(x)*x + 2).

6. Interact: The SDL2 window will launch and display your plot!



## Errors found and how i handled

#### Error if I directly use int main() after adding the SDL header.... 
Windows exclusive error that occurs because Windows insists it must have standard arguments...fixed by making it main(int argc, char* argv[]) and then adding the lines (void)argc;
    (void)argv; and also compiling it as gcc -Wall -Wextra -g plot.c -o plot.exe -lmingw32
 -lSDL2main -lSDL2 -mconsole
- Later made a Makefile which helps me not to write the whole line for compilation again and again

- Conclusion : Windows and linux have different rules when handling external libraries sometimes

#### Was getting error that it couldn't find the source of tinyexpr.h

Basically for a multifile project you have to compile the files together


## What I learned

- Differences in how Windows and linux handles C
- use of MSYS to install external C library
- use of SDL2 to create GUI
- How to compile a multifile project
- tinyexpr for parsing and evaluating expressions
- creating a MakeFile for C 
- Static Linking so that a user can directly use the .exe file without needing dependencies