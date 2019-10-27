# Protocol_Buffers_Example
This repository shows  use of Nanopb implementation of Protocol Buffers.


The message format is specified in the .proto file

Using the nano_pb libraries and tools the required files to include are generated

The try_enc.c file is the source code for the message encoding and writed it to a file in binary format.

The try_dec. file is the source code for the message decoding. It reads the file in binary format that previous programm created and it decodes the message.

Makefile is corresponds to try_enc and Makefile2 to the try_dec compiling and linking.
 
 *To be noted that the inlcude path in the Makefiles needs to change to the user 's directory path of nano_pb libraty
