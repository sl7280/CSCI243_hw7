/**
*
*
*HEADER TS
*
*/

#include <stdio.h>
#include <stdbool.h>


/**
*
*/
int main(void){
    int version;
    int type;
    int len;
    int ts;
    int message_length;
    int b0;
    int b1;
    int b2;
    int b3;
    int b4;
    int big_endian;
    bool is_reading = true;

    //read in each character while it is not EOF
    while(is_reading == true){
        b0 = getchar();
        if(b0 != EOF){

            //find the version and the type in the first char
            //find the high and low nibbles
            int high = (b0 >> 4) & 0xF;
            int low = b0 & 0xF;
            printf("version=%d type=%d", high, low);
           
            //find the length of the message
            b0 = getchar();
            b1 = b0;
            b0 = getchar();
            b2 = b0;
            big_endian = ((unsigned)b1 << 8) | (unsigned)b2;
            printf(" len=%d ", big_endian);
            message_length = big_endian;
            
            //get the timestamp   
            b1 = getchar();
            printf("%c", b1);
            b2 = getchar();
            printf("%c", b2);
            b3 = getchar();
            printf("%c", b3);
            b4 = getchar();
            printf("%c", b4);

            unsigned int big_endian = ((unsigned long)b1 << 32) | ((unsigned long)b2 << 16) | ((unsigned)b3 << 8) | (unsigned)b4;
            printf(" ts=%u ", big_endian);

            //print out each character in the message
            for(int i=0; i < message_length; i++){
                b0 = getchar();
                printf("%c", b0);
            }
            printf("\n");

        //end of the if statement for EOF
        }

        else{
            is_reading = false;
        }

    }
    printf("\n");

//end of main
}
