#include "myclass.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <iostream>

void read() {
    // Open the ROOT file
    TFile *file = new TFile("tree_file.root", "READ");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open tree_file.root" << std::endl;
        return;
    }

    // Get the tree
    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
        std::cerr << "Error: Tree not found in file" << std::endl;
        return;
    }

    // Create a pointer for our MyClass object
    MyClass *obj = nullptr;

    // Attach branch correctly (name = mybranch)
    tree->SetBranchAddress("mybranch", &obj);

    // Create a histogram for px vs py
    TH2F *h2 = new TH2F("h2", "px vs py;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    // Get total entries
    Long64_t nEntries = tree->GetEntries();
    std::cout << "Entries found: " << nEntries << std::endl;

    // Loop through all entries
    for (Long64_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);  // IMPORTANT: load entry data
        if (!obj) continue; // safety check
        h2->Fill(obj->Px(), obj->Py());
    }

    // Show number of histogram entries
    std::cout << "Histogram filled with: " << h2->GetEntries() << " points" << std::endl;

    // Draw the histogram
    TCanvas *c1 = new TCanvas("c1", "px vs py", 800, 600);
    h2->Draw("COLZ");
    c1->WaitPrimitive();

    // Extra plot: using TTree::Draw
    TCanvas *c2 = new TCanvas("c2", "TTree Draw", 800, 600);
    tree->Draw("mybranch.fPx*mybranch.fPy:mybranch.fPz", "mybranch.fPmag>0.02", "COLZ");
    c2->WaitPrimitive();

    file->Close();
}
