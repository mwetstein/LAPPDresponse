#include "LAPPDresponse.hh"
#include "TObject.h"
#include "TSTring.h"
#include "TFile.h"
#include "TH1.h"
#include "TF1.h"


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

  _pulseCluster = new LAPPDpulseCluster();

  mrand = new TRandom3();
}

LAPPDresponse::~LAPPDresponse()
{

}



void LAPPDresponse::AddSinglePhotonTrace(double trans, double para, double time)
{
// Draw a random value for the peak signal peak
double peak = _PHD->GetRandom();

// find nearest strip
int neareststripnum = this->FindStripNumber(trans);

// calculate distance from nearest strip center
double offcenter = fabs(trans - (this->StripCoordinate(neareststripnum))) ; //trans - striptrans;

std::cout<<"THE PEAK "<<peak<<std::endl;

// width of the charge sharing
double thesigma =  _pulsewidth->Interpolate(offcenter);

std::cout<<"nearest stripnum: "<<neareststripnum<<" off center: "<<offcenter<<" thesigma "<<thesigma<<std::endl;

TF1* theChargeSpread = new TF1("theChargeSpread","gaus",-100,100);
theChargeSpread->SetParameter(0,peak);
theChargeSpread->SetParameter(1,0.0);
theChargeSpread->SetParameter(2,thesigma);

// calculate distances and times in the parallel direction
double leftdistance = fabs(-114.554 - para); // annode is 229.108 mm in parallel direction
double rightdistance = fabs(114.554 - para);

if(leftdistance+rightdistance!=229.108) std::cout<<"WHAT!? "<<(leftdistance+rightdistance)<<std::endl;;

double lefttime = leftdistance/(0.53*(0.299792458)); // 53% speed of light (picoseconds per mm) on transmission lines
double righttime = rightdistance/(0.53*(0.299792458)); // 53% speed of light (picoseconds per mm) on transmission lines

std::cout<<leftdistance<<" "<<rightdistance<<" "<<lefttime<<" "<<righttime<<std::endl;

//loop over five-strip cluster about the central strip
for(int i=0; i<5; i++){

   int wstrip = (neareststripnum-2)+i;
   double wtrans = this->StripCoordinate(wstrip);
   double wspeak = theChargeSpread->Eval(trans-wtrans);

   //signal has to be larger than 0.5 mV
   if( (wspeak>0.5) && (wstrip>0) && (wstrip<31) ) {

      std::cout<<"which strip "<<wstrip<<" peakvalue "<<wspeak<<std::endl;

      LAPPDpulse* pulse = new LAPPDpulse(time,lefttime,righttime,wspeak,wstrip);
      _pulseCluster->AddPulse(pulse);	
   }
}	

std::cout<<"Done Adding Pulse"<<std::endl;

}

	
TH1D* LAPPDresponse::GetTrace(int CHnumber, int parity, double starttime, double samplesize, int numsamples)
{
  double lowend = (starttime-(samplesize/2.));
  double upend = lowend + samplesize*((double)numsamples);
  TString tracename;
  tracename += "trace_";
  tracename += CHnumber;
  tracename += "_";
  if(parity==1) tracename+="right";
  else tracename+="left";

  TH1D* trace = new TH1D(tracename,tracename,numsamples,lowend,upend);

  if(_pulseCluster->GetNPulsesStrip(CHnumber)==0) {
	for(int j=0; j<numsamples; j++){

	  double mnoise = 1.0*(mrand->Rndm()-0.5);
	  trace->SetBinContent(j+1, mnoise);
         }
  } else{


      for(int k=0; k<(_pulseCluster->GetNPulsesStrip(CHnumber)); k++){

	 int wPulse = _pulseCluster->GetPulseNum(CHnumber,k);	
	 LAPPDpulse* mpulse = _pulseCluster->GetPulse(wPulse);
         double peakv = mpulse->Getpeakvalue();
         double ptime = mpulse->Getpulsetime();
	 double stime;
	 if(parity<0) stime = mpulse->Getlefttime();
         else stime = mpulse->Getrighttime();

	 double tottime = ptime + stime;

	 std::cout<<"hmmhaw "<<" "<<tottime<<" "<<std::endl;


	  for(int j=0; j<numsamples; j++){

	  	double bcent = trace->GetBinCenter(j+1);

	  	double mbincontent = 0.0;
	  	double mnoise=0.0;
		if(k==0) mnoise = _noiselevel*(mrand->Rndm()-0.5);
	 	mbincontent+=mnoise;

           	if( (bcent > tottime) && (bcent< tottime+3000) ) mbincontent+=(peakv*(_templatepulse->Interpolate(bcent-tottime)));

		double obincontent = trace->GetBinContent(j+1);
		trace->SetBinContent(j+1,obincontent+mbincontent);
		std::cout<<bcent<<std::endl;
          } 
       }
  }


return trace;


}


int LAPPDresponse::FindStripNumber(double trans){

double newtrans = trans + 101.6;

int stripnum=-1;
if(newtrans<5.765) stripnum = 1;
if(newtrans>197.435) stripnum = 30;

double stripdouble;
if(stripnum==-1){

  double stripdouble = 28.0*((newtrans-5.765)/(203.2 - 11.53));
  stripnum = 2 + floor(stripdouble);
}

return stripnum;
}


double LAPPDresponse::StripCoordinate(int stripnumber){

double coor = -55555.;
if(stripnumber==1) coor = (2.31-101.6);
if(stripnumber==30) coor = (101.6-2.31);

if( stripnumber>1 && stripnumber<30 ){

coor= (5.765-101.6+3.455) + (stripnumber-2)*6.91;
}

return coor;

}

