while true; do
    ./make >in.txt
    ./G2 <in.txt >out1.txt
    ./G <in.txt > out2.txt
    if diff out1.txt out2.txt; 
	then echo "AC"
	else echo "WA" 
	exit 0
fi
done
