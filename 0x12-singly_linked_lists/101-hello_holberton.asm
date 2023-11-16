section .data
hello db "Hello, Holberton", 10

section .text
global main
extern printf

main:
mov edi, hello
mov eax, 0
call printf

mov eax, 60
xor edi, edi
syscall
