FROM debian:latest

RUN apt-get update && apt-get install -y \
    nasm \
    gcc \
    make

WORKDIR /usr/app

COPY . .

CMD ["make"]
