*This project has been created as part
of the 42 curriculum by rodcaeta*
# FT_PRINTF

# DESCRIPTION

`ft_printf` is a reimplementation of the C `printf` function.
The goal of this project is to understand variadic functions (`va_list`).\
\
This function prints text to the screen and returns how many characters it was printed.
### Supported format specifiers

- `%c` = prints a single character
- `%s` = prints a string
- `%u` = prints an unsigned integer
- `%d` / `%i` = prints a signed integer
- `%x` = prints a hexadecimal number (lowercase)
- `%X` = prints a hexadecimal number (uppercase)
- `%p` = prints a pointer address
- `%%` = prints a literal `%`


# INSTRUCTIONS

## How to compile

Build the library:
```bash
make
```

This will generate `libftprintf.a`.

## How to use

Compile:
```bash
cc -Wall -Wextra -Werror ft_printf.c ft_printf_functions.c
```

# ALGORITHM EXPLANATION
## Algorithm explanation

`ft_printf` scans the format string using a pointer (`str`) and prints output as it goes.

1. Start variadic processing with `va_start(args, str)` and initialize `printed_count = 0`.
2. While `*str` is not `'\0'`:
   - If the current character is `%`:
     - Advance the pointer (`++str`) to read the format type (for example `c`, `s`, `d`, `x`, etc.).
     - Call `fmt_check(type, args)` to dispatch the correct printing function.
     - If `fmt_check` returns `-1`, stop and return `-1` (error).
     - Otherwise add the returned value (how many chars were written) to `printed_count`.
   - If the current character is not `%`:
     - Write it directly with `write(1, str, 1)`.
     - If `write` fails, return `-1`.
     - Otherwise increment `printed_count`.
   - Move to the next character with `str++`.
3. Finish variadic processing with `va_end(args)` and return `printed_count`.

`fmt_check` is the dispatcher: it receives the specifier character and uses `va_arg` to fetch the next argument with the correct type, then calls the matching helper function (`ft_printf_char`, `ft_printf_str`, `ft_printf_nbr`, `ft_printf_hexa`, `ft_printf_ptr`, etc.). Each helper returns the number of printed characters (or `-1` on error).

---

# RESOURCES

## Manuals
- man stdarg
- man 3 printf


## Tutorials

- https://www.geeksforgeeks.org/c/variadic-functions-in-c/
- https://youtu.be/Hb2m7htiKWM

## AI Usage
I useed AI for:
- Help me how to format my README
- To find more documentations about variadic functions 