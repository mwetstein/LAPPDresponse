#include "LAPPDresponse.hh"
#include "TObject.h"
#include "TSTring.h"
#include "TFile.h"
#include "TH1.h"

#include <iostream>
#include <cmath>


ClassImp(LAPPDresponse)

LAPPDresponse::LAPPDresponse()
{
  TFile* tf = new TFile("pulsecharacteristics.root","READ");
 
  _templatepulse = (TH1D*) tf->Get("templatepulse");
  _PHD = (TH1D*) tf->Get("PHD");
  _pulsewidth = (TH1D*) tf->Get("pulsewidth");
  
  _noiselevel = 1.0; //in mV
  _nsamples = 35;
  _samplewidth = 100; //in picoseconds


}

LAPPDresponse::~LAPPDresponse()
{

}


void LAPPDresponse::SetFreezeTime(double freezetime)
{
 _freezetime = freezetime; //again, in picoseconds

 StripResponse_neg = new TH1D*[30];
 StripResponse_pos = new TH1D*[30];

 for(int i=0; i<30; i++){

   double starttime = _freezetime - (_samplewidth/2.0);
   double endtime = starttime + ((double)_nsamples)*_samplewidth;

   TString nname;
   nname+="negside_strip_";
   nname+=i;

   TString pname;
   pname+="posside_strip_";
   pname+=i;


   StripResponse_neg[i] = new TH1D(nname, nname, _nsamples, starttime, endtime); 
   StripResponse_pos[i] = new TH1D(pname, pname, _nsamples, starttime, endtime); 
 }


}

void LAPPDresponse::AddPhoton(double trans, double para, double time)
{
    for(int i=1; i<31; i++){
	
	TH1D* originaltrace_neg  = this->GetTrace(i,-1);
	TH1D* newtrace_neg = this->CalcSinglePhotonTrace(i,trans,para,time,-1);
	newtrace_neg->Add(originaltrace_neg);

	TH1D* originaltrace_pos  = this->GetTrace(i,1);
	TH1D* newtrace_pos = this->CalcSinglePhotonTrace(i,trans,para,time,1);
	newtrace_pos->Add(originaltrace_pos);


	StripResponse_neg[i-1] = newtrace_neg;
	StripResponse_pos[i-1] = newtrace_pos;
    
    }



}


TH1D* LAPPDresponse::CalcSinglePhotonTrace(int CHnumber, double trans, double para, double time, int parity)
{

TH1D* test = new TH1D("test","test",100,1,2);
return test;

}
	
TH1D* LAPPDresponse::GetTrace(int CHnumber, int parity)
{

TH1D* test = new TH1D("test","test",100,1,2);
return test;


}


