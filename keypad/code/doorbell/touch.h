
#define numElectrodes 12

int checkTouchReleased() {
  int val=-1;
  if (MPR121.touchStatusChanged()) {
    MPR121.updateTouchData();
    for (int i = 0; i < numElectrodes; i++) {

      if (MPR121.isNewTouch(i))
      {
       
      }
      else if (MPR121.isNewRelease(i)) {
        
        val = i;
      }
    }
  }
return(val);
}
