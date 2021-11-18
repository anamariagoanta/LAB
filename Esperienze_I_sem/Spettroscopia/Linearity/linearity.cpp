#include "TH1.h"
#include "TF1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <TGraphPainter.h>
#include <TGraph.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

  //  Function that returns the area with the Covell method
double covell(vector<double> c, double sx, double dx)
{
  return ((c[sx]+c[dx])/2)*(dx-sx);
}

  //  Function that returns the left point of the second fit
double raw_sx(double par[3], int m)
{
  return par[1]-m*par[2];
}

  //  Function that returns the right point of the second fit
double raw_dx(double par[3], int m)
{
  return par[1]+m*par[2];
}

int Cs(int a = 0)
{
  double Counts, n= 2048;
  double raw_area_gauss, raw_area_covell, raw_area_final, area_gauss, area_covell, area_final;
  vector<double> conteggi;
  double par[3], mean, mean_error, sigma, sigma_error;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Cs-137", n, 0, n); 
  h -> GetXaxis() -> SetTitle("Bin");
  h -> GetYaxis() -> SetTitle("Counts");
  h -> SetLineColor(kAzure+2);
  h -> SetLineWidth(1);


    //  Creating the raw fitting function
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
  par[0] = gauss_cs -> GetParameter(0);
  par[1] = gauss_cs -> GetParameter(1);
  par[2] = gauss_cs -> GetParameter(2);
  //printf("The 3 parameters are: %g\n",par[1]);
  raw_area_gauss = gauss_cs -> Integral(710, 900);
  printf("Raw area under the gauss fit: %f\n",raw_area_gauss);
  raw_area_covell = covell(conteggi, 710, 900);
  printf("Raw area with the Covell method under gauss fit: %f\n",raw_area_covell);
  raw_area_final = raw_area_gauss - raw_area_covell;
  printf("The total raw area of the peak is: %f\n",raw_area_final);

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  DOING THE BEST FIT  ////////////////////////////////////

    //  Creating the fitting function
  TF1 *gauss = new TF1("gauss", "gaus", raw_sx(par, 3), raw_dx(par, 3));
  gauss -> SetLineColor(kRed-4);

      //  Re-Fitting the histogram
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss", "R");
  if (a == 1)
  {
    mean = gauss -> GetParameter(1);
    return (int)round(mean);
  }
  if (a == 2)
  {
    sigma = gauss -> GetParameter(2);
    return (int)round(sigma);
  }
  //cs_error = gauss -> GetParError(1);
  area_gauss = gauss -> Integral(raw_sx(par, 3), raw_dx(par, 3));
  printf("Area under the gauss fit: %f\n",area_gauss);
  area_covell = covell(conteggi, raw_sx(par, 3), raw_dx(par, 3));
  printf("Area with the Covell method under gauss fit: %f\n",area_covell);
  area_final = area_gauss - area_covell;
  printf("The total area of the peak is: %f\n",area_final);

  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
  return 0;

}

int Am(int a = 0)
{
  double Counts, n= 2048;
  double raw_area_gauss, raw_area_covell, raw_area_final, area_gauss, area_covell, area_final;
  vector<double> conteggi;
  double par[3], mean, mean_error, sigma, sigma_error;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Am-241", n, 0, n);
  h -> GetXaxis() -> SetTitle("Bin");
  h -> GetYaxis() -> SetTitle("Counts");

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
  par[0] = gauss_am -> GetParameter(0);
  par[1] = gauss_am -> GetParameter(1);
  par[2] = gauss_am -> GetParameter(2);
  printf("The 3 parameters are: %g\n",par[1]);
  raw_area_gauss = gauss_am -> Integral(70, 100);
  printf("Raw area under the gauss fit: %f\n",raw_area_gauss);
  raw_area_covell = covell(conteggi, 70, 100);
  printf("Raw area with the Covell method under the gauss fit: %f\n",raw_area_covell);
  raw_area_final = raw_area_gauss - raw_area_covell;
  printf("The total raw area of the peak is: %f\n",raw_area_final);

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  DOING THE BEST FIT  ////////////////////////////////////

    //  Creating the fitting function
  TF1 *gauss = new TF1("gauss", "gaus", raw_sx(par, 3), raw_dx(par, 3));
  gauss -> SetLineColor(2);

      //  Re-Fitting the histogram
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss", "R");
  if (a == 1)
  {
    mean = gauss -> GetParameter(1);
    return (int)round(mean);
  }
  if (a == 2)
  {
    sigma = gauss -> GetParameter(2);
    return (int)round(sigma);
  }
  area_gauss = gauss -> Integral(raw_sx(par, 3), raw_dx(par, 3));
  printf("Area under the gauss fit: %f\n",area_gauss);
  area_covell = covell(conteggi, raw_sx(par, 3), raw_dx(par, 3));
  printf("Area with the Covell method under gauss fit: %f\n",area_covell);
  area_final = area_gauss - area_covell;
  printf("The total area of the peak is: %f\n",area_final);

  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
  return 0;

}

