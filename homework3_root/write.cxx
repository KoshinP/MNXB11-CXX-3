#include "myclass.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include <iostream>

void write() {
    const Int_t nEvents = 1000;  // number of entries to generate

    // Create a new ROOT file
    TFile *file = new TFile("tree_file.root", "RECREATE");

    // Create a TTree inside that file
    TTree *tree = new TTree("tree", "Tree with MyClass objects");

    // Create an object pointer for your class
    MyClass *obj = new MyClass();

    // Tell the tree what kind of branch to create (so it knows your class)
    tree->Branch("mybranch", "MyClass", &obj);

    // Loop over events and fill the tree
    for (Int_t i = 0; i < nEvents; i++) {
        Double_t px = gRandom->Gaus(0, 0.02);
        Double_t py = gRandom->Gaus(0, 0.02);
        Double_t pz = gRandom->Gaus(0, 0.02);

        // Create a new object with these random values
        obj = new MyClass(px, py, pz);

        // Fill the tree
        tree->Fill();

        // Prevent memory leaks by deleting the object
        delete obj;
    }

    // Write the tree to the file and close it
    tree->Write();
    file->Close();

    std::cout << "Successfully wrote " << nEvents
              << " entries to tree_file.root" << std::endl;
}
