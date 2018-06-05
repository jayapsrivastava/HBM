#!/bin/bash

#SBATCH -p knl
#SBATCH --constraint=cache
#SBATCH --job-name=ddr_dotproduct
#SBATCH -o slurm.%N.%j.out # STDOUT
#SBATCH -e slurm.%N.%j.err # STDERR

export MEMKIND_HBW_NODES=0
#export AUTO_HBW_LOG=2
#export AUTO_HBW_MEM_TYPE=MEMKIND_HBW  # this is the default, so you do not have to set explicitly
#export AUTO_HBW_DEBUG=2
#export AUTO_HBW_SIZE=1K:5K

srun -n 1 numactl --membind=0 ./ddr_dotproduct

