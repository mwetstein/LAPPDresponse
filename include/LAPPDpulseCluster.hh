#ifndef LAPPDPULSECLUSTER_HH
#define LAPPDPULSECLUSTER_HH

#include "LAPPDpulse.hh"
#include "TObject.h"
#include <map>

class LAPPDpulseCluster : public TObject {

 public: 

  LAPPDpulseCluster();
  ~LAPPDpulseCluster();

  void Reset();

  void AddPulse(LAPPDpulse* pulse);
  int GetNPulsesStrip(int stripnum);
  int GetPulseNum(int stripnum, int pulsenum);
  LAPPDpulse* GetPulse(Int_t n);
  Int_t GetNPulses();

 private: 

  std::vector<LAPPDpulse*> fLAPPDpulseList;
  std::vector<double> fLAPPDstripPulseCount;
  std::vector<std::vector<int> > fLAPPDstripPulseCoordinate;
  //  std::map<int,std::vector<double> > fLAPPDstripPulseCoordinate;
  int _nchannels; //number of uniques channels

  ClassDef(LAPPDpulseCluster,0)

};

#endif
