*This project has been created as part of the 42 curriculum by aakhmeto.*

# ft_printf

`ft_printf` is a 42 Common Core project (Circle 1).  
The goal is to reimplement `printf()` with variadic arguments and build it as a static library.

- Author / Intra: `aakhmeto`

## Description

This project implements:

```c
int	ft_printf(const char *format, ...);
```

Mandatory supported conversions:

- `%c`
- `%s`
- `%p`
- `%d`
- `%i`
- `%u`
- `%x`
- `%X`
- `%%`

Scope limits from the mandatory part:

- no original libc buffer management
- no flags (`-`, `0`, `#`, `+`, space)
- no field width
- no precision
- no length modifiers (`l`, `ll`, `h`, etc.)

## Subject Requirements

| Item | Requirement |
|---|---|
| Program name | `libftprintf.a` |
| Turn-in files | `Makefile`, `*.h`, `*/*.h`, `*.c`, `*/*.c` |
| Makefile rules | `NAME`, `all`, `clean`, `fclean`, `re` |
| Allowed external functions | `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end` |
| Libft authorized | Yes |
| Library build tool | `ar` (using `libtool` is forbidden) |

## Instructions

Build:

```bash
make
```

Clean objects:

```bash
make clean
```

Full clean:

```bash
make fclean
```

Rebuild:

```bash
make re
```

The build output is `libftprintf.a` at the project root.

Linking example:

```bash
cc main.c -L. -lftprintf -o app
```

or:

```bash
cc main.c libftprintf.a -o app
```

Include in your source:

```c
#include "includes/ft_printf.h"
```

## Algorithm and Data Structure Choices

The implementation uses a linear one-pass parser over the format string.

Algorithm overview:

1. Scan `format` from left to right.
2. For plain characters, write directly to `stdout`.
3. When `%` is found, parse the next conversion metadata with `ft_get_arg_info`.
4. Dispatch to a dedicated printer function via `ft_print_types`.
5. Accumulate the total number of printed characters, or return `-1` on write failure.

Chosen data structure:

- `t_argument` (in `includes/ft_printf.h`) stores `type` (conversion kind) and `len` (how many format characters were consumed).

Justification:

- A tiny struct keeps parser and dispatcher decoupled and easy to extend.
- Dedicated handlers (`ft_print_c_type`, `ft_print_s_type`, etc.) keep each conversion isolated and testable.
- Helper output functions (`*_ret`) unify write-error propagation, making failure handling consistent.
- Numeric output is centralized through base conversion helpers (`ft_putnbr_base_fd`, `ft_len_num_base`) to avoid duplicated logic.

## Behavior Notes

- `%s` with `NULL` prints `(null)`.
- `%p` with `NULL` prints `(nil)`.
- Return value matches `printf` contract: number of printed characters, or `-1` on write error.

## Project Structure

- Header: `includes/ft_printf.h`
- Source files: `sources/*.c`
- Internal dependency: `libft/`
- Build file: `Makefile`
- Output library: `libftprintf.a`

## Skills Developed in This Project

This project develops practical low-level C skills:

- using variadic arguments (`stdarg.h`) safely and predictably
- designing a parser/dispatcher flow for formatted output
- handling edge cases (`NULL`, `INT_MIN`, zero values, invalid specifier paths)
- organizing reusable helper functions for output and base conversion
- propagating system call failures (`write`) through a consistent error contract
- building and linking a static library with a clean `Makefile` workflow

## Key Achievements

- Built a working `printf`-compatible core for mandatory 42 conversions (`cspdiuxX%`).
- Implemented modular conversion handlers with shared output helpers.
- Kept parser state minimal through `t_argument` metadata (`type` + consumed length).
- Integrated project-local `libft` and produced a root-level `libftprintf.a`.
- Matched expected return-value behavior (printed length or `-1` on write error).

## How This Maps to Real-World Engineering

- **Interface contracts:** reproducing a known API behavior is core to compatibility work.
- **Modular architecture:** parser + dispatcher + handlers mirrors production formatter/logging pipelines.
- **Error discipline:** explicit propagation of low-level I/O failures improves reliability.
- **Maintainability:** small focused units reduce regression risk and simplify extension (e.g., bonus flags).
- **Build reproducibility:** static library packaging and deterministic make targets reflect CI-friendly practices.

## Resources

Classic references:

- `printf(3)`: https://man7.org/linux/man-pages/man3/printf.3.html
- `stdarg(3)`: https://man7.org/linux/man-pages/man3/stdarg.3.html
- C variadic functions (cppreference): https://en.cppreference.com/w/c/variadic
- 42 `ft_printf` subject PDF: `ft_printf_subject.pdf`

