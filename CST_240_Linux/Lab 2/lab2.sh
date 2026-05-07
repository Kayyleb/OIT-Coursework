#!/bin/bash
#Name: Kayleb Cook
#Programming Assignment: Lab 2: Bash Scripts
#Date Created: 04/09/26

start=1
end=0
verbose=0
s_flag=0
e_flag=0
#show help function is defined if the input it "h" then provde a message
show_help()
{
    echo "Syntax to use: ./test.sh -s [start value] -e [end value] [-v] & To see this message again use:  ./test.sh -h "
    exit 0
}

while getopts "hs:e:v" opt; do
    case $opt in
        h) show_help ;;
        s) s_flag=1
	   if [ -z "$OPTARG" ]; then
               start=1
               s_flag=0
           else
               start=$OPTARG
           fi;;
        e) e_flag=1
           if [ -z "$OPTARG" ]; then
	       end=0
               e_flag=0
	   else
	       end=$OPTARG
	   fi;;
        v) verbose=1 ;;
    esac
done

# if either -s or -e is given, then the flag changes to 1, but if the value never changes, then neither were given, and if not call help function
if [ "$s_flag" -eq  0 ]  ||  [ "$e_flag" -eq 0 ]; then
	show_help
fi

#if the value for s is given, and it is a value greater than the end value, then set both to the start value
if [ "$s_flag" -eq 1 ] && [ "$start" -gt "$end" ]; then
    end=$start
fi

#if the value for e is given, and it is a value less than the start value, then set both to the end value
if [ "$e_flag" -eq 1 ] && [ "$end" -lt "$start" ]; then
    start=$end
fi

for ((i=start; i<=end; i++)); do #loop through the inputed start and end
	 ./foo $i #run the foo program
	result=$? #copy the result into a variable
	if [ "$result" -eq 0 ]; then # compare the result to 0
	 echo "$i was successful" # if 0, then successful, so print message
        else
            if [ "$verbose" -eq 1 ]; then  # else if verbose, then provide more insight into
	  echo "$i failed with code $result"
         fi
    fi
done
