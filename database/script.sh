#!/bin/bash
user="root"
password="hoamoclan123"
db="smartgarden"
sql=$(cat mysql_script.sql) 
mysql -u "$user" -p"$password" <<EOF
 use $db;
 $sql;
EOF
