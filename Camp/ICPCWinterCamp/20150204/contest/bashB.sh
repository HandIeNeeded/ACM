while true; do
    ./makeD
    ./myD  >out1.txt
    ./D  > out2.txt
    if diff out1.txt out2.txt; 
	then echo "AC"
	else echo "WA" 
	exit 0
fi
done
