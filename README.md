# Command-Line Calculator (C++)
This is a simple command-line calculator written in C++. It supports basic arithmetic operations and additional functions like exponentiation and square root. The calculator also keeps a history of calculations which is session-based history (History resets when the program closes).

## Features
### Basic Arithmetic Operations
- Addition
- Subtraction
- Multiplication
- Division (with division-by-zero protection)

### Advanced Operations
- Exponentiation
- sqrt Square Root

### History Feature (Non-Persistent)
- Tracks calculations only while the program is running

### Error Handling
- Prevents invalid input (e.g., non-numeric values).
- Prevents division by zero.
- Prevents square root of negative numbers.

### Improved User Experience

- Operators are clearly listed before entering inputs.
- The program follows a logical input flow to avoid confusion.

---

## Installation and Setup

### **1. Install MinGW (GCC Compiler)**
If you don’t have a C++ compiler, install MinGW-w64:

1. Download MinGW-w64 from: [https://www.mingw-w64.org/downloads/](https://www.mingw-w64.org/downloads/)
2. Install it and select:
   - **Architecture:** x86_64 (for 64-bit) or i686 (for 32-bit)
   - **Threads:** POSIX
   - **Exception Handling:** SEH (for 64-bit) or DWARF (for 32-bit)
3. Add the MinGW `bin` folder (e.g., `C:\mingw-w64\mingw64\bin`) to your **System Path**.

Verify installation by running:
```sh
g++ --version