int Co(int a = 0)
{
  double Counts, n= 2048;
  double raw_area_gauss_1, raw_area_gauss_2, raw_area_covell_1, raw_area_covell_2, raw_area_final_1, raw_area_final_2, area_gauss_1, area_gauss_2, area_covell_1, area_covell_2, area_final_1, area_final_2;
  vector<double> conteggi;
  vector<int> mean;
  double par_1[3], par_2[3], mean_1, mean_2, mean_error_1, mean_error_2, sigma_1, sigma_2, sigma_error_1, sigma_error_2;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Co-60", n, 0, n); 
  h -> GetXaxis() -> SetTitle("Bin");
  h -> GetYaxis() -> SetTitle("Counts");

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
  par_1[0] = gauss_co_1 -> GetParameter(0);
  par_1[1] = gauss_co_1 -> GetParameter(1);
  par_1[2] = gauss_co_1 -> GetParameter(2);
  printf("The 3 parameters are: %g\n",par_1[1]);
  raw_area_gauss_1 = gauss_co_1 -> Integral(1320, 1470);
  printf("Raw area under the first gauss fit: %f\n",raw_area_gauss_1);
  raw_area_covell_1 = covell(conteggi, 1320, 1470);
  printf("Raw area with the Covell method under the first gauss fit: %f\n",raw_area_covell_1);
  raw_area_final_1 = raw_area_gauss_1 - raw_area_covell_1;
  printf("The total raw area of the first peak is: %f\n",raw_area_final_1);

      //  Fitting the second peak
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_co_2", "R+");
  par_2[0] = gauss_co_2 -> GetParameter(0);
  par_2[1] = gauss_co_2 -> GetParameter(1);
  par_2[2] = gauss_co_2 -> GetParameter(2);
  printf("The 3 parameters are: %g\n",par_2[1]);
  raw_area_gauss_2 = gauss_co_2 -> Integral(1480, 1665);
  printf("Raw area under the first gauss fit: %f\n",raw_area_gauss_2);
  raw_area_covell_2 = covell(conteggi, 1480, 1665);
  printf("Raw area with the Covell method under the first gauss fit: %f\n",raw_area_covell_2);
  raw_area_final_2 = raw_area_gauss_2 - raw_area_covell_2;
  printf("The total raw area of the first peak is: %f\n",raw_area_final_2);

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  DOING THE BEST FIT  ////////////////////////////////////

    //  Creating the fitting function
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", raw_sx(par_1, 2), raw_dx(par_1, 2));
  gauss_1 -> SetLineColor(2);

  TF1 *gauss_2 = new TF1("gauss_2", "gaus", raw_sx(par_2, 2), raw_dx(par_2, 2));
  gauss_2 -> SetLineColor(2);

      //  Re-Fitting the histogram
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_1", "R");
  mean_1 = gauss_1 -> GetParameter(1);
  sigma_1 = gauss_1 -> GetParameter(2);
  area_gauss_1 = gauss_1 -> Integral(raw_sx(par_1, 2), raw_dx(par_1, 2));
  printf("Area under the first gauss fit: %f\n",area_gauss_1);
  area_covell_1 = covell(conteggi, raw_sx(par_1, 2), raw_dx(par_1, 2));
  printf("Area with the Covell method under first gauss fit: %f\n",area_covell_1);
  area_final_1 = area_gauss_1 - area_covell_1;
  printf("The total area of the first peak is: %f\n",area_final_1);

  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_2", "R+");
  mean_2 = gauss_2 -> GetParameter(1);
  sigma_2 = gauss_2 -> GetParameter(2);
  area_gauss_2 = gauss_2 -> Integral(raw_sx(par_2, 2), raw_dx(par_2, 2));
  printf("Area under the second gauss fit: %f\n",area_gauss_2);
  area_covell_2 = covell(conteggi, raw_sx(par_2, 2), raw_dx(par_2, 2));
  printf("Area with the Covell method under second gauss fit: %f\n",area_covell_2);
  area_final_2 = area_gauss_2 - area_covell_2;
  printf("The total area of the second peak is: %f\n",area_final_2);

  if (a==1)
  {
    return (int)round(mean_1);
  }
  if (a==2)
  {
    return (int)round(mean_2);
  }
  if (a == 3)
  {
    return (int)round(sigma_1);
  }
  if (a == 4)
  {
    return (int)round(sigma_2);
  }
  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
  return 0;
}

