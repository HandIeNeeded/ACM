while true; do
    ./makeI
    ./checkI >std.out
    ./I >my.out
    if diff my.out std.out; then
        echo AC
    else
        echo WA
        exit
    fi
done
