#!/bin/bash

filename="$1"
bordercolor="#424242"
bordersize=16

if [ ! -f "$filename" ]; then
  echo "Error: File not found: $filename"
  exit 1
fi

convert \
  "$filename" \
  -bordercolor "$bordercolor" \
  -border "${bordersize}x${bordersize}" \
  "$filename"
