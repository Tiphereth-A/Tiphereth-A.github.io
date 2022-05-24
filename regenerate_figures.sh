#!/bin/sh

for i in imgcode/dot/*/*; do
  j=${i/'imgcode/dot'/'source/_posts'}
  cat $i | dot -Tsvg > ${j/.dot/.svg}
done

for i in imgcode/circo/*/*; do
  j=${i/'imgcode/circo'/'source/_posts'}
  cat $i | circo -Tsvg > ${j/.dot/.svg}
done