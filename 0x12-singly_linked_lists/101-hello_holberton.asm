section .data
msg db "Hello, Holberton", 0
fmt db "%s", 10, 0

section .text
global main
extern printf

main:
mov rdi, fmt
mov rsi, msg
mov eax, 0
call printf

mov eax, 0
ret
