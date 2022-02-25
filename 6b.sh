<<com
  Shell script to find the files which are having more than 10 characters
com

for i in `ls`
do
fl=`expr length $i`
if [ $fl -ge 10 ] 
then
echo "The file $i has $fl characters"
fi
done
