if [ ! $# -eq 1 ]
then
    echo This program takes 1 command line argument
    echo is should be a list of book information
fi

if [ ! -r $1 ]
then
    echo This program could not read the file $1
fi

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
            lowerAuthor=$(echo $line | tr 'A-Z' 'a-z')
            if [[ "$lowerAuthor" == *"$search"* ]]
            then
                echo -e $line '\t\t' $line2 '\t\t' $line3
            fi
        done < $1
        OIFS=IFS
    ;;
    2) #Add
        echo What is the book Author?
        read author
        echo What is the book Title?
        read title
        echo What is the book Year?
        read year

        found=0
        while read line line2 line3 || [ -n "$line" ];
        do 
            if [ $author -eq $line ] && 
            [ $title -eq $line2 ] && [ $year -eq $line3 ]
            then
                found=1
                echo found
            fi
        done <$1

        if [ found == 0 ]
        then
            echo -e '\n'$author':'$title':'$year >> $1
        else
            echo "This entry is already in the file"
        fi
        
    ;;
    3) #Delete by title
        echo What is the title of the book you want to delete:
        read search
        OIFS=$IFS
        IFS=':'
        while read line line2 line3 || [ -n "$line" ];
        do 
            if [[ ! $line2 == $search ]]
            then
                echo $line':'$line2':'$line3
            fi
        done <$1 >o
        mv o $1
        OIFS=IFS
    ;;
    4) #Display
        OIFS=$IFS
        IFS=':'
        count=0
        while read line line2 line3 || [ -n "$line" ];
        do 
            count=$((count + 1))
            echo -e $line '\t\t\t' $line2 '\t\t\t' $line3
        done < $1
        echo The toal number of books is $count
        OIFS=IFS
    ;;
    5) #Exit
        exit 0
    ;;
esac