int Na(int a = 0)
{
  double Counts, n= 2048;
  double raw_area_gauss_1, raw_area_gauss_2, raw_area_covell_1, raw_area_covell_2, raw_area_final_1, raw_area_final_2, area_gauss_1, area_gauss_2, area_covell_1, area_covell_2, area_final_1, area_final_2;
  vector<double> conteggi;
  double par_1[3], par_2[3], mean_1, mean_2, mean_error_1, mean_error_2, sigma_1, sigma_2, sigma_error_1, sigma_error_2;

    //  Creating the histogram
  TH1I *h = new TH1I("", "Na-22", n, 0, n); 
  h -> GetXaxis() -> SetTitle("Bin");
  h -> GetYaxis() -> SetTitle("Counts");

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
  par_1[0] = gauss_na_1 -> GetParameter(0);
  par_1[1] = gauss_na_1 -> GetParameter(1);
  par_1[2] = gauss_na_1 -> GetParameter(2);
  printf("The 3 parameters are: %g\n",par_1[1]);
  raw_area_gauss_1 = gauss_na_1 -> Integral(560, 685);
  printf("Raw area under the first gauss fit: %f\n",raw_area_gauss_1);
  raw_area_covell_1 = covell(conteggi, 560, 685);
  printf("Raw area with the Covell method under the first gauss fit: %f\n",raw_area_covell_1);
  raw_area_final_1 = raw_area_gauss_1 - raw_area_covell_1;
  printf("The total raw area of the first peak is: %f\n",raw_area_final_1);

      //  Fitting the second peak
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_na_2", "R+");
  par_2[0] = gauss_na_2 -> GetParameter(0);
  par_2[1] = gauss_na_2 -> GetParameter(1);
  par_2[2] = gauss_na_2 -> GetParameter(2);
  printf("The 3 parameters are: %g\n",par_2[1]);
  raw_area_gauss_2 = gauss_na_2 -> Integral(1400, 1595);
  printf("Raw area under the first gauss fit: %f\n",raw_area_gauss_2);
  raw_area_covell_2 = covell(conteggi, 1400, 1595);
  printf("Raw area with the Covell method under the first gauss fit: %f\n",raw_area_covell_2);
  raw_area_final_2 = raw_area_gauss_2 - raw_area_covell_2;
  printf("The total raw area of the first peak is: %f\n",raw_area_final_2);

/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  DOING THE BEST FIT  ////////////////////////////////////

    //  Creating the fitting function
  TF1 *gauss_1 = new TF1("gauss_1", "gaus", raw_sx(par_1, 3), raw_dx(par_1, 3));
  gauss_1 -> SetLineColor(2);

  TF1 *gauss_2 = new TF1("gauss_2", "gaus", raw_sx(par_2, 3), raw_dx(par_2, 3));
  gauss_2 -> SetLineColor(2);

      //  Re-Fitting the histogram
  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_1", "R");
  mean_1 = gauss_1 -> GetParameter(1);
  sigma_1 = gauss_1 -> GetParameter(2);
  area_gauss_1 = gauss_1 -> Integral(raw_sx(par_1, 3), raw_dx(par_1, 3));
  printf("Area under the first gauss fit: %f\n",area_gauss_1);
  area_covell_1 = covell(conteggi, raw_sx(par_1, 3), raw_dx(par_1, 3));
  printf("Area with the Covell method under first gauss fit: %f\n",area_covell_1);
  area_final_1 = area_gauss_1 - area_covell_1;
  printf("The total area of the first peak is: %f\n",area_final_1);

  printf("\\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t \\ \t\n");
  h -> Fit("gauss_2", "R+");
  mean_2 = gauss_2 -> GetParameter(1);
  sigma_2 = gauss_2 -> GetParameter(2);
  area_gauss_2 = gauss_2 -> Integral(raw_sx(par_2, 3), raw_dx(par_2, 3));
  printf("Area under the second gauss fit: %f\n",area_gauss_2);
  area_covell_2 = covell(conteggi, raw_sx(par_2, 3), raw_dx(par_2, 3));
  printf("Area with the Covell method under second gauss fit: %f\n",area_covell_2);
  area_final_2 = area_gauss_2 - area_covell_2;
  printf("The total area of the second peak is: %f\n",area_final_2);

  if (a==1)
  {
      return (int)round(mean_1);
  }
  if (a==2)
  {
    return (int)round(mean_2);
  }
  if (a == 3)
  {
    return (int)round(sigma_1);
  }
  if (a == 4)
  {
    return (int)round(sigma_2);
  }
  c -> SetLogy();// set the y-axis with log scale

     // Drawing the histogram
  h -> Draw();
  return 0;
}

