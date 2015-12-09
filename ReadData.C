#include <string>
#include <vector>
#include <cstdlib>
re4()
{
	//gStyle->SetOptStat(1111);
	gStyle->SetOptStat("iourRmMen");
	gStyle->SetOptFit(1011);
	TFile *f = new TFile("run243597.root","RECREATE");
	//TCanvas *c1 = new TCanvas("c1","RE-4",1); 
	ifstream in;
	in.open("run243597.txt");
	string	chamber[145],currentmin[145],currentmax[145],currentpoint[145],voltmin[145],voltmax[145],voltpoint[145];
	float currentMin,currentMax,currentPoint,voltMin,voltMax,voltPoint;
	float currentDiff[145],voltDiff[145];
	TH1F *h1 = new TH1F("CurrentMinimum","RE4/R2/R3",35,-0.1,6.9);
	TH1F *h2 = new TH1F("CurrentMaximun","RE4/R2/R3",35,-0.1,6.9);
	TH1F *h3 = new TH1F("NumberofCurrentPoint","RE4/R2/R3",26,-1,25);
	TH1F *h4 = new TH1F("VoltageMinimum","RE4/R2/R3",15,9360,9405);
	TH1F *h5 = new TH1F("VoltageMaximum","RE4/R2/R3",15,9375,9420);
	TH1F *h6 = new TH1F("NumberofVoltagePoint","RE4/R2/R3",16,0,12);
	TH1F *h7 = new TH1F("CurrentDiffrence","RE4/R2/R3",20,-1,6);
	TH1F *h8 = new TH1F ("VoltageDiffrence","RE4/R2/R3",15,-1,29);
	h1->GetYaxis()->SetTitle("Number of Entries");
	h1->GetXaxis()->SetTitle("CurrentMin(uA)");
	h2->GetYaxis()->SetTitle("Number of Entries");
	h2->GetXaxis()->SetTitle("CurrentMax(uA)");
	h3->GetYaxis()->SetTitle("Number of Entries");
	h3->GetXaxis()->SetTitle("Number of CurrentPoint");
	h4->GetYaxis()->SetTitle("Number of Entries");
	h4->GetXaxis()->SetTitle("VoltMin(kv)");
	h5->GetYaxis()->SetTitle("Number of Entries");
	h5->GetXaxis()->SetTitle("VoltMax(kv)");
	h6->GetYaxis()->SetTitle("Number of Entries");
	h6->GetXaxis()->SetTitle("Number of VoltagePoint");
	h7->GetYaxis()->SetTitle("Number of Entries");
	h7->GetXaxis()->SetTitle("Current Diffrence(uA)");
	h8->GetYaxis()->SetTitle("Number of Entries");
	h8->GetXaxis()->SetTitle("Volt Diffrence(v)");
	TF1 *f1 = new TF1("f1","gaus",-0.5,4);
	TF1 *f2 = new TF1("f2","gaus",-0.5,7);
	TF1 *f3 = new TF1("f3","gaus",1,25);
	TF1 *f4 = new TF1("f4","gaus",9367,9400);
	TF1 *f5 = new TF1("f5","gaus",9390,9405);
	TF1 *f6 = new TF1("f6","gaus",3,8);
	TF1 *f7 = new TF1("f7","gaus",0,6);
	TF1 *f8 = new TF1("f8","gaus",0,30);
	for(int i=0;i<144;i++)
	{
		in>>chamber[i]>>currentmin[i]>>currentmax[i]>>currentpoint[i]>>voltmin[i]>>voltmax[i]>>voltpoint[i];

		if (currentmax[i]== "No_Data" || currentmin[i] == "No_Data"||currentpoint[i]== "No_Data" ||voltmax[i]== "No_Data"||voltmin[i]== "No_Data"||voltpoint[i]== "No_Data") {cout<<"I am here"<<endl; continue;}
		//cout<<currentmin[i]<<endl;
		currentMin[i] = ::atof(currentmin[i].c_str());currentMax[i] = ::atof(currentmax[i].c_str());
		currentPoint[i] = ::atof(currentpoint[i].c_str());
		voltMin[i] = ::atof(voltmin[i].c_str());
		voltMax[i] = ::atof(voltmax[i].c_str());
		voltPoint[i] = ::atof(voltpoint[i].c_str());

		currentDiff[i] = (currentMax[i]-currentMin[i]);
		voltDiff[i] = (voltMax[i]-voltMin[i]);

		h1->Fill(currentMin[i]);h2->Fill(currentMax[i]);h3->Fill(currentPoint[i]);h4->Fill(voltMin[i]);h5->Fill(voltMax[i]);h6->Fill(voltPoint[i]);h7->Fill(currentDiff[i]);h8->Fill(voltDiff[i]);

	}
	h1->Fit(f1,"s");h2->Fit(f2,"s");h3->Fit(f3,"s");h4->Fit(f4,"s");h5->Fit(f5,"s");h6->Fit(f6,"s");h7->Fit(f7,"s");h8->Fit(f8,"s");

	//c1->cd(1);
	h1->Draw();h2->Draw();h3->Draw();h4->Draw();h5->Draw();h6->Draw();h7->Draw();h8->Draw();
	//h1->SaveAs("CurrentMin.eps");h2->SaveAs("CurrentMax.eps");h3->SaveAs("CurrentPoint.eps");h4->SaveAs("VoltageMin.eps");h5->SaveAs("VoltageMax.eps");h6->SaveAs("VoltagePoint.eps");h7->SaveAs("CurrentDiffrence.eps");h8->SaveAs("VoltageDiffrence.eps");
	in.close();
	f->Write();
	//	file->Write();

}
