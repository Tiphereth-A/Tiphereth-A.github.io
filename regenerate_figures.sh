#!/bin/sh
for i in imgcode/*/*; do
  j=${i/imgcode/'source/_posts'}
  ./bin/kroki.exe convert $i -o ${j/.*/.svg}
done