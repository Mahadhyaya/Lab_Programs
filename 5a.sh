<<com
  Shell script to display creation time of the file if exists
com

filename=$1
if [ -e $filename ]
then
set -- `ls -ld $filename`
echo "The Creation time of $filename is $6 $7 $8"
else
echo "File doesnt exits"
fi
