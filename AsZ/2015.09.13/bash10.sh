while true; do
    ./make
    ./check10 >std.out
    ./10 >a10.out
    if diff std.out a10.out; then
        echo AC
    else
        echo WA
        exit
    fi
done
