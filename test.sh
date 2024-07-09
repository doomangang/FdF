#!/bin/bash

 # 파일 목록
 files=(
     "10-2.fdf"
     "10-70.fdf"
     "100-6.fdf"
     "20-60.fdf"
     "42.fdf"
     "50-4.fdf"
     "basictest.fdf"
     "elem-col.fdf"
     "elem-fract.fdf"
     "elem.fdf"
     "elem2.fdf"
     "julia.fdf"
     "mars.fdf"
     "o.fdf"
     "pentenegpos.fdf"
     "plat.fdf"
     "pnp_flat.fdf"
     "pylone.fdf"
     "pyra.fdf"
     "pyramide.fdf"
     "s.txt"
     "t1.fdf"
     "t2.fdf"
 )

 # 파일이 있는 디렉토리
 dir="test_maps"

 # 반복문을 통해 각 파일에 대해 명령어 실행
 for file in "${files[@]}"; do
     echo "Running ./fdf $dir/$file"
     ./fdf "$dir/$file" &
     FDF_PID=$!
     sleep 5
     kill $FDF_PID
     echo "Finished running ./fdf $dir/$file"
 done