while true; do
	./gen>tmp.in
	./my<tmp.in>my.out
	./std<my.out>std.out
	if diff tmp.in std.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done

