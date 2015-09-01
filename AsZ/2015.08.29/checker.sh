while true; do
	./gen>tmp.in
	./I<tmp.in>std.out
	if ./test < std.out; then
        exit 0
    fi
done

