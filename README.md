# Hello C Program

A simple command-line program written in C that serves as an introduction to handling command-line arguments and structuring a basic C application.

## Features

- Greets the world with the classic "Hello World!".
- Greets a user by name.
- Offers a formal greeting with a title (MR./MS.) based on a gender argument.
- Handles both uppercase and lowercase input for the gender option.
- Provides a detailed help message with usage instructions.
- Gracefully handles invalid input or an incorrect number of arguments.

## Prerequisites

To build and run this program, you need a C toolchain, including `gcc` and `make`.

## Building

This project uses a `Makefile` to automate the compilation process. Open a terminal in the project directory and use the following commands:

**Compile the program:**

```bash
make
```

For a safer compilation that enables warnings for potential issues in the code, it is recommended to use the following flags:

```bash
gcc -Wall -Wextra -pedantic hello.c -o hello
```

## Usage

Once compiled, you can run the program in several ways:

**1. Generic Greeting**
Run the program without arguments to print "Hello World!".

```bash
./hello
```

Output:

```bash
Hello World!
```

**2. Personal Greeting**
Provide a name as an argument to get a personalized greeting.

```bash
./hello Richard
```

Output:

```bash
Hello Richard!
```

**3. Formal Greeting**
Provide a gender (`M`/`m` for male, `F`/`f` for female) and a name.

```bash
./hello M Johnson
```

Output:

```bash
Greetings MR. Johnson! It's pleasant to meet you!
```

**4. Displaying Help**
Use the `-h` or `--help` flag to display the instructions.

```bash
./hello --help
```

Output:

```bash
Usage: ./hello [OPTION] [NAME]
Greets a person in different ways.

OPTIONS:
  (none)        Greets the provided name.
  M | m         Adds the title 'MR.' to the greeting.
  F | f         Adds the title 'MS.' to the greeting.
  -h, --help    Shows this help message.

EXAMPLES:
  ./hello Michael
  ./hello F Maria
```
