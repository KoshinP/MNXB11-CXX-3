#ifndef __MYCLASS_H__
#define __MYCLASS_H__

#include <TObject.h>
#include <cmath>

class MyClass : public TObject {
public:
    MyClass();  // Default constructor
    MyClass(Double_t px, Double_t py, Double_t pz); // Constructor with arguments
    virtual ~MyClass(); // Destructor

    Double_t Px() const { return fPx; }
    Double_t Py() const { return fPy; }
    Double_t Pz() const { return fPz; }
    Double_t Pmag() const { return fPmag; }

    void CalculateMomentumMagnitude();

private:
    Double_t fPx;
    Double_t fPy;
    Double_t fPz;
    Double_t fPmag;

    ClassDef(MyClass, 1);
};

#endif // __MYCLASS_H__
