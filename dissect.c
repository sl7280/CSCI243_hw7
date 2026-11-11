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
    char payload[];

    int b0;
    bool is_reading = true;
    int counter = -1;

    //read in each character while it is not EOF
    while(is_reading == true){
        b0 = getchar();
        counter += 1;
        if(b0 != EOF){

        if(counter == 0){
            printf("test 0 : %d\n" b0);
            
        }
        





            printf("%c", b0);
        }
        else{
            is_reading = false;
        }
    }



}
