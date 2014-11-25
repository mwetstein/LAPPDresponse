{
TH1D* pulsewidth = new TH1D("pulsewidth","pulsewidth",10,0.0,8.0);

TFile* tf = new TFile("template.Apr05v1.root","READ");

//TH1D* tt = (TH1D*) tf->Get("template");
//TH1D* templatepulse = tt->Clone();
TH1D* templatepulse = (TH1D*) tf->Get("thetemplate");

for(int i=0; i<templatepulse->GetNbinsX(); i++){

	double bcx = templatepulse->GetBinCenter(i);
	if( (bcx<49300) || (bcx>52300) ) templatepulse->SetBinContent(i,0);

}

templatepulse->Draw();

TFile* tf2 = new TFile("pulsecharacteristics.root","RECREATE");
pulsewidth->Write("pulsewidth");
templatepulse->Write("templatepulse");





}
