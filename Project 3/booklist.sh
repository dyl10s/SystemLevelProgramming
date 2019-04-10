trap 'echo You cant leave like that dog' 2
trap 'echo You cant leave like that dog' 20

while [ true ]
do
    if [ ! $# -eq 1 ]
    then
        echo This program takes 1 command line argument
        echo is should be a list of book information
    fi

    if [ ! -r $1 ]
    then
        echo This program could not read the file $1
    fi

    echo "1 Search the booklist for entries by author 
2 Add a new entry to the booklist
3 Delete an entry from the booklist (using title as the key)
4 Display all entries and the number of entries in the booklist
5 Exit"

    read response

    case $response in
        1) #Search
            echo "What is your search?"
            read search
            search=$(echo $search | tr 'A-Z' 'a-z')
            OIFS=$IFS
            IFS=':'
            output=""
            while read line line2 line3 || [ -n "$line" ];
            do 
                lowerAuthor=$(echo $line | tr 'A-Z' 'a-z')
                if [[ "$lowerAuthor" == *"$search"* ]]
                then
                    output="$output $line $line2 $line3"
                    output+=$'\n'
                fi
            done < $1
            echo $output
            OIFS=IFS
        ;;
        2) #Add
            echo What is the book Author?
            read author
            echo What is the book Title?
            read title
            echo What is the book Year?
            read year

            OIFS=$IFS
            IFS=':'
            found=0
            while read line line2 line3 || [ -n "$line" ];
            do 
                if [ "$author" = "$line" ] && [ "$title" = "$line2" ] && [ "$year" = "$line3" ]
                then
                    found=1
                fi
            done <$1

            if [[ found -eq 0 ]]
            then
                echo -e $author':'$title':'$year >> $1
                echo "Add Complete"
            else
                echo "This entry is already in the file"
            fi
            OIFS=IFS
        ;;
        3) #Delete by title
            echo What is the title of the book you want to delete:
            read search
            OIFS=$IFS
            IFS=':'
            found=0
            while read line line2 line3 || [ -n "$line" ];
            do 
                if [[ ! $line2 == $search ]]
                then
                    echo $line':'$line2':'$line3
                else
                    found=1
                fi
            done <$1 >o
            if [[ found -eq 0 ]]
            then
                echo "Book not found!"
            fi
            mv o $1
            OIFS=IFS
        ;;
        4) #Display
            OIFS=$IFS
            IFS=':'
            count=0
            output=""
            while read line line2 line3 || [ -n "$line" ];
            do 
                count=$((count + 1))
                output="$output $line $line2 $line3"
                output+=$'\n'
            done < $1
            output="$output The toal number of books is $count"
            echo $output
            OIFS=IFS 
        ;;
        5) #Exit
            exit 0
        ;;
    esac
done
