#!/bin/sh

for i in imgcode/dot/*/*; do
  j=${i/'imgcode/dot'/'source/_posts'}
  cat $i | dot -Tsvg > ${j/.dot/.svg}
done

for i in imgcode/circo/*/*; do
  j=${i/'imgcode/circo'/'source/_posts'}
  cat $i | circo -Tsvg > ${j/.dot/.svg}
done

for i in imgcode/drawio/*; do
  j=${i/'imgcode/drawio'/'source/_posts'}
  draw.io -x -f svg -o ${i/'imgcode/drawio'/'source/_posts'} $i --embed-svg-images
done

for i in imgcode/latex/*; do
  for i2 in $i/*; do
    j=${i2/'imgcode/latex'/'source/_posts'}
    xelatex -synctex=1 -interaction=nonstopmode -file-line-error -output-directory=$i $i2
    ./bin/pdf2svg/pdf2svg.exe ${i2/'.tex'/'.pdf'} ${j/'.tex'/'.svg'}
    rm -f ${i2/'.tex'/'.aux'}
    rm -f ${i2/'.tex'/'.log'}
    rm -f ${i2/'.tex'/'.pdf'}
    rm -f ${i2/'.tex'/'.synctex.gz'}
    rm -f ${i2/'.tex'/'.synctex.log'}
    rm -f $i/texput.log
  done
done