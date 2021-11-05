#ifndef Gain_h
#define Gain_h

#include <vector>
using namespace std;

class gain {
public:

	vector<double> Histo_54, Histo_54_5, Histo_55, Histo_55_5, Histo_56, Histo_56_5, Histo_57, Histo_57_5, Histo_58;
    virtual ~gain();
    virtual void Histo();
};

#endif 
