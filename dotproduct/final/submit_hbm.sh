#!/bin/bash
set -x
DOUBLE="==========================================================================="
COUNTER=1
numactl -m 0 ./dotproduct hbm &
sleep 3
while [ $COUNTER -ne 0 ]
do
  echo "# numastat -p <pid>    " >> dotproduct.log
  numastat -p $! 2>&1 | tee -a dotproduct.log
  cat dotproduct.log | grep -w "Can't read" 
  if [ $? -eq 0 ]; then
    COUNTER=0
    exit
  fi
  echo "# numactl -H          " >> dotproduct.log
  numactl -H 2>&1 | tee -a dotproduct.log 
  echo "# free -m              " >> dotproduct.log
  free -m  2>&1 | tee -a dotproduct.log
  echo "$DOUBLE" >> dotproduct.log
done
sleep 1

