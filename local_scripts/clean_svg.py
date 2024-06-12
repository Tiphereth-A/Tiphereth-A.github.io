#!/usr/bin/python3
# -*- coding: utf-8 -*-

from xml.dom import minidom
import sys

if len(sys.argv) != 2:
    print("Usage: python clean_svg.py [file]")
    sys.exit(1)

dom = minidom.parse(sys.argv[1])
with open(sys.argv[1], 'wb') as f:
    f.write(dom.toprettyxml(indent='', newl='', encoding='UTF-8').replace(b'\n', b''))
dom.unlink()
