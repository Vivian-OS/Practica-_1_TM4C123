//GPIO interrupciones
//Vivian Odette Salinas Benavídez

#include "lib/include.h"
extern void Configurar_GPIO_D(void)
{
SYSCTL -> RCGCGPIO |=(1<<3);
//while ((SYSCTL->RCGCGPIO&0x00000008)==){;}

GPIOD->LOCK = 0x4C4F434B; //desbloquea los puertos para escribir*
GPIOD->CR = (1<<0); // el pin 0 desbloque


GPIOD->DIR    |=(0<<5)|(1<<1)|(1<<0);
GPIOD->PUR    |=(1<<5); //estado alto
GPIOD-> AFSEL |= 0x00;
GPIOD->PCTL   |= 0x00;
GPIOD->DEN    |=(1<<5)|(1<<1)|(1<<0);
}
// habilitacion de interrupciones

extern void habilitar_IntGPIO(void){

    NVIC ->IP[1] = (NVIC->IP[1] & 0xFFFFFF00) | (0x00100000);
    NVIC ->ISER[0] = 0x8;


   GPIOD->IM |= (0<<1) | (0<<0); //desactivamos el envio de la interrupcion al micro
   GPIOD->IS |= (0<<1) | (0<<0); //interrumpe cuandi sea posible al borde
   GPIOD->IBE |=(0<<1)| (0<<0); //lo que genere de la interrupcion esta controlada por
   GPIOD->IEV |=(1<<0) |(1<<0);   //detecta los bordes de subida
   GPIOD ->RIS |= (0<<4)|(0<<0); //registro de estado
  // GPIOD->IM |= (1<<0) | (1<<0);  //Se le ordena enviar la interrupcion al micro


}
extern void GPIOD_ISR(void)
{
    uint32_t i;
    GPIOD -> DATA = (1<<0); //led externo  D0
    for (i = 0; i<000000;i++){}
    GPIOD ->DATA = (0<<0);
    for (i = 0; i<000000;i++){}

    }
