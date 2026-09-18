#!/bin/bash

#SBATCH --job-name=my_program
#SBATCH --partition=Centaurus
#SBATCH --time=00:01:00
#SBATCH --mem=32G

make
./my_program