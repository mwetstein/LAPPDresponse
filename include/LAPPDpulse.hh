#ifndef LAPPDPULSE_HH
#define LAPPDPULSE_HH

#include "TObject.h"
#include "TH1.h"

class LAPPDpulse : public TObject {

 public: 

  LAPPDpulse(double plusetime, double lefttime, double righttime, double peakvalue, int stripnum);

  ~LAPPDpulse();

  Double_t Getpulsetime() { return _pulsetime; }
  Double_t Getlefttime() { return _lefttime; }
  Double_t Getrighttime() { return _righttime; }
  Double_t Getpeakvalue() { return _peakvalue; }
  Double_t Getstripnum(){ return _stripnum; }


 private: 

  double _pulsetime,_lefttime,_righttime,_peakvalue;
  int _stripnum; 
 
  ClassDef(LAPPDpulse,0)

};

#endif
