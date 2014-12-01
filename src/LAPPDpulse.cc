#include "LAPPDpulse.hh"
#include "TObject.h"
#include "TSTring.h"
#include "TFile.h"
#include "TH1.h"
#include "TF1.h"


#include <iostream>
#include <cmath>


ClassImp(LAPPDpulse)

LAPPDpulse::LAPPDpulse(double pulsetime, double lefttime, double righttime, double peakvalue, int stripnum){
_pulsetime = pulsetime;
_lefttime = lefttime;
_righttime = righttime;
_peakvalue = peakvalue;
_stripnum = stripnum;
}

LAPPDpulse::~LAPPDpulse()
{

}



