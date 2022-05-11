echo -n "Enter the username:"
read userName
temporary=`grep -wi "$username" /etc/passwd`
if [ "$userName" = `whoami` ]
then
	echo "user already logged in"
	exit
fi
if [ $? -eq 0 ]
then 
	
	
	echo "Ram"
	echo -n "mention the time it should wait for login in minutes:"
	read waitingTime
	temp=`echo $waitingTime | grep ^[0-9]$`
	if [ $? -eq 0 ]
	then
		currentHour=`date +%H`
		currentMinute=`date +%M`
		totalMinute=`expr $currentMinute + $waitingTime`
		totalHour=$currentHour
		if [ $totalMinute -gt 60 ]
		then
			totalMinute=`expr 60 - $totalMinute`
			totalHour=`expr $currentHour + 1`
		fi
		while [ $totalMinute -ge $currentMinute -o $totalHour -ge $currentHour ]
		do
			if [ "$userName" = `whoami` ]
			then
				echo "user logged in..."
				exit
			fi
		done
		echo "user not logged in..."
		exit
	else
		echo "Enter the crct time"
	fi

	
	
	
	echo "Soorya"
else
	echo "User doesn't exists"
fi
		
