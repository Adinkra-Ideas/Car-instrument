# Stage 1: Setup QEMU and dependencies
FROM multiarch/qemu-user-static as qemu

# Stage 2: Build stage
FROM balenalib/raspberrypi4-64-debian:latest

# Copy QEMU from the first stage
COPY --from=qemu /usr/bin/qemu-aarch64-static /usr/bin/

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libgl1-mesa-dev \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-declarative-dev \
    qt6-base-dev-tools \
    curl \
    git

# Set up work directory
WORKDIR /workspace

RUN ls -l /workspace

# Copy the source code into the container
COPY . .

RUN mkdir -p build && cd build && cmake ../ && make

# Debug: List files in the build directory after build
RUN ls -l /workspace/build