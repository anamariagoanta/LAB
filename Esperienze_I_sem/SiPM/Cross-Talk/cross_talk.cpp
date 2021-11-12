#include "TH1.h"
#include "TStyle.h"
#include "TCanvas.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void graph_0()
{
	double Bins;
	int Counts, n=77;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_54_150_2_1.txt
    ifstream Graph_54;
    Graph_54.open("20211103_54_150_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_54 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c0 = new TCanvas ("canvas0", "54 V");
      graph -> SetTitle("Dark Cross-Talk with 54 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}


void graph_1()
{
	double Bins;
	int Counts, n=112;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_54.5_220_2_1.txt
    ifstream Graph_54_5;
    Graph_54_5.open("20211103_54.5_220_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_54_5 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c1 = new TCanvas ("canvas1", "54.5 V");
      graph -> SetTitle("Dark Cross-Talk with 54.5 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_2()
{
	double Bins;
	int Counts, n=137;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_55_270_2_1.txt
    ifstream Graph_55;
    Graph_55.open("20211103_55_270_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_55 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c2 = new TCanvas ("canvas2", "55 V");
      graph -> SetTitle("Dark Cross-Talk with 55 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_3()
{
	double Bins;
	int Counts, n=187;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_55.5_370_2_1.txt
    ifstream Graph_55_5;
    Graph_55_5.open("20211103_55.5_370_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_55_5 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c3 = new TCanvas ("canvas3", "55.5 V");
      graph -> SetTitle("Dark Cross-Talk with 55.5 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_4()
{
	double Bins;
	int Counts, n=177;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_56_350_2_1.txt
    ifstream Graph_56;
    Graph_56.open("20211103_56_350_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_56 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c4 = new TCanvas ("canvas4", "56 V");
      graph -> SetTitle("Dark Cross-Talk with 56 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_5()
{
	double Bins;
	int Counts, n=227;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_56.5_450_2_1.txt
    ifstream Graph_56_5;
    Graph_56_5.open("20211103_56.5_450_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_56_5 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c5 = new TCanvas ("canvas5", "56.5 V");
      graph -> SetTitle("Dark Cross-Talk with 56.5 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_6()
{
	double Bins;
	int Counts, n=252;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_57_500_2_1.txt
    ifstream Graph_57;
    Graph_57.open("20211103_57_500_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_57 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c6 = new TCanvas ("canvas6", "57 V");
      graph -> SetTitle("Dark Cross-Talk with 57 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_7()
{
	double Bins;
	int Counts, n=302;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_57.5_600_2_1.txt
    ifstream Graph_57_5;
    Graph_57_5.open("20211103_57.5_600_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_57_5 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c7 = new TCanvas ("canvas7", "57.5 V");
      graph -> SetTitle("Dark Cross-Talk with 57.5 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_8()
{
	double Bins;
	int Counts, n=328;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_58_650_2_1.txt
    ifstream Graph_58;
    Graph_58.open("20211103_58_650_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_58 >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c8 = new TCanvas ("canvas8", "58 V");
      graph -> SetTitle("Dark Cross-Talk with 58 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_9()
{
	double Bins;
	int Counts, n=177;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_T_56_350_2_1.txt
    ifstream Graph_56_T;
    Graph_56_T.open("20211103_T_56_350_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_56_T >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c9 = new TCanvas ("canvas9", "56 V with teflon");
      graph -> SetTitle("Dark with teflon Cross-Talk with 56 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_10()
{
	double Bins;
	int Counts, n=277;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_T_57_550_2_1.txt
    ifstream Graph_57_T;
    Graph_57_T.open("20211103_T_57_550_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_57_T >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c10 = new TCanvas ("canvas10", "57 V with teflon");
      graph -> SetTitle("Dark with teflon Cross-Talk with 57 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void graph_11()
{
	double Bins;
	int Counts, n=327;
	double Threshold[n], Iteration[n];
	    
	  //  Extracting data from 20211103_T_58_650_2_1.txt
    ifstream Graph_58_T;
    Graph_58_T.open("20211103_T_58_650_2_1.txt");
    for (int i = 0; i < n; ++i)
    {
      Graph_58_T >> Bins >> Counts;
      Threshold[i] = i*0.2;	//	Saves i*0.2 into Threshold[i]
      Iteration[i] = Counts;	//	Saves Counts into Iteration[i]
    };
      TGraph *graph = new TGraph(n, Threshold, Iteration);
      TCanvas *c11 = new TCanvas ("canvas11", "58 V with teflon");
      graph -> SetTitle("Dark with teflon Cross-Talk with 58 V of overvoltage");
      graph -> SetLineColor(4);
      graph -> Draw();
}

void Buio()
{
  	graph_0();
  	graph_1();
  	graph_2();
  	graph_3();
  	graph_4();
  	graph_5();
  	graph_6();
  	graph_7();
  	graph_8();
}

void Teflon()
{
	graph_9();
	graph_10();
	graph_11();
}

void DoAll()
{
  	Buio();
  	Teflon();
}