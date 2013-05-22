#!/bin/bash

echo "Training"

mkdir negative			# folder with negative images
mkdir positive			# folder with positive images
mkdir samples			# folder with generated samples

read -p "Did you put samples in negative folder ? (y/n)" -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]
then
	rm bg.txt
    find negative -name '*.jpg' > bg.txt
    echo "File descriptor for negative generated"
fi

read -p "Did you put samples in positive folder ? (y/n)" -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]
then
	rm info.dat
    find positive -name '*.jpg' -exec /usr/local/Cellar/imagemagick/6.8.0-10/bin/identify -format '%i 1 0 0 %w %h' \{\} \; > info.dat
    echo "File descriptor for positive generated"
fi

rm out.vec

opencv_createsamples -vec out.vec -info info.dat -bg bg.txt

