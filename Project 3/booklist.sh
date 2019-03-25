echo Welcome to booklist
echo -------------------
echo "(1) Search the booklist for entries by author"
echo "(2) Add a new entry to the booklist"
echo "(3) Delete an entry from the booklist (using title as the key)"
echo "(4) Display all entries and the number of entries in the booklist"
echo "(5) Exit"

read response

case $response in
    1) #Search
        echo What is your search:
        read search
        search=$(echo $search | tr 'A-Z' 'a-z')
        OIFS=$IFS
        IFS=':'
        while read line line2 line3 || [ -n "$line" ];
        do 
            if [[ $search == *"$line"* ]]
            then
                echo -e $line '\t\t' $line2 '\t\t' $line3
            fi
        done < $1
        OIFS=IFS
    ;;
    2) #Add

    ;;
    3) #Delete

    ;;
    4) #Display
        OIFS=$IFS
        IFS=':'
        count=0
        while read line line2 line3 || [ -n "$line" ];
        do 
            count=$((count + 1))
            echo -e $line '\t\t' $line2 '\t\t' $line3
        done < $1
        echo The toal number of books is $count
        OIFS=IFS
    ;;
    5) #Exit
        exit 0
    ;;
esac