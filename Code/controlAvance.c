
#include <16f877a.h>
#fuses HS,NOWDT,NOBROWNOUT,NOCPD,NODEBUG
#USE delay (clock=20M)
#USE FAST_IO(D)
#USE FAST_IO(C)

#byte pd=0x08
#byte pc=0x07
#byte pb=0x06

#define ARRIBA pin_b0
#define DERECHA pin_b1
#define ABAJO pin_b2
#define IZQUIERDA pin_b3
#define BTN_pin_b4
#define BTN_pin_b5
//emision del pic al l293
#define ATRAS_1_UP pin_d0
#define ATRAS_1_DOWN pin_d1
#define ATRAS_2_UP pin_d2
#define ATRAS_2_DOWN pin_d3
/////
#define ATRAS_3_UP pin_d4
#define ATRAS_3_DOWN pin_d5
#define ATRAS_4_UP pin_d6
#define ATRAS_4_DOWN pin_d7

#define MOTORIZQ pin_c0
#define MOTORDER pin_c1

#define DERECHA1

void main(){
   pd = 0;
   pb = 0;
   pc = 0;
   port_b_pullups(0);
   set_tris_b(0b11111111);
   set_tris_d(0b00000000);
   set_tris_c(0b00000000);
   while (TRUE) {
      if (input(ARRIBA)==1){
         output_high(ATRAS_1_UP);
         output_high(ATRAS_2_UP);
         output_high(ATRAS_3_UP);
         output_high(ATRAS_4_UP);
      }
      else{
         output_low(ATRAS_1_UP);
         output_low(ATRAS_2_UP);
         output_low(ATRAS_3_UP);
         output_low(ATRAS_4_UP);
      }
      if(input(ABAJO)==1){
         output_high(ATRAS_1_DOWN);
         output_high(ATRAS_2_DOWN);
         output_high(ATRAS_3_DOWN);
         output_high(ATRAS_4_DOWN);
      }
      else{
         output_low(ATRAS_1_DOWN);
         output_low(ATRAS_2_DOWN);
         output_low(ATRAS_3_DOWN);
         output_low(ATRAS_4_DOWN);
      }
      if(input(DERECHA) == 1){
         output_high(MOTORDER);
      }
      else{
         output_low(MOTORDER);
      }
      if (input(IZQUIERDA) ==1){
         output_high(MOTORIZQ);
      } else {
         output_low(MOTORIZQ);
      }
      
   }
}
