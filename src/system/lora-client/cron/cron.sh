#!/bin/bash
for i in 0 1 2 3 4 5 6 7 8 9 10 11
do
  python /Users/huyhoang8398/SmartGarden/system/labtest/lora_client_analog$i.py
  sleep 20s
done

python /Users/huyhoang8398/SmartGarden/system/labtest/lora_client_capa.py