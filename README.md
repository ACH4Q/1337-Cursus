# Libft

Welcome to my `Libft` project repository! This is my first personal library built in C as part of the 1337 School curriculum. The goal of this project is to deepen my understanding of standard C functions by reimplementing them from scratch and creating a collection of utility functions that will be useful for future projects.

## Overview

The `Libft` project is all about coding a C library. It includes various functions that mirror those found in the standard C library (libc), as well as additional functions that provide extra utilities not available in libc. This project is fundamental to the curriculum as it lays the groundwork for more complex projects by teaching you how to handle memory, strings, and more in C.

## Contents

- **Part 1: Libc Functions**  
  I reimplemented several standard C library functions, such as:
  - `ft_isalpha`
  - `ft_isdigit`
  - `ft_memset`
  - `ft_strcpy`
  - `ft_strcat`
  - And many others...

- **Part 2: Additional Functions**  
  I also created additional functions that are not found in libc but are commonly needed in various C programs:
  - `ft_substr`
  - `ft_strjoin`
  - `ft_strtrim`
  - `ft_split`
  - `ft_itoa`
  - And more...

- **Bonus Part: Linked List Manipulation**  
  I implemented functions for handling linked lists, which are often crucial for various data structures and algorithms:
  - `ft_lstnew`
  - `ft_lstadd_front`
  - `ft_lstsize`
  - `ft_lstlast`
  - `ft_lstdelone`
  - `ft_lstclear`
  - `ft_lstiter`
  - `ft_lstmap`

## Getting Started

### Prerequisites

To compile the library, you need a C compiler like `gcc`. The library is designed to compile with the following flags:
- `-Wall`
- `-Wextra`
- `-Werror`

### Installation

To install and compile the library, simply clone this repository and run `make`:

```bash
git clone https://github.com/yourusername/libft.git
cd libft
make
