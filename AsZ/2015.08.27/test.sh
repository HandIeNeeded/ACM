while true; do
    ./gen > tmp.in
    x = ./C < tmp.in
    if ./C < tmp.in; then
        echo $x
        echo "RE"
        exit 0
    else
        echo "AC"
    fi  
done
