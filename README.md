# Command-Line Calculator (C++)

A simple C++ command-line calculator that supports basic arithmetic operations, exponentiation, square root calculations, and history tracking.

## 📌 Features
✅ Addition, Subtraction, Multiplication, and Division  
✅ Exponentiation (Power function)  
✅ Square Root Calculation  
✅ Error Handling (Invalid input, division by zero, negative square root)  
✅ Calculation History  

---

## 🛠️ Installation and Setup

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
