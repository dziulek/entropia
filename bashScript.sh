#!bin/bash


cppfiles=$(ls *.cpp)
hppfiles=$(ls *.hpp)

for i in $cppfiles
do
	cat ${i} | sed s/enthrop/entrop/g > some
	cat some > ${i}
	cat ${i} | sed s/Enthrop/Entrop/g > some
	cat some > ${i}
done

for i in $hppfiles
do
	cat ${i} | sed s/enthrop/entrop/g > some
	cat some > ${i}
	cat ${i} | sed s/Enthrop/Entrop/g > some
	cat some > ${i}
done

rm some
