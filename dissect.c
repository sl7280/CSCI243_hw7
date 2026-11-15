/**
*
*
*@course CSCI243
*@author Stephanie Livingston <sl7280@rit.edu>
*/

#include <stdio.h>
#include <stdbool.h>


/**
*leer cada letra para que podamos convertirlos en un mansaje
*@return none
*@return int to say if it was sucsessful or not
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
    int count;

    //read in each character while it is not EOF
    while(is_reading == true && b0 != EOF && b0 != 10){
        b0 = getchar();
//        printf("debugging for EOF at beginning of while loop:%c\n", b0);
        if(b0 != EOF && b0!=10){

            printf("msg ");
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
//            printf("%c", b1);
            b2 = getchar();
  //          printf("%c", b2);
            b3 = getchar();
    //        printf("%c", b3);
            b4 = getchar();
      //      printf("%c", b4);

            unsigned long big_endian = ((unsigned long)b1 << 24) | ((unsigned long)b2 << 16) | ((unsigned)b3 << 8) | (unsigned)b4;
            printf(" ts=%u ", big_endian);

            //print out each character in the message
            printf("payload=\"");
            for(int i=0; i < message_length; i++){
                b0= getchar();
                if(b0< 32 || b0 >= 127){
                    printf(".");
                }
                else{
                    
                    printf("%c", b0);
                }
            }
            printf("\"");
            printf("\n");
            count+=1;
        //end of the if statement for EOF
        }

        else{
            is_reading = false;
        }

    }
    printf("count: %d", count);
    printf("\n");

//end of main
return 0;
}
