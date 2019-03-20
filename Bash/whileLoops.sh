while read line line2 line3
do 
    echo $line2
done < temp.txt #This adds temp to the standard input
#The loop misses the last line
echo $line2

n=1
while [ $n -lt 10 ]
do
    echo -n $n
    let n=n+1
done
echo
echo done