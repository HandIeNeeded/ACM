while true; do
    ./makeC
    ./C
    ./checkc
    if diff cmy.out std.out; then
        echo AC
    else
        echo WA
        exit
    fi
done
