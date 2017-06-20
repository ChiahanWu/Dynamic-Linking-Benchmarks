#!/bin/bash

arrsize=50


create_addvec() {
	rm addvec.c
	touch addvec.c
	echo "void addvec(int *x, int *y, int *z) {" >> addvec.c
	for i in $(seq 0 $((arrsize-1)))
	do
		echo "\tz[$i] = x[$i] + y[$i];" >> addvec.c
	done
	echo "}" >> addvec.c
}


create_multvec() {
	rm multvec.c
	touch multvec.c
	echo "void multvec(int *x, int *y, int *z) {" >> multvec.c
	for i in $(seq 0 $((arrsize-1)))
	do
		echo "\tz[$i] = x[$i] * y[$i];" >> multvec.c
	done
	echo "}" >> multvec.c
}

create_addvec
create_multvec