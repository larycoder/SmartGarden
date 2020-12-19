# Smart Garden
This directory contain instruction to deploy USTH Server code

- Requirement:

    1. Apache
    2. MySql

- Steps:

    1. Copy whole files in 'Smart_Garden/system/USTHserver' to apache pulbic directory
    2. Config 'Smart_Garden/system/database/script.sh' script then run it to create sql database
    3. Run 'Smart_Garden/system/database/generatedb.php' to insert data to sql database (run it on apache public directory since it requires 'db_connect.php' script)

- We write auto-script for doing most of above step in file: script.sh
