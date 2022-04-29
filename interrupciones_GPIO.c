//GPIO interrupciones
//Vivian Odette Salinas Benavídez


#include "lib/include.h"
extern void Configurar_GPIO_C(void)
{
SYSCTL -> RCGCGPIO |=(1<<3);
while ((SYSCTL -> PRGPIO&0x4) == 0){;}

GPIOC->LOCK = 0x4C4F434B; //desbloquea los puertos para escribir*
GPIOC->CR = (1<<0); // el pin 0 desbloque


GPIOC->DIR    |=(0<<6)|(1<<7);
GPIOC->PUR    |=(1<<6); //estado alto
GPIOC-> AFSEL |= 0x00;
GPIOC->PCTL   |= 0x00;
GPIOC->DEN    |=(1<<6)|(1<<7);
GPIOC -> AMSEL |=0x00;
GPIOC -> PCTL |=0x00;
habilitar_IntGPIO();
}
// habilitacion de interrupciones

extern void habilitar_IntGPIO(void){

    NVIC ->IP[0] = (NVIC->IP[0] & 0xFF00FFFF) | (0x4);
    NVIC ->ISER[0] = 0x4;


   GPIOC->IM |= (0<<6) | (0<<0); //desactivamos el envio de la interrupcion al micro
   GPIOC->IS |= (0<<6) | (0<<0); //interrumpe cuandi sea posible al borde
   GPIOC->IBE |=(0<<6)| (0<<0); //lo que genere de la interrupcion esta controlada por
   GPIOC->IEV |=(1<<0) |(1<<0);   //detecta los bordes de subida
   GPIOC ->RIS |= (0<<6)|(0<<0); //registro de estado
  // GPIOD->IM |= (1<<0) | (1<<0);  //Se le ordena enviar la interrupcion al micro


}
extern void GPIOC_ISR(void){
    //uint32_t i;
    //GPIOC -> DATA = (1<<0); //led externo  D0
    //for (i = 0; i<000000;i++){}
    //GPIOC ->DATA = (0<<0);
    //for (i = 0; i<000000;i++){}
    if (GPIOC->RIS == (1<<0)){ //PF0 el 0 representa el etado de cambio
          char = Rx_string('%');
          numero = atoi(cadena_num);
          numero = (long)(numero +25);
          Itoa(numero,cadena_num,10);
          Tx_string(cadena_num);
    }
          if (GPIOC->RIS == (1<<6)){

               }
               GPIOC->ICR |= (1<<6)| (1<<7) ;


