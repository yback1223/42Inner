#!/bin/bash

micro() {
	printf "\033[32;1m""micro_paint Test""\033[m"
	read $a

	for n in {0..8}
	do
		./micro_paint1 micro_paint/examples/$n > 1
		./micro_paint2 micro_paint/examples/$n > 2
		./micro_paint3 micro_paint/examples/$n > 3
		value1=$(diff -c 1 3)
		value2=$(diff -c 2 3)
		if [[ $value1 == "" ]] && [[ $value2 == "" ]]
		then
			echo -e test $n"\033[34;1m" pass"\033[m"
		else
			echo -e test $n"\033[31;1m" failed"\033[m"
		fi
	done
	echo -e "\033[32;1m"micro_paint Test Finish"\033[m"
}

mini() {
	printf "\033[32;1m""mini_paint Test""\033[m"
	read $a

	for n in {1..2}
	do
		./mini_paint1 mini_paint/examples/$n > 1
		./mini_paint2 mini_paint/examples/$n > 2
		./mini_paint3 mini_paint/examples/$n > 3
		value1=$(diff -c 1 3)
		value2=$(diff -c 2 3)
		if [[ $value1 == "" ]] && [[ $value2 == "" ]]
		then
			echo -e test $n"\033[34;1m" pass"\033[m"
		else
			echo -e test $n"\033[31;1m" failed"\033[m"
		fi
	done
	echo -e "\033[32;1m"mini_paint Test Finish"\033[m"
}
make
if [ $? -eq 0 ]; then
	while [ -n "$1" ]
	do
		clear
		case "$1" in
		-c)
			micro;;
		-n)
			mini;;
		-a)
			micro
			echo "==================================="
			mini;;
		esac
		shift
	done
else
	echo -e "\033[31;1m""[Compile Error!!!!!!]""\033[m"
fi
make fclean 
rm -rf 1 2 3
