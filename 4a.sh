<<com
  Shell script to convert lowercase character to uppercase of the file and display it
com

for i in $*
do
if [ -f $i ]
then
echo "---------$i contents are---------------"
cat $i | tr "[a-z]" "[A-Z]"
echo "---------------------------------------"
else
echo "$i file doesnt exits"
fi
done
