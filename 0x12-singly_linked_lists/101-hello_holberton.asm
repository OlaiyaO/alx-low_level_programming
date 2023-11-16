section .data
hello db "Hello, Holberton", 10

section .text
global main
extern printf

main:
mov edi, format
mov eax, 0
call printf

mov edi, newline
mov eax, 0
call printf

mov eax, 60
xor edi, edi
syscall

format: db "Hello, Holberton", 0
newline: db 10
