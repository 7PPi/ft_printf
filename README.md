# ft_printf
A complete custom implementation of the C standard printf function for 42 School. Supports all mandatory format specifiers (c s p d i u x X %) and uses a modular helper system. No bonus formatting included.

# 🔥 ft_printf — 42 Project

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Bonus-No-lightgrey?style=for-the-badge" />
</p>

---

## 📘 Overview

`ft_printf` is a custom re-implementation of the standard C function `printf`.

It prints formatted output to **stdout** using:
- `write()`
- variadic arguments (`va_list`, `va_start`, `va_arg`, `va_end`)
- internal helper functions

It is a mandatory 42 core project and is widely reused in future projects.

---

## ✔️ Supported Format Specifiers

| Format | Meaning |
|------|--------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address |
| `%d` | Integer (signed) |
| `%i` | Integer (signed) |
| `%u` | Unsigned integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Literal `%` symbol |

---

## 📁 Project Structure

📦 ft_printf/
├── ft_printf.c
├── ft_helpers.c
├── ft_helpers1.c
├── ft_printf.h
├── Makefile
└── README.md


- `ft_printf.c` — main dispatcher and parsing logic
- `ft_helpers.c & ft_helpers1.c` — conversion & printing utilities
- `ft_printf.h` — prototypes, includes, typedefs

---

## ⚙️ Compilation

Build the static library:

```bash
make
```

This will create:

	libftprintf.a

Remove object files:

	make clean

Remove object files + library:

	make fclean

Rebuild from scratch:

	make re

🧪 Example Usage
```
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d Hex: %x\n", "World", 42, 42);
    return 0;
}
```

Compile with your library:

	cc main.c libftprintf.a

💡 Key Concepts

- Variadic arguments (stdarg.h)

- Manual formatting without libc formatting

- Direct output using write()

- Type dispatching and conversion

- No dynamic memory required (except strings if implemented)

🚫 Not Included (as required)

❌ Width
❌ Precision
❌ Flags (-, 0, #, +, space)
❌ Bonus formatting

🧑‍💻 Author


Emanuel Tchipoque

🔗 LinkedIn: [Emanuel Tchipoque](https://www.linkedin.com/in/emanuel-tchipoque-820894198?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=ios_app)
