
#include <TM1650.h>
TM1650 module(7, 6);  // SDA=A4, SCL=A5


void setup()
{
  module.setDisplayToString("HALO");
  delay(1000);  

  module.clearDisplay();
  module.setDisplayToString("HALO1234", 0xF0);
  delay(1000);  
}

void loop()
{
  module.clearDisplay();
  for(byte nPos=0; nPos<16; nPos++)     // 16 positions (columns) on TM1640, most others have less
  {
    for(int nVal=0; nVal<=0xFF; nVal=nVal*2+1)     // max 8 segments on TM1638QYF module.
    {
      module.setSegments(nVal, nPos);   // note: you can use setSegments16() when module class supports > 8 segments (TM1638, TM1668)
      delay(100);
    }
  }
  delay(1000);
}
