while true; do
    ./makeK
    ./K > king.out
    ./checkK > std.out
    if diff king.out std.out; then
        echo AC
    else
        echo WA
        exit
    fi
done
