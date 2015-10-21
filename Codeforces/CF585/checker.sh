while true; do
	./gen>tmp.in
	./E2<tmp.in>std.out
	./E<tmp.in>my.out
	if diff my.out std.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done

