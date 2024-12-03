FROM ubuntu:latest

RUN useradd -d /home/user/ -m -p user -s /bin/bash user 
RUN echo "user:user" | chpasswd

WORKDIR /home/user

COPY vulnerable_program_static .
COPY ynetd .

RUN chmod +s /home/user/vulnerable_program_static
RUN chmod +x /home/user/ynetd 
RUN echo "BUV{5om3_1MPOR74N7_DO5pOO933N7}" > flag
RUN chmod 600 flag 

USER user 
EXPOSE 1337  
CMD ./ynetd -p 1337 "env -i ./vulnerable_program_static" 

