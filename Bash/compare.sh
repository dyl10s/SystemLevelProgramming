#string compare
s1=dylan;
s2=notdylan;
# there is = and !=
if test $s1 = $s2;
then echo same;
else echo not same;
fi;

#-eq equal
#-gt greater then
#-lt less than
#-nl 
#-gl
#-le less the
n1=12;
n2=15;

if [ $n1 -lt $n2 ];
then echo yes;
else echo no;
fi;

#special test
name=temp;
if test -d $name;
then echo "a directory";
fi;

#-a and
#-o or
#! not
