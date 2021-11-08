
#include "gain.h"
#include "TH1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
 
/*double gauss(double x, double mean, double sigma)
{
  return exp(-pow(x - mean, 2)/2*pow(sigma, 2));
};

double gauss_sum(double *x, double *p) // x rappresents the bin while p rappresents the parameters (3 for each gaussian)
{
  return p[0]*gauss(x[0], p[1], p[2]) + p[3]*gauss(x[0], p[4], p[5]) + p[6]*gauss(x[0], p[7], p[8]) + p[9]*gauss(x[0], p[10], p[11]) + p[12]*gauss(x[0], p[13], p[14]) + p[15]*gauss(x[0], p[16], p[17]);//sum of 6 gaussian
}*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 1: 54 V

void Histo_54()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h1 = new TH1I("", "Area segnale a 54 V", 1000, 4.6e-10 , 5.455e-09);  

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", 4.6e-10, 1.7e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 1.7e-09, 2.5e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 2.5e-9, 3.3e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 3.3e-9, 5.455e-09);

    //  The g1 is the sum of the six, each has 3 parameters
  TF1 *g1 = new TF1("g6", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", 4.6e-10 , 5.455e-09); 

    //  Extracting data from F1--Hist_54--00001--00000.txt and uploading into h1
  ifstream F1_Hist_54;
  F1_Hist_54.open("F1--Hist_54--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_54 >> Bins >> Counts;
    h1->SetBinContent(h1->FindBin(Bins), Counts);
  }

      // Creating the canvas
  TCanvas *c1 = new TCanvas ("canvas1", "54 V");

      //Fitting the histo
   h1 -> Fit(gauss_0, "R");
   h1 -> Fit(gauss_1, "R+");
   h1 -> Fit(gauss_2, "R+");
   h1 -> Fit(gauss_3, "R+");

      // Defining the parameter array for the total function
   Double_t par[12];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);

      //  Using the parameters on the sum
   g1 -> SetParameters(par);
  
   h1 -> Fit("g1", "+", " ", 4.6e-10 , 5.455e-09);
   h1 -> Draw();

}









///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 2: 54_5 V

void Histo_54_5()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h2 = new TH1I("", "Area segnale a 54.5 V", 1000, -1.14e-09, 8.85e-09);  

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -1.14e-09, 2e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 2e-09, 3e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 3e-9, 4e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 4e-9, 5e-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 5e-9, 8.85e-09);

    //  The g2 is the sum of the six, each has 3 parameters
  TF1 *g2 = new TF1("g6", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4", -1.14e-09, 8.85e-09); 

    //  Extracting data from F1--Hist_54.5--00001--00000.txt and uploading into h2
  ifstream F1_Hist_54_5;
  F1_Hist_54_5.open("F1--Hist_54.5--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_54_5 >> Bins >> Counts;
    h2->SetBinContent(h2->FindBin(Bins), Counts);
  }

      // Creating the canvas
  TCanvas *c2 = new TCanvas ("canvas2", "54.5 V"); 

      //Fitting the histo
   h2 -> Fit(gauss_0, "R");
   h2 -> Fit(gauss_1, "R+");
   h2 -> Fit(gauss_2, "R+");
   h2 -> Fit(gauss_3, "R+");
   h2 -> Fit(gauss_4, "R+");

      // Defining the parameter array for the total function
   Double_t par[15];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);

      //  Using the parameters on the sum
   g2 -> SetParameters(par);
  
   h2 -> Fit("g2", "+", " ", -1.14e-09, 8.85e-09);
   h2 -> Draw();

}








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 3: 55 V

void Histo_55()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h3 = new TH1I("", "Area segnale a 55 V", 1000, -4.6e-09, 1.538e-08);  

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -4.6e-09, 2e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 2e-09, 3.5e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 3.5e-9, 4.75e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 4.75e-9, 6e-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 6e-9, 7.5e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 7.5e-9, 1.538e-08);

    //  The g3 is the sum of the six, each has 3 parameters
  TF1 *g3 = new TF1("g6", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -4.6e-09, 1.538e-08); 

    //  Extracting data from F1--Hist_55--00001--00000.txt and uploading into h3
  ifstream F1_Hist_55;
  F1_Hist_55.open("F1--Hist_55--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_55 >> Bins >> Counts;
    h3->SetBinContent(h3->FindBin(Bins), Counts);
  }

      // Creating the canvas
  TCanvas *c3 = new TCanvas ("canvas3", "55 V");

      //Fitting the histo
   h3 -> Fit(gauss_0, "R");
   h3 -> Fit(gauss_1, "R+");
   h3 -> Fit(gauss_2, "R+");
   h3 -> Fit(gauss_3, "R+");
   h3 -> Fit(gauss_4, "R+");
   h3 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g3 -> SetParameters(par);
  
   h3 -> Fit("g3", "+", " ", -4.6e-09, 1.538e-08);
   h3 -> Draw();

}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 4: 55.5 V

void Histo_55_5()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h4 = new TH1I("", "Area segnale a 55.5 V", 1000, -4.24e-09, 1.574e-08);  

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -4.24e-09, 2.5e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 2.5e-09, 4e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 4e-9, 5.5e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 5.5e-9, 7e-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 7e-9, 9e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 9e-9, 1.574e-08);

    //  The g4 is the sum of the six, each has 3 parameters
  TF1 *g4 = new TF1("g6", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -4.24e-09, 1.574e-08); 

    //  Extracting data from F1--Hist_55.5--00001--00000.txt and uploading into h4
  ifstream F1_Hist_55_5;
  F1_Hist_55_5.open("F1--Hist_55.5--00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_55_5 >> Bins >> Counts;
    h4->SetBinContent(h4->FindBin(Bins), Counts);
  }

      // Creating the canvas
  TCanvas *c4 = new TCanvas ("canvas4", "55.5 V"); 

      //Fitting the histo
   h4 -> Fit(gauss_0, "R");
   h4 -> Fit(gauss_1, "R+");
   h4 -> Fit(gauss_2, "R+");
   h4 -> Fit(gauss_3, "R+");
   h4 -> Fit(gauss_4, "R+");
   h4 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g4 -> SetParameters(par);
  
   h4 -> Fit("g4", "+", " ", -4.24e-09, 1.574e-08);
   h4 -> Draw();

}






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 5: 56 V

void Histo_56()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h5 = new TH1I("", "Area segnale a 56 V", 1000, -1.59e-08, 3.405e-08);  

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -1.59e-08, 2e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 2e-09, 4e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 4e-9, 6e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 6e-9, 8e-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 8e-9, 10e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 10e-9, 3.405e-08);

    //  The g5 is the sum of the six, each has 3 parameters
  TF1 *g5 = new TF1("g6", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -1.59e-08, 3.405e-08); 

    //  Extracting data from F1--Hist_56-00001--00000.txt and uploading into h5
  ifstream F1_Hist_56;
  F1_Hist_56.open("F1--Hist_56-00001--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_56 >> Bins >> Counts;
    h5->SetBinContent(h5->FindBin(Bins), Counts);
  }

      // Creating the canvas
  TCanvas *c5 = new TCanvas ("canvas5", "56 V"); 

      //Fitting the histo
   h5 -> Fit(gauss_0, "R");
   h5 -> Fit(gauss_1, "R+");
   h5 -> Fit(gauss_2, "R+");
   h5 -> Fit(gauss_3, "R+");
   h5 -> Fit(gauss_4, "R+");
   h5 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g5 -> SetParameters(par);
  
   h5 -> Fit("g5", "+", " ", -1.59e-08, 3.405e-08);
   h5 -> Draw();

}





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 6: 56.5 V

void Histo_56_5()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h6 = new TH1I("", "Area segnale a 56.5 V", 1000, -1.42e-08, 3.575e-08);  

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -1.42e-08, 2.5e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 2.5e-09, 4.5e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 4.5e-9, 7e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 7e-9, 9e-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 9e-9, 11e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 11e-9, 3.575e-08);

    //  The g6 is the sum of the six, each has 3 parameters
  TF1 *g6 = new TF1("g6", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -1.42e-08, 3.575e-08); 

    //  Extracting data from F1--Hist_56.5--00000.txt and uploading into h6
  ifstream F1_Hist_56_5;
  F1_Hist_56_5.open("F1--Hist_56.5--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_56_5 >> Bins >> Counts;
    h6->SetBinContent(h6->FindBin(Bins), Counts);
  }
 
      // Creating the canvas
  TCanvas *c6 = new TCanvas ("canvas6", "56.5 V");    

      //Fitting the histo
   h6 -> Fit(gauss_0, "R");
   h6 -> Fit(gauss_1, "R+");
   h6 -> Fit(gauss_2, "R+");
   h6 -> Fit(gauss_3, "R+");
   h6 -> Fit(gauss_4, "R+");
   h6 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g6 -> SetParameters(par);
  
   h6 -> Fit("g6", "+", " ", -1.42e-08, 3.575e-08);
   h6 -> Draw();

}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 7: 57 V

void Histo_57()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h7 = new TH1I("", "Area segnale a 57 V", 1000, -1.38e-08, 3.615e-08);     

    //  Making the fit functions
  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -1.38e-08, 2.5e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 2.5e-09, 5e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 5e-9, 8e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 8e-9, 10-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 10e-9, 12e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 12e-9, 3.615e-08);

    //  The g7 is the sum of the six, each has 3 parameters
  TF1 *g7 = new TF1("g7", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -1.38e-08, 3.615e-08); 

    //  Extracting data from F1--Hist_57--00000.txt and uploading into h7
  ifstream F1_Hist_57;
  F1_Hist_57.open("F1--Hist_57--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_57 >> Bins >> Counts;
    h7->SetBinContent( h7->FindBin(Bins), Counts);
  }
 
      // Creating the canvas
  TCanvas *c7 = new TCanvas ("canvas7", "57 V");   

      //Fitting the histo
   h7 -> Fit(gauss_0, "R");
   h7 -> Fit(gauss_1, "R+");
   h7 -> Fit(gauss_2, "R+");
   h7 -> Fit(gauss_3, "R+");
   h7 -> Fit(gauss_4, "R+");
   h7 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g7 -> SetParameters(par);
  
   h7 -> Fit("g7", "+", " ", -1.38e-08, 3.615e-08);
   h7 -> Draw();

}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 8: 57.5 V

void Histo_57_5()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h8 = new TH1I("", "Area segnale a 57.5 V", 1000, -1.2e-08, 3.795e-08);   

    //  Making the fit functions

  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -1.2e-08, 3e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 3e-09, 6e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 6e-9, 8e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 8e-9, 11-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 11e-9, 13.5e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 13.5e-9, 3.795e-08);

    //  The g8 is the sum of the six, each has 3 parameters
  TF1 *g8 = new TF1("g8", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -1.2e-08, 3.795e-08); 

    //  Extracting data from F1--Hist_57.5--00000.txt and uploading into h8
  ifstream F1_Hist_57_5;
  F1_Hist_57_5.open("F1--Hist_57.5--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_57_5 >> Bins >> Counts;
    h8->SetBinContent( h8->FindBin(Bins), Counts);
  }
 

      // Creating the canvas
  TCanvas *c8 = new TCanvas ("canvas8", "57.5 V");  

      //Fitting the histo
   h8 -> Fit(gauss_0, "R");
   h8 -> Fit(gauss_1, "R+");
   h8 -> Fit(gauss_2, "R+");
   h8 -> Fit(gauss_3, "R+");
   h8 -> Fit(gauss_4, "R+");
   h8 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g8 -> SetParameters(par);
  
   h8 -> Fit("g8", "+", " ", -1.2e-08, 3.795e-08);
   h8 -> Draw();

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  WORKING ON HISTOGRAM NUMBER 9: 58 V

void Histo_58()
{

  int Counts;
  float Bins;

    //  Creating the histogram
  TH1I *h9 = new TH1I("", "Area segnale a 58 V", 1000, -7.1e-09, 4.285e-08);

    //  Making the fit functions

  TF1 *gauss_0 = new TF1("gauss_0", "gaus", -7.1e-09, 3e-09);
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", 3e-09, 6.5e-9);
  TF1 *gauss_2 = new TF1("gauss_2", "gaus", 6.5e-9, 9e-9);
  TF1 *gauss_3 = new TF1("gauss_3", "gaus", 9e-9, 12e-9);
  TF1 *gauss_4 = new TF1("gauss_4", "gaus", 12e-9, 15e-9);
  TF1 *gauss_5 = new TF1("gauss_5", "gaus", 15e-9, 4.285e-08);

    //  The g9 is the sum of the six, each has 3 parameters
  TF1 *g9 = new TF1("g9", "gauss_0 + gauss_1 + gauss_2 + gauss_3 + gauss_4 + gauss_5", -7.1e-09, 4.285e-08); 

    //  Extracting data from F1--Hist_58--00000.txt and uploading into h9
  ifstream F1_Hist_58;
  F1_Hist_58.open("F1--Hist_58--00000.txt");
  for (int i = 0; i < 1000; ++i)
  {
    F1_Hist_58 >> Bins >> Counts;
    h9->SetBinContent( h9->FindBin(Bins), Counts);
  }


      // Creating the canvas
   TCanvas *c9 = new TCanvas ("canvas9", "58 V"); 

      //Fitting the histo
   h9 -> Fit(gauss_0, "R");
   h9 -> Fit(gauss_1, "R+");
   h9 -> Fit(gauss_2, "R+");
   h9 -> Fit(gauss_3, "R+");
   h9 -> Fit(gauss_4, "R+");
   h9 -> Fit(gauss_5, "R+"); 

      // Defining the parameter array for the total function
   Double_t par[18];

      // Getting the parameters from the fit
   gauss_0->GetParameters(&par[0]);
   gauss_1->GetParameters(&par[3]);
   gauss_2->GetParameters(&par[6]);
   gauss_3->GetParameters(&par[9]);
   gauss_4->GetParameters(&par[12]);
   gauss_5->GetParameters(&par[15]);

      //  Using the parameters on the sum
   g9 -> SetParameters(par);
  
   h9 -> Fit("g9", "+", " ", -7.1e-09, 4.285e-08);
   h9 -> Draw();

}

void DoAll()
{
  Histo_54();
  Histo_54_5();
  Histo_55();
  Histo_55_5();
  Histo_56();
  Histo_56_5();
  Histo_57();
  Histo_57_5();
  Histo_58();
}