#ifndef LAPPDRESPONSE_HH
#define LAPPDRESPONSE_HH

#include "TObject.h"
#include "TH1.h"

class LAPPDresponse : public TObject {

 public: 

  LAPPDresponse();

  ~LAPPDresponse();

  void SetFreezeTime(double freezetime);

  void AddPhoton(double trans, double para, double time);

  TH1D* CalcSinglePhotonTrace(int CHnumber, double trans, double para, double time, int parity);
	
  TH1D* GetTrace(int CHnumber, int parity);



 private: 


  //relevant to a particular event
  double _freezetime;

  //input parameters and distributions
  TH1D* _templatepulse;
  TH1D* _PHD;
  TH1D* _pulsewidth; 
  double _noiselevel;
  int _nsamples;
  double _samplewidth;

  //output responses
  TH1D** StripResponse_neg;
  TH1D** StripResponse_pos;

  //useful functions
  int FindNearestStrip(double trans);
  double TransStripCenter(int CHnum);

  
  ClassDef(LAPPDresponse,0)

};

#endif
