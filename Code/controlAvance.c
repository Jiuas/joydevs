
#include <16f877a.h>
#fuses HS,NOWDT,NOBROWNOUT,NOCPD,NODEBUG
#useDelay (clock=20M)
#USE FAST_IO(D)
#USE FAST_IO(C)

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
   set_tris_b(0b11111111);
   set_tris_d(0b00000000);
   set_tris_c(0b00000000);
   if (ARRIBA){
      output_high(ATRAS_1_UP);
      output_high(ATRAS_2_UP);
      output_high(ATRAS_3_UP);
      output_high(ATRAS_4_UP);
   }
   if(ABAJO){
      output_high(ATRAS_1_DOWN);
      output_high(ATRAS_2_DOWN);
      output_high(ATRAS_3_DOWN);
      output_high(ATRAS_4_DOWN);
   }
   if(DERECHA){
      output_high(MOTORDER);
   }
   if (IZQUIERDA){
      output_high(MOTORIZQ);
   }
}
