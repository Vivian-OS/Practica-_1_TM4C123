//GPIO interrupciones
//Vivian Odette Salinas Benavídez


#include "lib/include.h"

extern void Configurar_GPIO_C(void){

SYSCTL ->RCGCGPIO |=(1<<2);
                   //C
while ((SYSCTL -> PRGPIO&0x4) == 0){;}

GPIOC->LOCK = 0x4C4F434B; //desbloquea los puertos para escribir*
GPIOC->CR = (1<<0); // el pin 0 desbloque


GPIOC->DIR    |=(0<<6)|(1<<7);
GPIOC->PUR    |=(1<<6); //estado alto
GPIOC-> AFSEL |= 0x00;
//Vincular los pines al GPIO
GPIOC->PCTL   |= 0x00;
GPIOC->DEN    |=(1<<6)|(1<<7);
GPIOC -> AMSEL |=(0<<6)|(0<<7);
GPIOC->LOCK |=0x11111111;
//habilitar_IntGPIO();
}
// habilitacion de interrupciones

extern void habilitar_IntGPIO(void){

  NVIC ->IP[0] = (NVIC->IP[0] & 0xFF00FFFF) | (0x00800000);
  NVIC ->ISER[0] = 0x4;
    //ISR ->NVIC
    //NVIC_SetPriority(GPIOC_IRQn, 0);
    //NVIC_EnableIRQ(GPIOC_IRQn);


   GPIOC->IM |= (0<<6); //desactivamos el envio de la interrupcion al micro
   GPIOC->IS |= (0<<6); //interrumpe cuandi sea posible al borde
   GPIOC->IBE |=(0<<6); //lo que genere de la interrupcion esta controlada por
   GPIOC->IEV |=(1<<6);   //detecta los bordes de subida
   GPIOC ->RIS |= (0<<6); //registro de estado
   GPIOC->IM |= (1<<6);  //Se le ordena enviar la interrupcion al micro
   GPIOC->ICR |= 0xFF;


}
extern void GPIOC_ISR(void){

    if((GPIOC->RIS & 0b1000000) == (1<<6)){
              Prender_led();
              //GPIOC->ICR |= 0xFF;
              //uint32_t i;
              //for (i=0; i<100000;i++){}


          }

    GPIOC->ICR |=(1<<6)|(1<<7);

    }

extern void Prender_led (void){
    uint32_t i;
    GPIOC ->DATA |=0b10000000;
    for (i=0; i<400000;i++){}
    GPIOC ->DATA &= ~(0b10000000);
    for (i=0; i<400000;i++){}
    //GPIOC ->DATA = (1<<7);
    //for (i=0; i<100000;i++){}

    //GPIOC ->DATA = (0<<7);
      // for (i=0; i<100000;i++){}




}
