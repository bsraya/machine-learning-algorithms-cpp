FROM gcc:latest

WORKDIR /app

COPY . /app

RUN ["apt", "update"]

RUN ["apt", "upgrade"]

RUN ["apt", "install", "cmake", "libeigen3-dev", "clang-format", "tree", "-y"]