if [ $1 -eq 0 ]
then
	sed -i '/autoindex/c autoindex off;' /etc/nginx/sites-available/default
elif [ $1 -eq 1 ]
then
	sed -i '/autoindex/c autoindex on;' /etc/nginx/sites-available/default
else
	echo "Incorrect use of script, use 1 for ON and 0 for OFF"
fi
service nginx restart