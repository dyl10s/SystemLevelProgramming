#! /bin/bash
# show the number of current users
echo
date
echo -n "the number of users is "
who | wc -l
echo

#command expansion (Works in double quotes not single quotes)
echo my current directory is $(pwd)
echo today is `date +%m-%d-%Y`
echo 'the command $(pwd) is' "$(pwd)"
echo 

echo "What is your first and last name?"
#variable expansion
read fname lname
echo Your name is $fname $lname

exit 0 #This can be seen by $?
