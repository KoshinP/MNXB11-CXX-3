# Homework 3 – C++ (ROOT)
**Course:** MNXB11  
**Student:** Your Name  
**Date:** October 2025  

---

## Description
This homework implements a custom ROOT class and uses it to write and read random momentum data (`px`, `py`, `pz`) stored in a `TTree`.

### Files
- `myclass.h` / `myclass.cxx` — Definition of the `MyClass` ROOT class.
- `write.cxx` — Generates random data and writes it into `tree_file.root`.
- `read.cxx` — Reads the data and plots `px` vs `py` and a TTree::Draw visualization.

---

## How to run
Inside ROOT:

```cpp
root [0] .L myclass.cxx+
root [1] .x write.cxx
root [2] .x read.cxx
