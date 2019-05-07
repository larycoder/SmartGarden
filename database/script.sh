#!/bin/bash
user="root"
password=""
db="SmartGarden"
sql=$(cat mysql_script.sql) 
mysql -u "$user" -p"$password" <<EOF
 use $db;
 $sql;
EOF
