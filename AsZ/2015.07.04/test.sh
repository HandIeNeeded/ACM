while true; do
	./gen >tmp.in
	if ! ./B < tmp.in; then
		cat tmp.in
		break
	fi
done
