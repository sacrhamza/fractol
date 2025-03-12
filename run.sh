#!/bin/bash

while true
do
	update=$(make || echo )
	if [[ "$update" != "make: Nothing to be done for 'all'." && -n $update ]]
	then
		process=$(ps -aux | pgrep fractol)
		if [[ -n $process ]]
		then
			kill -9 $process
		fi
		./fractol &
	fi
done

