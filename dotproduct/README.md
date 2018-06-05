# Steps to compile the prgram

* Using malloc
```
$ make ddr
```
* using hbw_malloc
```
$ make hbm
```

# Steps to submit job to SLURM

* For DDR
```
$ sbatch submit_ddr.sh
```
* For HBM 
```
$ sbatch submit_hbm.sh
```

# Few observations 

* To find out which NUMA node is associated with HBM, run the command numactl with the –hardware or -H option and look for the node with no cores.
```
$ numactl -H
available: 2 nodes (0-1)
node 0 cpus: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30
node 0 size: 96965 MB
node 0 free: 5963 MB
node 1 cpus: 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31
node 1 size: 98304 MB
node 1 free: 87069 MB
node distances:
node   0   1
  0:  10  21
  1:  21  10
```
NOTE: On knl partition, both nodes have DDR memory. 

* For DDR
```
$ numactl --membind=0 ./ddr_dotproduct
$ ps -C ddr_dotproduct u
USER        PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
hpcsriv1   6295  0.0  0.0   4308   552 pts/21   S+   20:14   0:00 ./ddr_dotproduct
$ numastat -p 6295

Per-node process memory usage (in MBs) for PID 6295 (ddr_dotproduct)
                           Node 0          Node 1           Total
                  --------------- --------------- ---------------
Huge                         0.00            0.00            0.00
Heap                         0.01            0.00            0.01
Stack                        0.02            0.00            0.02
Private                      0.49            0.06            0.55
----------------  --------------- --------------- ---------------
Total                        0.52            0.06            0.58
```

* For HBM
```
$ ps -C hbm_dotproduct u
USER        PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
hpcsriv1  15963  0.6  0.0  39964 18252 pts/21   S+   20:40   0:00 ./hbm_dotproduct
[hpcsriv1@login-e-13 Intel_Sample_Code]$ numastat -p 15963

Per-node process memory usage (in MBs) for PID 15963 (hbm_dotproduct)
                           Node 0          Node 1           Total
                  --------------- --------------- ---------------
Huge                         0.00            0.00            0.00
Heap                         0.00            0.02            0.02
Stack                        0.00            0.03            0.03
Private                      0.57           17.24           17.81
----------------  --------------- --------------- ---------------
Total                        0.57           17.29           17.86
```


