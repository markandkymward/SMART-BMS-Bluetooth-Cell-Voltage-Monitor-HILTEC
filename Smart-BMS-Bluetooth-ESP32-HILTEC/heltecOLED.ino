void oledConnected()
{
  
}
void oledConnectionFailed()
{
  
}
void oledConnectingStatus(int status)
{
  
}
void heltecStartup()
{
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);
  Heltec.display->setContrast(255);
  Heltec.display->clear();
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->drawString(10,24,"Connecting...");
  Heltec.display->setFont(ArialMT_Plain_10);
  Heltec.display->display();
  

}
void showInfoOled()
{
  Heltec.display->clear();
  Heltec.display->drawString(0, 0, String((float)packBasicInfo.Volts/1000,1)+"v");
  Heltec.display->drawString(30,0,"("+String(float(packCellInfo.CellDiff)/1000.0,2)+")");
  Heltec.display->drawString(65, 0,String(packBasicInfo.CapacityRemainPercent)+"%");
  Heltec.display->drawProgressBar(86,0,38,10,packBasicInfo.CapacityRemainPercent);
  
  float averageCellVolts = 0.0;
  for (uint8_t i = 0; i <10; i++){
      averageCellVolts = packCellInfo.CellVolt[i] + averageCellVolts;
  }
  averageCellVolts = averageCellVolts/10;
  unsigned int balanceMask = 0;
  balanceMask = (packBasicInfo.BalanceCodeHigh<<8) | (packBasicInfo.BalanceCodeLow);
  int mid1 = 35;
  int mid2 = 99;
  int cell = 0;
  float scale = 0.5;
  for (int i = 14; i<= 64; i=i+10){
    Heltec.display->drawString(0,i,String(cell+1));
    if (cell < 4)
      Heltec.display->drawString(64,i,String(cell+6));
    else
      Heltec.display->drawString(64,i,"X");
    Heltec.display->drawRect(10,i,50,10);
    Heltec.display->drawRect(74,i,50,10);
    float width1 = (packCellInfo.CellVolt[cell]-averageCellVolts)/1000/scale * 100;
    float width2 = (packCellInfo.CellVolt[cell+5]-averageCellVolts)/1000/scale * 100;
    if (int(width1) >= 0) 
      Heltec.display->fillRect(mid1,i,int(width1),10); 
    else
      Heltec.display->fillRect(mid1+int(width1), i, abs(int(width1)), 10);  
    if (int(width2) >= 0) 
      Heltec.display->fillRect(mid2,i,int(width2),10); 
    else
      Heltec.display->fillRect(mid2+int(width2), i, abs(int(width2)), 10);  
    if (bitRead(balanceMask,cell)) Heltec.display->drawString(mid1+17, i-1, "B");
    if (bitRead(balanceMask,cell+5)) Heltec.display->drawString(mid2+17, i-1, "B");
    cell++;
  }
  Heltec.display->drawVerticalLine(mid1,14,50);
  Heltec.display->drawVerticalLine(mid2,14,50);
  Heltec.display->display();
  //Heltec.display->drawString(0,30,String((float)packBasicInfo.Volts / 1000));
}
