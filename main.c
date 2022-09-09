#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "bits.h"



int main()
{
  DIOInt('F',0x1f,0x0e);
  
  while(1)
  {
    DIOWritePin('F',2,off);
    DIOWritePin('F',1,off);
    DIOWritePin('F',3,off);
    if( !(GPIO_PORTF_DATA_R & 1<<0))
    {
      DIOWritePin('F',1,on);
    }
    if( !(GPIO_PORTF_DATA_R & 1<<4))
    {
      DIOWritePin('F',2,on);
    }
    if ( (!(GPIO_PORTF_DATA_R & 1<<4)) && (!(GPIO_PORTF_DATA_R & 1<<0)) )
    {
      while( (!(GPIO_PORTF_DATA_R & 1<<4)) && (!(GPIO_PORTF_DATA_R & 1<<0)))
      {
        DIOWritePin('F',3,on);
        DIOWritePin('F',1,off);
        DIOWritePin('F',2,off);
      }
    }
  }
}
  

