read str
read substr
 
prefix=${str%%$substr*}
index=${#prefix}
 
if [[ index -eq ${#str} ]];
then
    echo "Substring is not present in string."
else
    echo "Index of substring in string : $index"
fi
