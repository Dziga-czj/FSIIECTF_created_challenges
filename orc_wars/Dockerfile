FROM debian:latest

RUN apt-get update
RUN apt-get install -y binutils make gcc-multilib libc6 libc6-i386 git 
RUN git clone https://github.com/johnsonjh/ynetd.git /ynetd
RUN cd /ynetd && make

RUN useradd -m pwn3r

RUN echo "PasswordAuthentication no" >> /etc/ssh/sshd_config

WORKDIR /home/pwn3r/

COPY ./orc_wars.c ./
COPY ./flag.txt ./
COPY ./Makefile ./

RUN make
RUN chown -R pwn3r:pwn3r /home/pwn3r && chmod -R 755 /home/pwn3r

EXPOSE 1339

CMD ["/ynetd/./ynetd","-p","1342","/home/pwn3r/orc_wars"]


