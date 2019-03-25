if [ ! $# -eq "2" ]
then
    echo Please provide 2 command line args
    exit 1
fi

if [ ! -e $1 ]
then
    echo $1 does not exist
    exit 1
fi

count=1

if [ ! -e $2 ]
then
    mv $1 $2
else
    while true;
    do
        if [ ! -e $2.$count ]
        then
            mv $1 $2.$count
            break
        else
            count=$((count + 1))
        fi
    done
fi


    