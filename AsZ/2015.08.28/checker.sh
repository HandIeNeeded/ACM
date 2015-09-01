while true; do
	./gen>tmp.in
	python I.py<tmp.in>std.out
	java I<tmp.in>my.out
	if diff my.out std.out; then
		echo "AC"
	else
		echo "WA"
		exit 0
	fi
done

