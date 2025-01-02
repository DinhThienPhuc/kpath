# KPath

A command-line tool for getting Brillouin zone paths of crystal lattice structures.

## Overview

KPath is a simple C program that helps users identify and select crystal lattice structures and their corresponding k-paths in the Brillouin zone, which is essential for electronic band structure calculations.

## Features

- Supports 14 Bravais lattice types:
  - CUB (Cubic)
  - FCC (Face-centered Cubic)
  - BCC (Body-centered Cubic)
  - TET (Tetragonal)
  - BCT (Body-centered Tetragonal)
  - ORC (Orthorhombic)
  - ORCF (Face-centered Orthorhombic)
  - ORCI (Body-centered Orthorhombic)
  - ORCC (C-centered Orthorhombic)
  - HEX (Hexagonal)
  - RHL (Rhombohedral)
  - MCL (Monoclinic)
  - MCLC (C-centered Monoclinic)
  - TRI (Triclinic)

## Project Structure

```
kpath/
├── lattices/ # Directory containing lattice-specific files
└── main.c # Main program entry point
```

## Technical Details

- Written in C
- Uses standard libraries:
  - stdio.h
  - string.h
  - unistd.h
- Buffer size: 4096 bytes
- Supports up to 161 Q-point characters

## Building

Compile the program using a C compiler:

```bash
gcc -o kpath main.c
```
