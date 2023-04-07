
# RPC Client-Server
This project is a simple implementation of an RPC (Remote Procedure Call) client-server communication using the gRPC library with QtProtobuf.

# Overview
RPC is a communication protocol that allows a program to execute a procedure in a different address space. gRPC is a modern, high-performance, open-source framework that supports multiple languages and platforms. It is built on top of HTTP/2, uses Protocol Buffers as the interface description language, and provides features such as bidirectional streaming, flow control, and blocking or non-blocking bindings.

QtProtobuf is a Qt-based library that provides Protocol Buffers support for Qt applications. It provides a simple interface for encoding and decoding messages, handles protocol versioning, and supports both synchronous and asynchronous communication.

This project demonstrates a simple RPC client-server communication using gRPC and QtProtobuf. The server listens for requests on a given port and responds to requests by executing the specified function. The client connects to the server and sends a request, then receives a response from the server.

# Prerequisites
To build and run this project, you will need:

CMake 3.15 or higher
gRPC 1.38 or higher
Protobuf 3.0 or higher
Qt 5 or higher

# Building the Project
To build the project, follow these steps:

1. Clone the repository to your local machine: git clone https://github.com/maxsdrv/rpc-client-server.git
2. Open a terminal window and navigate to the root directory of the project: cd rpc-client-server
3. Create a build directory: mkdir build && cd build
4. Configure the project using CMake: cmake ..
5. Build the project: cmake --build .

This will generate two executable files: server and client in the build directory.

Running the Applications
To run the server, navigate to the build directory and run the server executable:

bash
Copy code
cd build
./server
The server will start running and listening on port 50051.

To run the client, open a new terminal window and navigate to the build directory. Then run the client executable:

bash
Copy code
cd build
./client
The client will connect to the server and make a simple RPC call.

Contributing
If you would like to contribute to this project, please submit a pull request on GitHub.
