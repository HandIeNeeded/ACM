while true; do
    ./makeK
    ./checkK1 <K.in > K.out
    ./K > K1.out
    if diff K.out K1.out; then
        echo AC
    else echo WA
        exit
    fi
done
