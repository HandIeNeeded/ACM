while true; do
    ./makeE >E.in
    ./E1 <E.in >E1.out
    ./E2 <E.in >E2.out
    if diff E1.out E2.out; then
        echo AC
    else
        echo WA
        exit
    fi
done
