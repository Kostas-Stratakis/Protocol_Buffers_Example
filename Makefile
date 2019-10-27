# Include the nanopb provided Makefile rules
include /home/kostas/Downloads/nanopb/extra/nanopb.mk

# Compiler flags to enable all warnings & debug info
CFLAGS = -Wall -Werror -g -O0
CFLAGS += -I$(NANOPB_DIR)

# C source code files that are required
CSRC  = try_enc.c                   # The main program

CSRC += try_enc.pb.c                # The compiled protocol definition
CSRC += $(NANOPB_DIR)/pb_encode.c  # The nanopb encoder
CSRC += $(NANOPB_DIR)/pb_decode.c  # The nanopb decoder
CSRC += $(NANOPB_DIR)/pb_common.c  # The nanopb common parts

# Build rule for the main program
try_enc: $(CSRC)
	$(CC) $(CFLAGS) -otry_enc $(CSRC)
	


# Build rule for the protocol
try_enc.pb.c: try_enc.proto
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. try_enc.proto

