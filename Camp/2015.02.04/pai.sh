while true; do
	./gen>tmp.in
	./J2<tmp.in>std.out
	./J<tmp.in>J.out
	if diff std.out J.out; then 
		echo "AC"
	else 
		echo "WA"
		exit 0
	fi
done
