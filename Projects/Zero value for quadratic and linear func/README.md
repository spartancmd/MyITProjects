# Calculation of Zero Values

This program calculates the zero values (roots) where the graph of a function intersects the horizontal x-axis. The program provides a menu where you can choose the type of function to work with. The available options are:

- **Linear Function:** \( y = mx + b \)
- **Quadratic Function:** \( y = x^2 + px + q \)

## Usage

**Running the Program:**
   - Compile and run the program. Upon starting, you’ll be presented with a menu to choose between a linear or quadratic function or to exit.
   - Use the up/down arrow keys to navigate through the options and press `Enter` to confirm your selection.
   
**Function Input:**
   - For linear functions, enter values for `m` and `b`.
   - For quadratic functions, enter values for `p` and `q`.
   - When entering decimal values, use a period (`.`) as the decimal separator.

**Important Notes:**
   - **Testing Mode**: The `#define DEBUG` macro at the beginning of the code enables test cases for the calculation functions. If you only want to use the program without running tests, remove or comment out this line.
   - **Input Validity**: Only numerical input is supported. What happens when using non-numerical characters at the input, is undefined behavior.
