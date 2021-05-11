# ft_printf

## Features
Real printf function and flags of "cspdiuxX%" are validated.

## Requirement
- gcc compiler

## Usage
Clone this repository:
```shell
git clone https://github.com/sakku-14/ft_printf
```

Generate libftprintf.a:
```shell
make
```

Remove objective files:
```shell
make clean
```

Delete all:
```shell
make fclean
```

Include ***ft_printf.h*** then you can use ft_printf function.

## Note

| function name | libftprintf.a |
| ---- | ---- |
| Prototype | int ft_printf(const char \*, \.\.\.); |
| External functs | malloc, free, write, va_start, va_arg, va_copy, va_end |
| Description | Write a library that contains ft_printf, a function that will mimic the real printf |

## Author
- Yuki Sakuma
