while true; do
    ./makeI
    ./checkC
    ./I
    if diff i.out istd.out; then
        echo AC
    else
        echo WA
        exit
    fi
done
