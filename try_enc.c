#include <stdio.h>
#include <pb_common.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "try_enc.pb.h"
#include <stdlib.h>


bool write_string(pb_ostream_t *stream, const pb_field_t *field, void * const *arg)
{
    char *str = *arg;
	printf("inside %ld \n",strlen(str));
    if (!pb_encode_tag_for_field(stream, field))
        return false;

    return pb_encode_string(stream, (uint8_t*)str, strlen(str));
}





int main()
{

uint8_t buffer[200];
size_t message_length;
bool status;

Peri myperi = Peri_init_zero;
pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

myperi.value=13.4f;
printf("%f\n", myperi.value);

char* mess="something to say\0";
myperi.dev_name.arg=mess;
//myperi.dev_name.funcs.encode(&stream, &Peri_fields[0], (char*)myperi.dev_name.arg));
myperi.dev_name.funcs.encode=&write_string;
myperi.dev_name.arg=(char *)malloc(sizeof(mess));
myperi.dev_name.arg=mess;
printf("it gets executed\n");

status = pb_encode(&stream, Peri_fields, &myperi);
message_length = stream.bytes_written;
printf("message length %ld\n", message_length);


if (!status)
        {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }




FILE * fp  = fopen("/home/kostas/Downloads/nanopb/examples/myex/testing", "wb");
for(int i=0; i<message_length; i++){
fputc(buffer[i], fp);
}

fclose(fp);
return 0;

}
