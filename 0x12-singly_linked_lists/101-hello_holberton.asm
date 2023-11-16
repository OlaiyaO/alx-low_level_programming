section .data
hello db "Hello, Holberton", 10

section .text
global main
extern printf

main:
; print the main message
mov edi, format
mov eax, 0
call printf

; print a newline
mov edi, newline
mov eax, 0
call printf

; exit the program
mov eax, 60          ; system call number for sys_exit
xor edi, edi         ; exit code 0
syscall              ; call kernel

format: db "Hello, Holberton", 0
newline: db 10
