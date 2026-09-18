#!/bin/bash

#SBATCH --job-name=array_maximum
#SBATCH --partition=Centaurus
#SBATCH --time=00:01:00
#SBATCH --mem=32G

make
./array_maximum