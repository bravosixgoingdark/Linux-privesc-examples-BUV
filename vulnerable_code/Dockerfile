FROM ubuntu:latest

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY vulnerable_program_static .
COPY ynetd .

RUN chmod +s /home/ctf/vulnerable_program_static
RUN chmod +x /home/ctf/ynetd 

USER ctf
EXPOSE 1337  
CMD ./ynetd -p 1337 "env -i ./vulnerable_program_static" 

