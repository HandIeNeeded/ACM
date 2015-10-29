while true; do
	./gen > tmp.in
	if ! ./350 < tmp.in; then
		cat tmp.in
		break
	fi
done
	
