<<com
  Shell script to create files within the directories repeatedly
com

if [ $# -ne 0 ]
then 
p=`echo $1 | tr "/" " "`        #set -- `$1 | tr "/" " "`
for i in $p
do
mkdir $i
cd $i
done
echo "All directories are created"
else
echo "Please enter a parameter"
fi
