#include <stdio.h>
#include <pb_common.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "try_enc.pb.h"
#include <stdlib.h>

bool decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg) {


	size_t i=stream->bytes_left;
        pb_byte_t* buf=(pb_byte_t *) malloc(stream->bytes_left*sizeof(pb_byte_t));
        pb_read(stream, buf, stream->bytes_left);
	for(size_t j=0; j<i;j++){
        printf("%c", buf[j]);
	}
	printf(" size of pb byte %ld", sizeof(pb_byte_t));
   	*arg=(pb_byte_t *) malloc(i*sizeof(pb_byte_t));

for(size_t j=0; j<i;j++){
       *(pb_byte_t*)(*arg+j)=buf[j];
	}
	

return 1;

}




int main()
{

uint8_t buffer[200];
//size_t message_length;
//bool status;



Peri myperi = Peri_init_zero;


FILE * fp  = fopen("/home/kostas/Downloads/nanopb/examples/myex/testing", "rb");
int i=0;
while(!feof(fp)){
buffer[i]=fgetc(fp);
i++;
}

fclose(fp);
myperi.dev_name.funcs.decode=&decode_string;


pb_istream_t stream = pb_istream_from_buffer(buffer, i);
pb_decode(&stream, Peri_fields, &myperi);
/*
if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
        
 */      
 /* Print the data contained in the message. */
        printf("Your dev measue %f!\n", (float)myperi.value);


     printf(" %s\n",(char*) (myperi.dev_name.arg));
    
    return 0;

}




