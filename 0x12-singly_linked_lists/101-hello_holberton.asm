section .data
format db "Hello, Holberton", 10

section .text
global main
extern printf

main:
mov edi, format
xor eax, eax
call printf

mov eax, 60
xor edi, edi
syscall
