#!/bin/bash

echo 0 | sudo tee /proc/sys/kernel/randomize_va_space # disable ASLR, dangerous, please set it back to 2 after finishing
docker build -t vuln_program .
docker run -d -p 1337:1337 --security-opt seccomp=unconfined vuln_program:latest
