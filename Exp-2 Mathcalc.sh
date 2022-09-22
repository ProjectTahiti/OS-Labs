echo "Menu Based Calculator"
echo "Enter the Operands"
read a
read b
echo "Enter the Operator"
read o
case $o in
"+" ) echo "$a + $b" = `expr $a + $b`;;
"-" ) echo "$a + $b" =  `expr $a - $b`;;
"*" ) echo "$a + $b" =   `expr $a * $b`;;
"/" ) echo "$a + $b" =  `expr $a / $b`;;
* ) echo "Inavlid Operation"
esac
