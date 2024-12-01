#!/bin/bash

docker build -t vuln_program .
docker run -d -p 1337:1337 --security-opt seccomp=unconfined vuln_program:latest
