#include "myclass.h"
#include "TMath.h"

ClassImp(MyClass)

MyClass::MyClass() : fPx(0), fPy(0), fPz(0), fPmag(0) {}

MyClass::MyClass(Double_t px, Double_t py, Double_t pz)
    : fPx(px), fPy(py), fPz(pz)
{
    CalculateMomentumMagnitude();
}

MyClass::~MyClass() {}

void MyClass::CalculateMomentumMagnitude() {
    fPmag = TMath::Sqrt(fPx*fPx + fPy*fPy + fPz*fPz);
}
