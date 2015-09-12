while true; do
	./gen>tmp.in
	./H<tmp.in>my.out
	./std<tmp.in>std.out
	if diff my.out std.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done

