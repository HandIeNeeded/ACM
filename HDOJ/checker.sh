while true; do
	./gen>tmp.in
	./5030_SA<tmp.in>std.out
	./5030<tmp.in>my.out
	if diff my.out std.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done

