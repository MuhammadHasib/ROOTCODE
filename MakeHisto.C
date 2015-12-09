void readHist(){
	gStyle->SetOptStat("iourRmMen");
	//TLegend *leg = 	new TLegend(0.11,0.7031193,0.3679695,0.8970642);
  TFile* file = new TFile("run243597.root","READ");

  DrawHistos(file, "CurrentMinimum", 2.1, 0.0, 2.1, 30.0);
  DrawHistos(file, "CurrentMaximun", 2.5, 0.0, 2.5, 22.0);
  DrawHistos(file, "VoltageMinimum", 9384, 0.0,9384, 36.0);
  DrawHistos(file, "VoltageMaximum",9402, 0.0,9402, 60.0);
  DrawHistos(file, "CurrentDiffrence", 1.1, 0.0, 1.1, 60.0);
  DrawHistos(file, "VoltageDiffrence", 27.0, 0.0, 27.0, 40.0);
  DrawHistos(file, "NumberofCurrentPoint", 8.0, 0.0, 8.0, 35.0);
  DrawHistos(file, "NumberofVoltagePoint", 7.5, 0.0, 7.5, 70.0);


}

void DrawHistos(TFile *InputFile, TString histName, Float_t lineX1, Float_t lineY1, Float_t lineX2, Float_t lineY2){

  TH1F *hist = (TH1F*)InputFile->Get(histName);

  TLine *line = new TLine(lineX1, lineY1, lineX2, lineY2);
  line->SetLineWidth(1);            
  line->SetLineColor(kGreen);     
  line->SetLineStyle(1);        

	//TLegend *leg =  new TLegend(0.11,0.7031193,0.3679695,0.8970642);  
hist->Draw(); 
  line->Draw("SAME"); 
//leg->Draw("iourRmMen");
//c1->SaveAs(histName+".root");
  c1->SaveAs(histName+".pdf");
}

