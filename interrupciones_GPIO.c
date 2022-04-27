//GPIO interrupciones
//Vivian Odette Salinas Benavídez
//Microcontroladores
//Usar puerto E para interrupciones

#include "lib/include.h"

extern void Configurar_GPIO_D(void)
{
SYSCTL-> RCGCPIO |=(1<<3);
while ((SYSCTL->PRGPIO&0x00000008)==){;}

GPIOD->DIR    |=(0<<5)|(1<<1)|(1<<0);
GPIOD->PUR    |=(1<<5); //estado alto
GPIOD-> AFSEL |= 0x00;
GPIOE->PCTL   |= 0x00;
GPIOD->DEN    |=(1<<5)|(1<<1)|(1<<0);

// habilitacion de interrupciones

   GPIOD->IM |= (0<<1) | (0<<0); //desactivamos el envio de la interrupcion al micro
   GPIOD->IS |= (0<<1) | (0<<0); //interrumpe cuandi sea posible al borde
   GPIOD->IBE |=(0<<1)| (0<<0); //lo que genere de la interrupcion esta controlada por
   GPIOD->IEV |=(1<<0) |(1<<0);   //detecta los bordes de subida
   GPIOD ->RIS |= (0<<4)|(0<<0); //registro de estado
  // GPIOD->IM |= (1<<0) | (1<<0);  //Se le ordena enviar la interrupcion al micro

 GPIOF->LOCK = 0x4C4F434B; //desbloquea los puertos para escribir*
 GPIOF_CR = (1<<0); // el pin 0 desbloque
}
extern void GPIOD_ISR(void);
{
    uint32_t i;
    GPIO->DATA = (1<<0); //led externo  D0
    for (i = 0; i<000000;i++){}
    GPIO->DATA = (0<<0);
    for (i = 0; i<000000;i++){}
    }


