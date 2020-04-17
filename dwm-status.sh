#!/usr/local/bin/bash

mpc (){
	SONG=`ncmpcpp --current-song -q`
	echo "${SONG}"
}

memory (){
	free | awk '(NR == 18) {print $6}'
}

drive (){
	df -h | grep '/$' | awk '{print $5}'
}

cpu_temp (){
	sysctl dev.cpu.0.temperature | sed -e 's|.*: \([0-9.]*\)C|\1|'
}

volume (){
	mixer -s vol | grep -Eo '[0-9]+$'
}

print_date (){
	date "+%H:%M "
}

weather() {
     LOCATION=Parramatta

     printf "%s" "$SEP1"
     if [ "$IDENTIFIER" = "unicode" ]; then
         printf "%s" "$(curl -s wttr.in/$LOCATION?format=1)"
     else
         printf "%s" "$(curl -s wttr.in/$LOCATION?format=1 | grep -o "[0-9].*")"
     fi
     printf "%s\n" "$SEP2"
 }

while true
do
	xsetroot -name "  $(mpc) |  [$(memory) |  $(drive) |  $(cpu_temp) |  $(volume)% |  $(weather) |  $(print_date)"
	sleep 1
done
