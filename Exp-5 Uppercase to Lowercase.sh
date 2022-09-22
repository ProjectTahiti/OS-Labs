echo -n "Enter the filename:"
read filename
if [ ! -f $filename ]; then
   echo "filename $filename does not exists"
   exit 1
else
   tr '[A-Z]' '[a-z]' < $filename
fi
