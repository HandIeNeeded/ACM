while true; do
	./gen>tmp.in
	./std<tmp.in>std.out
	./my<tmp.in>my.out
	if diff my.out std.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done

