#include "TH1.h"
#include "TF1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

float covell(vector<int> c, int sx, int dx)
{
  return ((c[sx]+c[dx])/2)*(dx-sx);
}

void Cs()
{
  int Counts, n= 2048;
  float area_gauss, area_covell, area_final;
  vector<int> conteggi;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Cs-137", n, 0, n);  

    //  Creating the fitting function
  TF1 *gauss_cs = new TF1("gauss_cs", "gaus", 710, 900);
  gauss_cs -> SetLineColor(46);

    //  Extracting data from 1_Cs-137.txt and uploading into h
  ifstream cesio;
  cesio.open("1_Cs-137.txt");
  for (int i = 0; i < n; ++i)
  {
    cesio >> Counts;
    h->SetBinContent(h->FindBin(i), Counts);
    conteggi.push_back(Counts);
  }

      // Creating the canvas
  TCanvas *c = new TCanvas ("Cesio", "Cs-137");

      //  Fitting the histogram
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_cs", "R");
  area_gauss = gauss_cs -> Integral(710, 900);
  printf("Area under the gauss fit: %f\n",area_gauss);
  area_covell = covell(conteggi, 710, 900);
  printf("Area with the Covell method under gauss fit: %f\n",area_covell);
  area_final = area_gauss - area_covell;
  printf("The total area of the peak is: %f\n",area_final);

  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
}

void Am()
{
  double Counts, n= 2048;
  float area_gauss, area_covell, area_final;
  vector<int> conteggi;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Am-241", n, 0, n);  

    //  Creating the fitting function
  TF1 *gauss_am = new TF1("gauss_am", "gaus", 70, 100);
  gauss_am -> SetLineColor(46);

    //  Extracting data from 2_Am-241.Spe and uploading into h
  ifstream americio;
  americio.open("2_Am-241.Spe");
  for (int i = 0; i < n; ++i)
  {
    americio >> Counts;
    h->SetBinContent(h->FindBin(i), Counts);
    conteggi.push_back(Counts);
  }

      // Creating the canvas
  TCanvas *c = new TCanvas ("Americio", "Am-241");

      //  Fitting the histogram
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_am", "R");
  area_gauss = gauss_am -> Integral(70, 100);
  printf("Area under the gauss fit: %f\n",area_gauss);
  area_covell = covell(conteggi, 70, 100);
  printf("Area with the Covell method under the gauss fit: %f\n",area_covell);
  area_final = area_gauss - area_covell;
  printf("The total area of the peak is: %f\n",area_final);

  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
}

void Co()
{
  double Counts, n= 2048;
  float area_gauss_1, area_gauss_2, area_covell_1, area_covell_2, area_final_1, area_final_2;
  vector<int> conteggi;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Co-60", n, 0, n);  

    //  Creating the fitting functions
  TF1 *gauss_co_1 = new TF1("gauss_co_1", "gaus", 1320, 1470);
  gauss_co_1 -> SetLineColor(46);

  TF1 *gauss_co_2 = new TF1("gauss_co_2", "gaus", 1480, 1665);
  gauss_co_2 -> SetLineColor(49);

    //  Extracting data from 3_Co-60.Spe and uploading into h
  ifstream cobalto;
  cobalto.open("3_Co-60.Spe");
  for (int i = 0; i < n; ++i)
  {
    cobalto >> Counts;
    h->SetBinContent(h->FindBin(i), Counts);
    conteggi.push_back(Counts);
  }

      // Creating the canvas
  TCanvas *c = new TCanvas ("Cobalto", "Co-60");

      //  Fitting the first peak
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_co_1", "R");
  area_gauss_1 = gauss_co_1 -> Integral(1320, 1470);
  printf("Area under the first gauss fit: %f\n",area_gauss_1);
  area_covell_1 = covell(conteggi, 1320, 1470);
  printf("Area with the Covell method under the first gauss fit: %f\n",area_covell_1);
  area_final_1 = area_gauss_1 - area_covell_1;
  printf("The total area of the first peak is: %f\n",area_final_1);

      //  Fitting the second peak
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_co_2", "R+");
  area_gauss_2 = gauss_co_2 -> Integral(1480, 1665);
  printf("Area under the first gauss fit: %f\n",area_gauss_2);
  area_covell_2 = covell(conteggi, 1480, 1665);
  printf("Area with the Covell method under the first gauss fit: %f\n",area_covell_2);
  area_final_2 = area_gauss_2 - area_covell_2;
  printf("The total area of the first peak is: %f\n",area_final_2);

  c -> SetLogy();// set the y-axis with log scale

      //  Drawing the histogram 
  h -> Draw();
}

void Na()
{
  double Counts, n= 2048;
  float area_gauss_1, area_gauss_2, area_covell_1, area_covell_2, area_final_1, area_final_2;
  vector<int> conteggi;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Na-22", n, 0, n);  

    //  Creating the fitting functions
  TF1 *gauss_na_1 = new TF1("gauss_na_1", "gaus", 560, 685);
  gauss_na_1 -> SetLineColor(46);

  TF1 *gauss_na_2 = new TF1("gauss_na_2", "gaus", 1400, 1595);
  gauss_na_2 -> SetLineColor(49);

    //  Extracting data from 4_Na-22.Spe and uploading into h
  ifstream sodio;
  sodio.open("4_Na-22.Spe");
  for (int i = 0; i < n; ++i)
  {
    sodio >> Counts;
    h->SetBinContent(h->FindBin(i), Counts);
    conteggi.push_back(Counts);
  }

      // Creating the canvas
  TCanvas *c = new TCanvas ("Sodio", "Na-22");

      //  Fitting the first peak
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_na_1", "R");
  area_gauss_1 = gauss_na_1 -> Integral(560, 685);
  printf("Area under the first gauss fit: %f\n",area_gauss_1);
  area_covell_1 = covell(conteggi, 560, 685);
  printf("Area with the Covell method under the first gauss fit: %f\n",area_covell_1);
  area_final_1 = area_gauss_1 - area_covell_1;
  printf("The total area of the first peak is: %f\n",area_final_1);

      //  Fitting the second peak
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_na_2", "R+");
  area_gauss_2 = gauss_na_2 -> Integral(1400, 1595);
  printf("Area under the first gauss fit: %f\n",area_gauss_2);
  area_covell_2 = covell(conteggi, 1400, 1595);
  printf("Area with the Covell method under the first gauss fit: %f\n",area_covell_2);
  area_final_2 = area_gauss_2 - area_covell_2;
  printf("The total area of the first peak is: %f\n",area_final_2);

  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
}

void DoAll()
{
  Cs();
  Am();
  Co();
  Na();
}