void Calibration()
{
  int n=2048;
  float Position[n], Energy[n], Position_error[n], Energy_error[n];
  int cs_mean, am_mean, co_mean_1, co_mean_2, na_mean_1, na_mean_2, cs_sigma, am_sigma, co_sigma_1, co_sigma_2, na_sigma_1, na_sigma_2;
  cs_mean = Cs(1);
  cs_sigma = Cs(2);
  am_mean = Am(1);
  am_sigma = Am(2);
  co_mean_1 = Co(1);
  co_mean_2 = Co(2);
  co_sigma_1 = Co(3);
  co_sigma_2 = Co(4);
  na_mean_1 = Na(1);
  na_mean_2 = Na(2);
  na_sigma_1 = Na(3);
  na_sigma_2 = Na(4);
  cout << co_mean_1 << '\t' << co_mean_2 <<'\n';
  for (int i = 0; i < n; ++i)
  {
    Position[i] = 0;
    Energy[i] = 0;
    Position_error[i] = 0;
    Energy_error[i] = 0;
    if (i > am_mean-1 && i < am_mean+1)
    {
      Position[i] = am_mean;
      Energy[i] = 60;//keV
      Position_error[i] = am_sigma;
      Energy_error[i] = 0;
    }
    if (i > cs_mean-1 && i < cs_mean+1)
    {
      Position[i] = cs_mean;
      Energy[i] = 662;//keV
      Position_error[i] = cs_sigma;
      Energy_error[i] = 0;
    }
    if (i > co_mean_1-1 && i < co_mean_1+1)
    {
      Position[i] = co_mean_1;
      Energy[i] = 1174;//keV
      Position_error[i] = co_sigma_1;
      Energy_error[i] = 0;
    }
    if (i > co_mean_2-1 && i < co_mean_2+1)
    {
      Position[i] = co_mean_2;
      Energy[i] = 1332;//keV
      Position_error[i] = co_sigma_2;
      Energy_error[i] = 0;
    }
    if (i > na_mean_1-1 && i < na_mean_1+1)
    {
      Position[i] = na_mean_1;
      Energy[i] = 511;//keV
      Position_error[i] = na_sigma_1;
      Energy_error[i] = 0;
    }
    if (i > na_mean_2-1 && i < na_mean_2+1)
    {
      Position[i] = na_mean_2;
      Energy[i] = 1274;//keV
      Position_error[i] = na_sigma_2;
      Energy_error[i] = 0;
    }
  }
  TGraphErrors *calibration = new TGraphErrors(n, Energy, Position, Energy_error, Position_error);
  TCanvas *c = new TCanvas ("Calibration", "");

  TF1 *fit = new TF1("fit", "pol1", Energy[0], Energy[n]);
  fit -> SetLineColor(2);
  fit -> SetLineWidth(1);

  calibration -> SetTitle("Calibration of the MCA channels");
  for (int i = n; i >= 0 ; --i)
  {
    double x, y;
    calibration -> GetPoint(i, x, y);
    if (x == 0 && y == 0)
    {
      calibration -> RemovePoint(i); 
    }
  }
  calibration -> SetMarkerColor(kAzure+2);
  calibration -> SetMarkerSize(0.8);
  calibration -> SetMarkerStyle(21);
  calibration -> SetMarkerColorAlpha(kAzure+2, 0);
  calibration -> Fit("fit", "R");
  calibration -> Draw("AP");
}

void DoAll()
{
  Cs();
  Am();
  Co(0);
  Na(0);
  Calibration();
}
