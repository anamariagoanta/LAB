#include "gain.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void gain::Histo()
{
	int Counts;
	float Bins;

 //Making the histograms

  //histo for 54 V
  TH1I *h1 = new TH1I("", "Area segnale a 54 V", 1000, 4.6e-10 , 5.455e-09);  

  //histo for 54.5 V                 
  TH1I *h2 = new TH1I("", "Area segnale a 54.5 V", 1000, -1.14e-09, 8.85e-09);  

  //histo for 55 V               
  TH1I *h3 = new TH1I("", "Area segnale a 55 V", 1000, -4.6e-09, 1.538e-08);  

  //histo for 55.5 V                 
  TH1I *h4 = new TH1I("", "Area segnale a 55.5 V", 1000, -4.24e-09, 1.574e-08);  

  //histo for 56 V             
  TH1I *h5 = new TH1I("", "Area segnale a 56 V", 1000, -1.59e-08, 3.405e-08);   

  //histo for 56.5 V           
  TH1I *h6 = new TH1I("", "Area segnale a 56.5 V", 1000, -1.42e-08, 3.575e-08);  

  //histo for 57 V              
  TH1I *h7 = new TH1I("", "Area segnale a 57 V", 1000, -1.38e-08, 3.615e-08);  

  //histo for 57.5 V                
  TH1I *h8 = new TH1I("", "Area segnale a 57.5 V", 1000, -1.2e-08, 3.795e-08);   

  //histo for 58 V
  TH1I *h9 = new TH1I("", "Area segnale a 58 V", 1000, -7.1e-09, 4.285e-08);                   

 //Loading the histograms from filex .txt 


  //extracting data from F1--Hist_54--00001--00000.txt
  ifstream F1_Hist_54;
  F1_Hist_54.open("F1--Hist_54--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_54 >> Bins >> Counts;
    h1->SetBinContent(h1->FindBin(Bins), Counts);
  }

  //extracting data from F1--Hist_54.5--00001--00000.txt
  ifstream F1_Hist_54_5;
  F1_Hist_54_5.open("F1--Hist_54.5--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_54_5 >> Bins >> Counts;
    h2->SetBinContent(h2->FindBin(Bins), Counts);
  }

    //extracting data from F1--Hist_55--00001--00000.txt
  ifstream F1_Hist_55;
  F1_Hist_55.open("F1--Hist_55--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_55 >> Bins >> Counts;
    h3->SetBinContent(h3->FindBin(Bins), Counts);
  }

    //extracting data from F1--Hist_55.5--00001--00000.txt
  ifstream F1_Hist_55_5;
  F1_Hist_55_5.open("F1--Hist_55.5--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_55_5 >> Bins >> Counts;
    h4->SetBinContent(h4->FindBin(Bins), Counts);
  }

    //extracting data from F1--Hist_56-00001--00000.txt
  ifstream F1_Hist_56;
  F1_Hist_56.open("F1--Hist_56-00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_56 >> Bins >> Counts;
    h5->SetBinContent(h5->FindBin(Bins), Counts);
  }

    //extracting data from F1--Hist_56.5--00000.txt
  ifstream F1_Hist_56_5;
  F1_Hist_56_5.open("F1--Hist_56.5--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_56_5 >> Bins >> Counts;
    h6->SetBinContent(h6->FindBin(Bins), Counts);
  }

    //extracting data from F1--Hist_57--00000.txt
  ifstream F1_Hist_57;
  F1_Hist_57.open("F1--Hist_57--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_57 >> Bins >> Counts;
    h7->SetBinContent( h7->FindBin(Bins), Counts);
  }

    //extracting data from F1--Hist_57.5--00000.txt
  ifstream F1_Hist_57_5;
  F1_Hist_57_5.open("F1--Hist_57.5--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_57_5 >> Bins >> Counts;
    h8->SetBinContent( h8->FindBin(Bins), Counts);
  }
 
    //extracting data from F1--Hist_58--00000.txt
  ifstream F1_Hist_58;
  F1_Hist_58.open("F1--Hist_58--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_58 >> Bins >> Counts;
    cout << Bins << " " << Counts << '\n';
    h9->SetBinContent( h9->FindBin(Bins), Counts);
  }

//Making the canvases
 
  //canvas for the Histo_54
  TCanvas *c1 = new TCanvas ("canvas1", "54 V"); 
   //h1 -> Fit("gaus");                                     
   h1 -> Draw();

       //canvas for the Histo_54_5
  TCanvas *c2 = new TCanvas ("canvas2", "54.5 V"); 
   //h2 -> Fit("gaus");                                     
   h2 -> Draw();

     //canvas for the Histo_55
  TCanvas *c3 = new TCanvas ("canvas3", "55 V"); 
   //h3 -> Fit("gaus");                                     
   h3 -> Draw();

     //canvas for the Histo_55_5
  TCanvas *c4 = new TCanvas ("canvas4", "55.5 V"); 
   //h4 -> Fit("gaus");                                     
   h4 -> Draw();

       //canvas for the Histo_56
  TCanvas *c5 = new TCanvas ("canvas5", "56 V"); 
   //h5 -> Fit("gaus");                                     
   h5 -> Draw();

       //canvas for the Histo_56_5
  TCanvas *c6 = new TCanvas ("canvas6", "56.5 V"); 
   //h6 -> Fit("gaus");                                     
   h6 -> Draw();

       //canvas for the Histo_57
  TCanvas *c7 = new TCanvas ("canvas7", "57 V"); 
   //h7 -> Fit("gaus");                                     
   h7 -> Draw();

       //canvas for the Histo_57.7
  TCanvas *c8 = new TCanvas ("canvas8", "57.5 V"); 
   //h8 -> Fit("gaus");                                     
   h8 -> Draw();

       //canvas for the Histo_58
  TCanvas *c9 = new TCanvas ("canvas9", "58 V"); 
   //h9 -> Fit("gaus");                                     
   h9 -> Draw();
}
